#pragma once
#include<cstring>
#include<GL/glew.h>
#include<Transform.h>
#include<Material.h>
#include<glm/glm.hpp>
#include<vector>
#include<stdio.h>


class Mesh{
public:
  Mesh(Transform transform,const char* texturePath=nullptr,Material material=Material(),GLenum drawMode=GL_TRIANGLES,Mesh* parent=nullptr);
  void draw();
  bool hasTexture();
  virtual void update();
  glm::mat4 getModelMatrix();
  Material getMaterial();
  
  Transform transform;
protected:
  void init(bool clearData=true);

  GLuint VAO,VBO,EBO;
  size_t verticesCount;
  std::vector<glm::vec4> colors;
  std::vector<glm::vec3> positions,normals;
  std::vector<glm::vec2> uvs;  
  std::vector<unsigned> indices;
  
  Mesh* parent;
  GLenum drawMode;
  GLuint textureID;
  unsigned indicesCount=0;
  Material material;
private:
  void initTexture();
  
  const char* texturePath;
};
