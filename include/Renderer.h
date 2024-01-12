#pragma once
#include "Mesh.h"
#include<vector>
#include<fstream>
#include<optional>
#include<GL/glew.h>
#include<glm/glm.hpp>
#include<Player.h>
#include<Skybox.h>
#include<Light.h>
class Renderer{
public:
  Renderer();
  void render();
  void setModelMatrix(glm::mat4 model);
  void setViewPrespective(glm::mat4 viewPrespective);
  void setObserverPos(glm::vec3 pos);
  void setHasTexture(bool hasTexture);
  GLuint getShaderProgramID();

  std::vector<Mesh> meshes;
  std::vector<Light> lights;
  Player player;
  std::optional<Skybox> skybox;
  bool shadeless=true;

private:
  std::vector<Mesh*> transparentMeshes;
  std::vector<Mesh*> solidMeshes;
  void drawSkybox();
  GLuint loadShaderProgram(const char* vertexShaderPath,const char* fragmentShaderPath);
  void setShadeless(bool shadeless);

  GLuint shaderProgramID;
  GLuint modelLocation;
  GLuint viewPrespectiveLocation,hasTextureLocation,observerLocation,shadelessLocation;
};
