#include "Mesh.h"
#include "Transform.h"
#include "Color.hpp"
#include <DummyTriangle.h>

using namespace std;
using namespace glm;

DummyTriangle::DummyTriangle() : Mesh(Transform()) {
  positions = {{-1, -1, -10}, {1, -1, -10}, {0, 1, -10}};
  normals = vector<vec3>(3, {0, 0, 0});
  uvs = vector<vec2>(3, {0, 0});
  colors = vector<vec4>(3, {Color::Red, 1});
  init();
}
