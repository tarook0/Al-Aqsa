#include "Mesh.h"
#include "Transform.h"
#include "Color.hpp"
#include <Cube.h>

using namespace std;
using namespace glm;

Cube::Cube(glm::vec3 c) : Mesh(Transform()) {
    cubeDraw(c);
    init();
}

Cube::Cube( glm::vec3 c,const char *texturePath) : Mesh(Transform() , texturePath) {
cubeDraw(c);
  init();
}

void Cube::cubeDraw(glm::vec3 c){
  positions ={
        // positions        
        {-0.5f, -0.5f, -0.5f}, 
        { 0.5f, -0.5f, -0.5f}, 
        { 0.5f,  0.5f, -0.5f}, 
        { 0.5f,  0.5f, -0.5f}, 
        {-0.5f,  0.5f, -0.5f}, 
        {-0.5f, -0.5f, -0.5f}, 
        {-0.5f, -0.5f,  0.5f}, 
        { 0.5f, -0.5f,  0.5f}, 
        { 0.5f,  0.5f,  0.5f}, 
        { 0.5f,  0.5f,  0.5f}, 
        {-0.5f,  0.5f,  0.5f}, 
        {-0.5f, -0.5f,  0.5f}, 
        {-0.5f,  0.5f,  0.5f}, 
        {-0.5f,  0.5f, -0.5f}, 
        {-0.5f, -0.5f, -0.5f}, 
        {-0.5f, -0.5f, -0.5f}, 
        {-0.5f, -0.5f,  0.5f}, 
        {-0.5f,  0.5f,  0.5f}, 
        { 0.5f,  0.5f,  0.5f}, 
        { 0.5f,  0.5f, -0.5f}, 
        { 0.5f, -0.5f, -0.5f}, 
        { 0.5f, -0.5f, -0.5f}, 
        { 0.5f, -0.5f,  0.5f}, 
        { 0.5f,  0.5f,  0.5f}, 
        {-0.5f, -0.5f, -0.5f}, 
        { 0.5f, -0.5f, -0.5f}, 
        { 0.5f, -0.5f,  0.5f}, 
        { 0.5f, -0.5f,  0.5f}, 
        {-0.5f, -0.5f,  0.5f}, 
        {-0.5f, -0.5f, -0.5f}, 
        {-0.5f,  0.5f, -0.5f}, 
        { 0.5f,  0.5f, -0.5f}, 
        { 0.5f,  0.5f,  0.5f}, 
        { 0.5f,  0.5f,  0.5f}, 
        {-0.5f,  0.5f,  0.5f}, 
        {-0.5f,  0.5f, -0.5f},
    };
normals = {
        {0, 1, 0},  // Front
        {0, 1, 0},   // Back
        {0, 1, 0},  // Bottom
        {0, 1, 0},   // Top
        {0, 1, 0},  // Left
        {1, 1, 0}    // Right
    };
   uvs = {
        {0, 0}, {1, 0}, {1, 1},
        {1, 1}, {0, 1}, {0, 0},
        {0, 0}, {1, 0}, {1, 1},
        {1, 1}, {0, 1}, {0, 0},
        {0, 0}, {1, 0}, {1, 1},
        {1, 1}, {0, 1}, {0, 0},
        {0, 0}, {1, 0}, {1, 1},
        {1, 1}, {0, 1}, {0, 0},
        {0, 0}, {1, 0}, {1, 1},
        {1, 1}, {0, 1}, {0, 0},
        {0, 0}, {1, 0}, {1, 1},
        {1, 1}, {0, 1}, {0, 0}
    };

  colors = vector<vec4>(36, {c, 1});
}

