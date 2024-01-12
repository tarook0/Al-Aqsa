#include "Light.h"
#include <DirectionalLight.h>

using namespace glm;

DirectionalLight::DirectionalLight(vec4 ambient, vec4 diffuse, vec4 specular,
                                   vec3 direction, Mesh *parent) {
  this->parent = parent;
  lightStruct.ambient = ambient;
  lightStruct.diffuse = diffuse;
  lightStruct.specular = specular;
  lightStruct.direction = direction;
  lightStruct.enabled = true;
  lightStruct.type = DIRECTIONAL;
  transform = Transform({0, 0, 0}, direction);
}
