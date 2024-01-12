#pragma once

#include<Mesh.h>
#include "Color.hpp"

class Floor:public Mesh{
public:
   Floor(glm::vec3 c = Color::White);
    Floor(glm::vec3 c, const char* texturePath);
  private:
    void floorDraw(glm::vec3 c);
};
