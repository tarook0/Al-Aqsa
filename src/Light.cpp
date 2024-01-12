#include <Light.h>

using namespace glm;
using namespace std;

GLuint Light::UBO;

Light::Light() {}

void Light::updateInShader() {
  LightStruct tempStruct = lightStruct;
  if (lightStruct.type == LightType::SPOT) {
    tempStruct.position =
        parent->getModelMatrix() * vec4(transform.getPosition(), 1);
    tempStruct.direction =
        parent->getModelMatrix() * vec4(lightStruct.direction, 0);
  }
  glBindBuffer(GL_UNIFORM_BUFFER, UBO);
  glBufferSubData(GL_UNIFORM_BUFFER, sizeof(LightStruct) * indexInShaderArray,
                  sizeof(LightStruct), &tempStruct);
  assert(glGetError() == 0);
}

void Light::toggle() {
  lightStruct.enabled = !lightStruct.enabled;
  updateInShader();
}

void Light::constructLightUniformBuffer(vector<Light> &lights) {
  if (lights.size() == 0)
    return;
  if (lights.size() > 20) {
    printf("requested more lights (%d) than the specified limit, ignoring past "
           "20 lights",
           lights.size());
  }
  vector<char> stagingBuffer(sizeof(LightStruct) * lights.size());
  for (unsigned i = 0; i < lights.size(); ++i) {
    memcpy(stagingBuffer.data() + i * sizeof(LightStruct),
           &lights[i].lightStruct, sizeof(lightStruct));
    lights[i].indexInShaderArray = i;
  }
  glGenBuffers(1, &UBO);
  glBindBuffer(GL_UNIFORM_BUFFER, UBO);
  glBufferData(GL_UNIFORM_BUFFER, sizeof(LightStruct) * lights.size(),
               stagingBuffer.data(), GL_DYNAMIC_DRAW);
  glBindBufferBase(GL_UNIFORM_BUFFER, 0, UBO);
  // TODO call these in renderer after calling this function
  //	int lightsIndex = glGetUniformBlockIndex(RENDERER.getMainShader(),
  //"Lights"); 	glUniformBlockBinding(RENDERER.getMainShader(), lightsIndex, 0);
  assert(glGetError() == 0);
}
