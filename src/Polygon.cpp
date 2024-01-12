#include "Mesh.h"
#include "Transform.h"
#include "Color.hpp"
#include "Polygon.h"

using namespace std;
using namespace glm;

Polygon::Polygon(int edge,const char* texturePath,Material material) : Mesh(Transform(),texturePath,material,GL_POLYGON) {
    generateVertices(edge);
  init(true);
}
void Polygon::generateVertices(int edge){
    GLfloat center_x=0.0;
    GLfloat center_z=0.0;
    GLfloat size=2.0;
    for (GLfloat i = 0; i < edge; i++) {
    GLfloat angle = 2 * glm::pi<float>() / edge * (i + 0.5);
    GLfloat vertex_x = center_x + size * cos(angle);
    GLfloat vertex_z = center_z + size * sin(angle);
    GLfloat u = 0.5 * (1 + cos(angle));
    GLfloat v = 0.5 * (1 + sin(angle));
    positions.emplace_back(vertex_x, 0, vertex_z); 
    uvs.emplace_back(u,v);
}
  normals = vector<vec3>(edge, {0, 1, 0});
  colors = vector<vec4>(edge, {Color::White, 1});
}

