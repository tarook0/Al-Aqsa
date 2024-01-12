#pragma once

#include<Mesh.h>
#include "Color.hpp"

class Grass:public Mesh{
public:
   Grass(glm::vec3 c = Color::White);
    Grass(glm::vec3 c, const char* texturePath);
  private:
    void GrassDraw(glm::vec3 c);
};
