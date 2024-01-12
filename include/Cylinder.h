#pragma once

#include<Mesh.h>
#include<glm/glm.hpp>
#include"Color.hpp"

class Cylinder:public Mesh
{

public:
    Cylinder(float baseRadius=1.0f, float topRadius=1.0f, float height=1.0f,
             int sectorCount=36, int stackCount=1, glm::vec3 c = Color::Gold, const char *texturePath = nullptr, Material material = Material());
   private:
   std::vector<float> unitCircleVertices;
   void buildUnitCircleVertices(int sectorCount);
    void buildVerticesFlat(float baseRadius, float topRadius, float height, int sectorCount,
                                     int stackCount,glm::vec3 c );
    std::vector<float> getSideNormals(float baseRadius, float topRadius, float height, int sectorCount,
                                     int stackCount);
};
