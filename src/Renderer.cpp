#include "Material.h"
#include "Transform.h"
#include <Renderer.h>
#include <glm/packing.hpp>

using namespace std;
using namespace glm;
using namespace sf;

static inline vector<char> readBinFile(const char *path)
{
  vector<char> data;
  fstream fileStream(path, ios::binary | ios::ate | ios::in);
  if (!fileStream.is_open())
  {
    printf("Failed to open file at %s", path);
  }
  data.resize(fileStream.tellg());
  fileStream.seekg(0, ios::beg);
  fileStream.read(data.data(), data.size());
  fileStream.flush();
  fileStream.close();
  return data;
}

Renderer::Renderer() : player(Transform({0, 2.4f, 0}))
{
  glewExperimental = true;
  glewInit();

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  shaderProgramID =
      loadShaderProgram("./shaders/main.vert", "./shaders/main.frag");
  glUseProgram(shaderProgramID);
  modelLocation = glGetUniformLocation(shaderProgramID, "M");
  viewPrespectiveLocation = glGetUniformLocation(shaderProgramID, "VP");
  hasTextureLocation = glGetUniformLocation(shaderProgramID, "hasTexture");
  observerLocation = glGetUniformLocation(shaderProgramID, "observer");
  shadelessLocation = glGetUniformLocation(shaderProgramID, "shadeless");
  Material::setLocValues(shaderProgramID);
  setViewPrespective(mat4(1.0f));
}
void Renderer::render()
{
  transparentMeshes.clear();
  solidMeshes.clear();
  setViewPrespective(player.updateView());
  setObserverPos(player.transform.getPosition());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  setShadeless(true);
  drawSkybox();
  if (Keyboard::isKeyPressed(Keyboard::L))
  {
    shadeless = !shadeless;
  }
  if (Keyboard::isKeyPressed(Keyboard::K))
  {
    lights[0].toggle();
    lights[1].toggle();
    lights[2].toggle();
    lights[3].toggle();
    lights[4].toggle();
    lights[5].toggle();
    lights[6].toggle();
    lights[7].toggle();
  }
  if (Keyboard::isKeyPressed(Keyboard::J))
  {
    lights[0].toggle();
    lights[8].toggle();
    lights[9].toggle();
    lights[10].toggle();
    lights[11].toggle();
    lights[12].toggle();
    lights[13].toggle();
    lights[14].toggle();
  }
  setShadeless(shadeless);
  for (uint i = 0; i < meshes.size(); ++i)
  {
    if (meshes[i].getMaterial().getAlpha() < 0.99f)
    {
      transparentMeshes.push_back(&meshes[i]);
    }
    else
    {
      solidMeshes.push_back(&meshes[i]);
    }
  }
  for (Mesh *mesh : solidMeshes)
  {
    setModelMatrix(mesh->getModelMatrix());
    if (mesh->hasTexture())
    {
      setHasTexture(true);
    }
    else
    {
      setHasTexture(false);
    }
    mesh->draw();
  }
  for (Mesh *mesh : transparentMeshes)
  {
    setModelMatrix(mesh->getModelMatrix());
    if (mesh->hasTexture())
    {
      setHasTexture(true);
    }
    else
    {
      setHasTexture(false);
    }
    mesh->draw();
  }
}

GLuint Renderer::loadShaderProgram(const char *vertexShaderPath,
                                   const char *fragmentShaderPath)
{
  GLuint program;
  vector<char> vertexShaderCode = readBinFile(vertexShaderPath);
  vector<char> fragmentShaderCode = readBinFile(fragmentShaderPath);
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  GLint vertexShaderSize = vertexShaderCode.size();
  GLint fragmentShaderSize = fragmentShaderCode.size();
  char *pVertexShaderCode = vertexShaderCode.data();
  char *pFragmentShaderCode = fragmentShaderCode.data();
  glShaderSource(vertexShader, 1, &pVertexShaderCode, &vertexShaderSize);
  glShaderSource(fragmentShader, 1, &pFragmentShaderCode, &fragmentShaderSize);
  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);
  GLint infoLogLen;
  glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &infoLogLen);
  vector<char> infoLog(infoLogLen);
  glGetShaderInfoLog(vertexShader, infoLog.size(), nullptr, infoLog.data());
  infoLog.push_back('\0');
  printf(infoLog.data());
  infoLog.resize(0);
  glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &infoLogLen);
  infoLog.resize(infoLogLen);
  glGetShaderInfoLog(fragmentShader, infoLog.size(), nullptr, infoLog.data());
  infoLog.push_back('\0');
  printf(infoLog.data());
  infoLog.resize(0);
  program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLen);
  infoLog.resize(infoLogLen);
  glGetProgramInfoLog(program, infoLogLen, nullptr, infoLog.data());
  infoLog.push_back('\0');
  printf(infoLog.data());
  glDetachShader(program, vertexShader);
  glDetachShader(program, fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return program;
}

void Renderer::setModelMatrix(mat4 model)
{
  glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &model[0][0]);
}
void Renderer::setHasTexture(bool hasTexture)
{
  glUniform1i(hasTextureLocation, hasTexture);
}
void Renderer::setViewPrespective(mat4 viewPrespective)
{
  glUniformMatrix4fv(viewPrespectiveLocation, 1, GL_FALSE,
                     &viewPrespective[0][0]);
}
void Renderer::drawSkybox()
{
  if (skybox.has_value())
  {
    glDisable(GL_DEPTH_TEST);
    skybox.value().transform = Transform(player.transform.getPosition());
    setModelMatrix(skybox.value().getModelMatrix());
    setHasTexture(true);
    skybox.value().draw();
    glEnable(GL_DEPTH_TEST);
  }
}

GLuint Renderer::getShaderProgramID() { return shaderProgramID; }
void Renderer::setObserverPos(vec3 pos)
{
  glUniform3fv(observerLocation, 1, &pos.x);
}
void Renderer::setShadeless(bool shadeless)
{
  glUniform1i(shadelessLocation, shadeless);
}
