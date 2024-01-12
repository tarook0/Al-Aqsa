#include "FileMesh.h"
#include "Transform.h"
#include<CrescentMoon.h>
using namespace std;
using namespace glm;
CrescentMoon::CrescentMoon(const char* texturePath):FileMesh("./assets/Models/moon.glb",Transform(),{1,1,1,1},texturePath ){
  
}
