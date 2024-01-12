#include "FileMesh.h"
#include "Transform.h"
#include<Luster.h>
using namespace std;
using namespace glm;

Luster::Luster(const char* texturePath):FileMesh("./assets/Models/MODUL_CHANDELIER.obj",Transform(),{1,1,1,1},texturePath){
  
}
