#include "Light.h"
#include <PointLight.h>

using namespace glm;
using namespace std;

PointLight::PointLight(vec4 ambient, vec4 diffuse, vec4 specular, vec3 position,
                       Mesh *parent) {
  this->parent=parent;
  lightStruct.ambient = ambient;
  lightStruct.diffuse = diffuse;
  lightStruct.specular = specular;
  lightStruct.position = position;
  lightStruct.type = POINT;
  lightStruct.enabled = true;
  transform = Transform(position);
}
