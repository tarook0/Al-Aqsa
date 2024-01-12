#include "FileMesh.h"
#include "Transform.h"
#include<Skybox.h>
using namespace std;
using namespace glm;
Skybox::Skybox(const char* texturePath):FileMesh("./assets/SkyBoxes/Cube.glb",Transform(),{1,1,1,1},texturePath ){
  
}
