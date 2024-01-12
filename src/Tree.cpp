#include "FileMesh.h"
#include "Transform.h"
#include<Tree.h>
using namespace std;
using namespace glm;
Tree::Tree(const char* texturePath):FileMesh("./assets/Trees/Tree.obj",Transform(),{1,1,1,1},texturePath ){
  
}
