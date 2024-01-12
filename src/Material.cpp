#include <Material.h>

using namespace glm;

GLint Material::diffuseLoc;
GLint Material::ambientLoc;
GLint Material::specularLoc;
GLint Material::shininessLoc;
GLint Material::alphaLoc;

Material::Material(vec4 ambient, vec4 diffuse, vec4 specular, float shininess,
                   float alpha)
    : ambient(ambient), diffuse(diffuse), specular(specular),
      shininess(shininess), alpha(alpha) {}

Material::Material()
    : ambient({0.1f, 0.1f, 0.1f, 1.0f}), diffuse({0.6f, 0.6f, 0.6f, 1.0f}),
      specular({0.3f, 0.3f, 0.3f, 1.0f}), shininess(8.0f) {}

void Material::setAmbient(vec4 ambient) { this->ambient = ambient; }

void Material::setDiffuse(vec4 diffuse) { this->diffuse = diffuse; }

void Material::setSpecular(vec4 specular) { this->specular = specular; }

void Material::setShininess(float shininess) { this->shininess = shininess; }

void Material::setAlpha(float alpha) { this->alpha = alpha; }

float Material::getAlpha() { return alpha; }

void Material::setValuesInShader() {
  glUniform4fv(ambientLoc, 1, &ambient.x);
  glUniform4fv(diffuseLoc, 1, &diffuse.x);
  glUniform4fv(specularLoc, 1, &specular.x);
  glUniform1f(shininessLoc, shininess);
  glUniform1f(alphaLoc, alpha);
}

void Material::setLocValues(GLuint shaderProgram) {
  glUseProgram(shaderProgram);
  ambientLoc = glGetUniformLocation(shaderProgram, "material.ambient");
  diffuseLoc = glGetUniformLocation(shaderProgram, "material.diffuse");
  specularLoc = glGetUniformLocation(shaderProgram, "material.specular");
  shininessLoc = glGetUniformLocation(shaderProgram, "material.shininess");
  alphaLoc = glGetUniformLocation(shaderProgram, "material.alpha");
}
