#include "Material.h"
#include "Mesh.h"
#include "Transform.h"
#include <FileMesh.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
using namespace Assimp;
using namespace glm;
using namespace std;

Importer FileMesh::importer;

FileMesh::FileMesh(const char *meshPath, Transform transform, vec4 color,
                   const char *texturePath,Material material, GLenum drawMode, Mesh *parent)
    : Mesh(transform, texturePath,material, drawMode, parent) {
  auto scene = importer.ReadFile(meshPath, aiProcess_Triangulate);
  auto mesh = scene->mMeshes[0];
  for (uint i = 0; i < mesh->mNumVertices; ++i) {
    auto v = mesh->mVertices[i];
    auto n = mesh->mNormals[i];
    auto uv = mesh->mTextureCoords[0][i];
    positions.push_back({v.x, v.y, v.z});
    normals.push_back({n.x, n.y, n.z});
    uvs.push_back({uv.x, uv.y});
  }
  for (uint i = 0; i < mesh->mNumFaces; ++i) {
    for (uint j = 0; j < mesh->mFaces[i].mNumIndices; j++) {
      indices.push_back(mesh->mFaces[i].mIndices[j]);
    }
  }
  colors = vector<vec4>(mesh->mNumVertices, color);
  importer.FreeScene();
  init();
}

