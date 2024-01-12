#pragma once

#include<Mesh.h>

class Polygon:public Mesh{
public:
  Polygon(int edge=6,const char* texturePath=nullptr,Material material=Material());
private:
    void generateVertices(int edge);
};
