#pragma once
#include <FileMesh.h>
#include <string>
#include <vector>

class Skybox : public FileMesh {
public:
  Skybox(const char* texturePath);
};
