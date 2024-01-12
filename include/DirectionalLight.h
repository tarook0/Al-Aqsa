#pragma once
#include <Light.h>

class DirectionalLight : public Light {
public:
  DirectionalLight(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular,
                   glm::vec3 direction, Mesh *parent = nullptr);
};
