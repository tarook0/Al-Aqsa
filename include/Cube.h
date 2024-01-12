#pragma once

#include<Mesh.h>
#include "Color.hpp"

class Cube:public Mesh{
public:
   Cube(glm::vec3 c = Color::White);
    Cube(glm::vec3 c, const char* texturePath);
  private:
    void cubeDraw(glm::vec3 c);
};
