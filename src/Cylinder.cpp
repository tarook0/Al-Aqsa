#include <Cylinder.h>
#include "Color.hpp"
#include "Material.h"
#include "Mesh.h"
#include "Transform.h"
#include <cmath>
#include <vector>

using namespace std;
using namespace glm;

Cylinder::Cylinder(float baseRadius, float topRadius, float height, int sectorCount,
                   int stackCount, vec3 c,const char *texturePath, Material material)
    : Mesh(Transform(), texturePath, material, GL_TRIANGLES)
{
    buildVerticesFlat( baseRadius,  topRadius,  height, sectorCount,stackCount,c);
    init(true);
}

void Cylinder::buildVerticesFlat(float baseRadius, float topRadius, float height, int sectorCount,
                                 int stackCount,glm::vec3 c )
{
    float x, y, z;                                  // vertex position
    float radius;                                   // radius for each stack 
    unsigned int topIndex;   
    unsigned int baseIndex;                                           
    // get normals for cylinder sides
    vector<float> sideNormals = getSideNormals(baseRadius,  topRadius,  height, sectorCount,stackCount);
    buildUnitCircleVertices(sectorCount);

    // put vertices of side cylinder to array by scaling unit circle
    for(int i = 0; i <= stackCount; ++i)
    {
        z = -(height * 0.5f) + (float)i / stackCount * height;      // vertex position z
        radius = baseRadius + (float)i / stackCount * (topRadius - baseRadius);     // lerp
        float t = 1.0f - (float)i / stackCount;   // top-to-bottom

        for(int j = 0, k = 0; j <= sectorCount; ++j, k += 3)
        {
            x = unitCircleVertices[k];
            y = unitCircleVertices[k+1];
            positions.push_back(vec3( x * radius, y * radius, z));   // position
            normals.push_back(vec3( sideNormals[k], sideNormals[k+1], sideNormals[k+2])); // normal
            uvs.push_back (vec2((float)j / sectorCount, t)); // tex coord
        }
    }

    // remember where the base.top vertices start
    unsigned int baseVertexIndex = (unsigned int)positions.size() / 3;

    // put vertices of base of cylinder
    z = -height * 0.5f;
    positions.push_back(vec3(0, 0, z));
    normals.push_back(vec3(0, 0, -1));
    uvs.push_back(vec2(0.5f, 0.5f));
    for(int i = 0, j = 0; i < sectorCount; ++i, j += 3)
    {
        x = unitCircleVertices[j];
        y = unitCircleVertices[j+1];
        positions.push_back(vec3(x * baseRadius, y * baseRadius, z));
        normals.push_back(vec3(0, 0, -1));
        uvs.push_back(vec2(-x * 0.5f + 0.5f, -y * 0.5f + 0.5f));    // flip horizontal
    }

    // remember where the base vertices start
    unsigned int topVertexIndex = (unsigned int)positions.size() / 3;

    // put vertices of top of cylinder
    z = height * 0.5f;
    positions.push_back(vec3(0, 0, z));
    normals.push_back(vec3(0, 0, 1));
    uvs.push_back(vec2(0.5f, 0.5f));
    for(int i = 0, j = 0; i < sectorCount; ++i, j += 3)
    {
        x = unitCircleVertices[j];
        y = unitCircleVertices[j+1];
         positions.push_back(vec3(x * topRadius, y * topRadius, z));
       normals.push_back(vec3(0, 0, 1));
        uvs.push_back(vec2(x * 0.5f + 0.5f, -y * 0.5f + 0.5f));
    }

    // put indices for sides
    unsigned int k1, k2;
    for(int i = 0; i < stackCount; ++i)
    {
        k1 = i * (sectorCount + 1);     // bebinning of current stack
        k2 = k1 + sectorCount + 1;      // beginning of next stack

        for(int j = 0; j < sectorCount; ++j, ++k1, ++k2)
        {
            // 2 trianles per sector
            indices.push_back(k1);
            indices.push_back(k1+1);
            indices.push_back(k2);
            indices.push_back(k2);
            indices.push_back(k1+1);
            indices.push_back(k2+1);
        }
    }

    // remember where the base indices start
    baseIndex = (unsigned int)indices.size();

    // put indices for base
    for(int i = 0, k = baseVertexIndex + 1; i < sectorCount; ++i, ++k)
    {
        if(i < (sectorCount - 1)){
           indices.push_back(baseVertexIndex);
            indices.push_back(k+1);
            indices.push_back(k);
        }
        else{    // last triangle
            indices.push_back(baseVertexIndex);
            indices.push_back(baseVertexIndex+1);
            indices.push_back(k);
        }
    }

    // remember where the base indices start
    topIndex = (unsigned int)indices.size();

    for(int i = 0, k = topVertexIndex + 1; i < sectorCount; ++i, ++k)
    {
        if(i < (sectorCount - 1)){
            indices.push_back(baseVertexIndex);
            indices.push_back(k);
            indices.push_back(k+1);
        }
        else
        {
            indices.push_back(topVertexIndex);
            indices.push_back(k);
            indices.push_back(topVertexIndex+1);
        }
    }
    colors = vector<vec4>(positions.size(), {c, 1});
}


std::vector<float> Cylinder::getSideNormals(float baseRadius, float topRadius, float height, int sectorCount,
                                     int stackCount)
{
    const float PI = acos(-1.0f);
    float sectorStep = 2 * PI / sectorCount;
    float sectorAngle;  // radian

    // compute the normal vector at 0 degree first
    // tanA = (baseRadius-topRadius) / height
    float zAngle = atan2(baseRadius - topRadius, height);
    float x0 = cos(zAngle);     // nx
    float y0 = 0;               // ny
    float z0 = sin(zAngle);     // nz

    // rotate (x0,y0,z0) per sector angle
    std::vector<float> normals;
    for(int i = 0; i <= sectorCount; ++i)
    {
        sectorAngle = i * sectorStep;
        normals.push_back(cos(sectorAngle)*x0 - sin(sectorAngle)*y0);   // nx
        normals.push_back(sin(sectorAngle)*x0 + cos(sectorAngle)*y0);   // ny
        normals.push_back(z0);  // nz
    }

    return normals;
}
void Cylinder::buildUnitCircleVertices(int sectorCount)
{
    const float PI = acos(-1.0f);
    float sectorStep = 2 * PI / sectorCount;
    float sectorAngle;  // radian

    std::vector<float>().swap(unitCircleVertices);
    for(int i = 0; i <= sectorCount; ++i)
    {
        sectorAngle = i * sectorStep;
        unitCircleVertices.push_back(cos(sectorAngle)); // x
        unitCircleVertices.push_back(sin(sectorAngle)); // y
        unitCircleVertices.push_back(0);                // z
    }
}