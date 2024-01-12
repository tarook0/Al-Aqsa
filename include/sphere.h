#pragma once

#include<Mesh.h>
#include<glm/glm.hpp>
#include"Color.hpp"

class Sphere:public Mesh
{
public:
    Sphere(float radius=2.0f, unsigned int rings=50, unsigned int sectors=150,glm::vec3 c=Color::Gold,int t=1,const char* texturePath=nullptr,Material material=Material());
private:
struct Vertex {
    float x, y, z;
};

void generateSphereVertices(float radius, unsigned int rings, unsigned int sectors,glm::vec3 c);
void generateHalfSphereVertices(float radius, unsigned int rings, unsigned int sectors,glm::vec3 c);
};

