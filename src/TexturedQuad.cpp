#include "Mesh.h"
#include "Transform.h"
#include <TexturedQuad.h>

using namespace glm;
using namespace std;
TexturedQuad::TexturedQuad(const char *texturePath)
    : Mesh(Transform(), texturePath) {
  positions = {{-1, -1, 0}, {1, -1, 0}, {1, 1, 0},
               {-1, -1, 0}, {-1, 1, 0}, {1, 1, 0}};

  normals = vector<vec3>(6, {0, 1, 0});
  colors = vector<vec4>(6, {1, 1, 1, 1});
  uvs = {{0, 0}, {1, 0}, {1, 1}, {0, 0}, {0, 1}, {1, 1}};
  init();
}
