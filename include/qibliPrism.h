#pragma once

#include<Mesh.h>
#include "Color.hpp"

class qibliPrism:public Mesh{
public:
  qibliPrism( glm::vec3 c=Color::Blue);
   qibliPrism( glm::vec3 c, const char* texturePath);

  private:
    void drawPrism(glm::vec3 c);
};
