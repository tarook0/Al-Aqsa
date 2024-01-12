#pragma once

#include<Mesh.h>
#include "Color.hpp"

class Fence:public Mesh{
public:
   Fence(glm::vec3 c = Color::White);
    Fence(glm::vec3 c, const char* texturePath);
  private:
    void FenceDraw(glm::vec3 c);
};
