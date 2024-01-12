#pragma once
#include <Mesh.h>
#include <glm/glm.hpp>
enum LightType { DIRECTIONAL, POINT, SPOT };

class Light {
protected:
  struct LightStruct {
    int enabled;
    LightType type;
    float padding0, padding1;
    glm::vec4 ambient, diffuse, specular;
    glm::vec3 direction;
    float angle;
    glm::vec3 position;
    float padding2;
  } lightStruct;

  Mesh *parent;

  int indexInShaderArray;
  static GLuint UBO; // Uniform Buffer Object
  Light();

public:
  Transform transform;

  void updateInShader();

  void toggle();

  static void constructLightUniformBuffer(std::vector<Light> &lights);
};
