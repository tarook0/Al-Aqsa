#include "Transform.h"
#include <Mesh.h>
#include <SFML/Graphics/Image.hpp>
#include <memory>

using namespace std;
using namespace glm;
using namespace sf;

Mesh::Mesh(Transform transform, const char *texturePath, Material material,
           GLenum drawMode, Mesh *parent)
    : transform(transform), parent(parent), drawMode(drawMode),
      material(material), texturePath(texturePath) {}

void Mesh::update() {}

void Mesh::init(bool clearData) {
  verticesCount = positions.size();
  vector<char> vertexBuffer(

      positions.size() * sizeof(vec3) + normals.size() * sizeof(vec3) +
      uvs.size() * sizeof(vec2) + colors.size() * sizeof(vec4));

  memcpy(vertexBuffer.data(), positions.data(),
         positions.size() * sizeof(vec3));

  memcpy(vertexBuffer.data() + positions.size() * sizeof(vec3), normals.data(),
         normals.size() * sizeof(vec3));

  memcpy(vertexBuffer.data() + positions.size() * sizeof(vec3) +
             normals.size() * sizeof(vec3),
         uvs.data(), uvs.size() * sizeof(vec2));

  memcpy(vertexBuffer.data() + positions.size() * sizeof(vec3) +
             normals.size() * sizeof(vec3) + uvs.size() * sizeof(vec2),
         colors.data(), colors.size() * sizeof(vec4));

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertexBuffer.size(), vertexBuffer.data(),
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);
  glEnableVertexAttribArray(3);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
                        (void *)(positions.size() * sizeof(vec3)));
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0,
                        (void *)(positions.size() * sizeof(vec3) +
                                 normals.size() * sizeof(vec3)));
  glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 0,
                        (void *)(positions.size() * sizeof(vec3) +
                                 normals.size() * sizeof(vec3) +
                                 uvs.size() * sizeof(vec2)));
  if (indices.size() > 0) {
    glBindVertexArray(VAO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * indices.size(),
                 indices.data(), GL_STATIC_DRAW);
    indicesCount = indices.size();
  }
  if (clearData) {
    positions.clear();
    normals.clear();
    uvs.clear();
    colors.clear();
    indices.clear();
  }
  if (texturePath != nullptr)
    initTexture();
}

mat4 Mesh::getModelMatrix() {
  mat4 parentMat(1.0f);
  if (parent != nullptr)
    parentMat = parent->getModelMatrix();

  vec3 translation = transform.getPosition();
  vec3 scale = transform.getScale();

  mat4 transMat = translate(mat4(1.0f), translation);
  mat4 rotationMat = mat4(transform.getRotation());
  mat4 scaleMat = glm::scale(mat4(1.0f), scale);

  mat4 transform = transMat * rotationMat * scaleMat;

  return parentMat * transform;
}

void Mesh::draw() {
  if (texturePath != nullptr) {
    glBindTexture(GL_TEXTURE_2D, textureID);
  }
  material.setValuesInShader();
  glBindVertexArray(VAO);
  if (indicesCount == 0) {
    glDrawArrays(drawMode, 0, verticesCount);
  } else {
    glDrawElements(drawMode, indicesCount, GL_UNSIGNED_INT, (void *)0);
  }
}

void Mesh::initTexture() {
  Image img;
  img.loadFromFile(texturePath);
  img.flipVertically();

  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, img.getSize().x, img.getSize().y, 0,
               GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
}
bool Mesh::hasTexture() {
  if (texturePath != nullptr) {
    return true;
  }
  return false;
}
Material Mesh::getMaterial(){
  return material;
}
