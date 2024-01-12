#pragma once
#include <Light.h>

class PointLight : public Light {
public:
  PointLight(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular,
             glm::vec3 position, Mesh *parent = nullptr);
};
