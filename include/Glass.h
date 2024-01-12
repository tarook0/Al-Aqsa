#pragma once
#include<Mesh.h>
#include<glm/glm.hpp>
#include"Color.hpp"

class Glass:public Mesh{
public:
  Glass( glm::vec3 c = Color::White,Material material = Material(),const char *texturePath = nullptr);
};
