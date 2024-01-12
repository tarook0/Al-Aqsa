#include "Mesh.h"
#include "Transform.h"
#include "Color.hpp"
#include "qibliCuboid.h"

using namespace std;
using namespace glm;

qibliCuboid::qibliCuboid(glm::vec3 c, const char* texturePath, std::vector<glm::vec3> customNormals)
    : Mesh(Transform(), texturePath) {
    cuboid(c, customNormals);
    init();
}

void qibliCuboid::cuboid(glm::vec3 c, std::vector<glm::vec3> customNormals) {
    // Define the positions for the rectangular prism
    positions = {
        // Front face
        {0.0f, 0.0f, 0.0f},    // 0
        {6.0f, 0.0f, 0.0f},    // 1
        {0.0f, 6.0f, 0.0f},    // 2
        {6.0f, 0.0f, 0.0f},    // 3
        {6.0f, 6.0f, 0.0f},    // 4
        {0.0f, 6.0f, 0.0f},    // 5
    };

    uvs = {
        {0, 0}, {1, 0}, {0, 1},
        {1, 0}, {1, 1}, {0, 1},
    };

    // if (!customNormals.empty()) {
    //     // Use custom normals if provided
    //     normals = customNormals;
    // } else {
    //     // Use default normals
    normals = vector<vec3>(6, {0, 1, 0});

    // }

    colors = vector<vec4>(36, {c, 1});
}
