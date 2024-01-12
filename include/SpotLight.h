#pragma once
#include<Light.h>

class SpotLight:public Light{
public:
  SpotLight(glm::vec4 ambient,glm::vec4 diffuse,glm::vec4 specular,glm::vec3 position,glm::vec3 direction,float angle,Mesh* parent=nullptr);
};
