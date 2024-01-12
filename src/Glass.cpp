#include "Mesh.h"
#include "Transform.h"
#include <Glass.h>

using namespace glm;
using namespace std;
Glass::Glass(glm::vec3 c ,Material material,const char *texturePath )
    : Mesh(Transform(),texturePath,material) {
  positions = {{-1, -1, 0}, {1, -1, 0}, {1, 1, 0},
               {-1, -1, 0}, {-1, 1, 0}, {1, 1, 0}};

  normals = vector<vec3>(6, {0, 1, 0});
  colors = vector<vec4>(6, {c, 0.4});
  uvs = {{0, 0}, {1, 0}, {1, 1}, {0, 0}, {0, 1}, {1, 1}};
  init();
}
