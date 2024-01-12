#pragma once
#include<Mesh.h>


class TexturedQuad:public Mesh{
public:
  TexturedQuad(const char* texturePath);
};
