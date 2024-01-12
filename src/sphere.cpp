#include "Color.hpp"
#include "Material.h"
#include "Mesh.h"
#include "Transform.h"
#include <cmath>
#include <sphere.h>
#include <vector>

using namespace std;
using namespace glm;
//1.0F, 50, 150
Sphere::Sphere(float radius, unsigned int rings, unsigned int sectors, vec3 c,
               int t,const char* texturePath, Material material)
    : Mesh(Transform(), texturePath, material, GL_POLYGON) {

  if (t == 0) {
    generateSphereVertices(radius, rings, sectors, c);
  } else {
    generateHalfSphereVertices(radius, rings, sectors, c);
  }
  init(true);
}

void Sphere::generateHalfSphereVertices(float radius, unsigned int rings,
                                        unsigned int sectors, vec3 c) {
   const float PI = acos(-1.0f);

    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // normal
    float s, t;                                     // texCoord

    float sectorStep = 2 * PI / sectors;
    float stackStep = PI / rings;
    float sectorAngle, stackAngle;

    for(int i = 0; i <= rings; ++i)
    {
        stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

      
        for(int j = 0; j <= sectors; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            if(y<0){
            positions.push_back(vec3( x, -y, z));
            }
            else
            {
              positions.push_back(vec3( x, y, z));
            }
            
            // normalized vertex normal
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(vec3(nx, ny, nz));

            // vertex tex coord between [0, 1]
            s = (float)j / sectors;
            t = (float)i / rings;
            uvs.push_back(vec2(s, t));
        }
    }

    // indices
    //  k1--k1+1
    //  |  / |
    //  | /  |
    //  k2--k2+1
    unsigned int k1, k2;
    for(int i = 0; i < rings; ++i)
    {
        k1 = i * (sectors + 1);     
        k2 = k1 + sectors + 1;      

        for(int j = 0; j < sectors; ++j, ++k1, ++k2)
        {
            if(i != 0)
            {
                indices.push_back(k1) ;
                 indices.push_back(k2);
                 indices.push_back(k1+1);  // k1---k2---k1+1
            }

            if(i != (rings-1))
            {
                   indices.push_back(k1+1) ;
                 indices.push_back(k2);
                 indices.push_back(k2+1); 
            }
        }
    }
    colors = vector<vec4>(positions.size(), {c, 1});
}

void Sphere::generateSphereVertices(float radius, unsigned int rings,
                                    unsigned int sectors, vec3 c) {
   const float PI = acos(-1.0f);

    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // normal
    float s, t;                                     // texCoord

    float sectorStep = 2 * PI / sectors;
    float stackStep = PI / rings;
    float sectorAngle, stackAngle;

    for(int i = 0; i <= rings; ++i)
    {
        stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        for(int j = 0; j <= sectors; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
              positions.push_back(vec3( x, y, z));
            // normalized vertex normal
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(vec3(nx, ny, nz));

            // vertex tex coord between [0, 1]
            s = (float)j / sectors;
            t = (float)i / rings;
            uvs.push_back(vec2(s, t));
        }
    }

    // indices
    //  k1--k1+1
    //  |  / |
    //  | /  |
    //  k2--k2+1
    unsigned int k1, k2;
    for(int i = 0; i < rings; ++i)
    {
        k1 = i * (sectors + 1);     // beginning of current stack
        k2 = k1 + sectors + 1;      // beginning of next stack

        for(int j = 0; j < sectors; ++j, ++k1, ++k2)
        {
            if(i != 0)
            {
                indices.push_back(k1) ;
                 indices.push_back(k2);
                 indices.push_back(k1+1);  // k1---k2---k1+1
            }

            if(i != (rings-1))
            {
                   indices.push_back(k1+1) ;
                 indices.push_back(k2);
                 indices.push_back(k2+1); 
            }
        }
    }
    colors = vector<vec4>(positions.size(), {c, 1});
}