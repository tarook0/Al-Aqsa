#pragma once

#include "Mesh.h"
#include "Color.hpp"

class qibliCuboid : public Mesh {
public:
    qibliCuboid(glm::vec3 c, const char* texturePath, std::vector<glm::vec3> customNormals = {});
private:
    void cuboid(glm::vec3 c, std::vector<glm::vec3> customNormals);
};
