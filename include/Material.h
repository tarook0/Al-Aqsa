#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Material {
private:
  static GLint ambientLoc, diffuseLoc, specularLoc, shininessLoc, alphaLoc;

  glm::vec4 ambient, diffuse, specular;
  float shininess, alpha = 1.0f;

public:
  Material();
  Material(glm::vec4 ambient, glm::vec4 diffues, glm::vec4 specular,
           float shininess, float alpha = 1.0f);

  void setAmbient(glm::vec4 ambient);
  void setDiffuse(glm::vec4 diffues);
  void setSpecular(glm::vec4 specular);
  void setShininess(float shininess);
  void setAlpha(float alpha);

  float getAlpha();

  void setValuesInShader();

  static void setLocValues(GLuint shaderProgram);
};
