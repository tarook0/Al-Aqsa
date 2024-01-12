#pragma once
#include "Transform.h"
#include <Mesh.h>
#include <assimp/Importer.hpp>

class FileMesh : public Mesh {
public:
  FileMesh(const char *meshPath, Transform transform,
           glm::vec4 color = {1, 1, 1, 1}, const char *texturePath = nullptr,
           Material material = Material(), GLenum drawMode = GL_TRIANGLES,
           Mesh *parent = nullptr);

private:
  static Assimp::Importer importer;
};
