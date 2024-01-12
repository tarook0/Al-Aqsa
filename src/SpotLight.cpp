#include "Transform.h"
#include<SpotLight.h>
using namespace glm;

SpotLight::SpotLight(vec4 ambient,vec4 diffuse,vec4 specular,vec3 position,vec3 direction,float angle,Mesh* parent){
  this->parent=parent;
  lightStruct.ambient=ambient;
  lightStruct.angle=angle/2.0f;
  lightStruct.diffuse=diffuse;
  lightStruct.direction=direction;
  lightStruct.enabled=true;
  lightStruct.position=position;
  lightStruct.specular=specular;
  lightStruct.type=SPOT;
  transform=Transform(position,direction);
}
