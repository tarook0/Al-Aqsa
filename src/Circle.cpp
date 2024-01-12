#include "Mesh.h"
#include "Transform.h"
#include <Circle.h>
#include "Color.hpp"
#include <cmath>

Circle::Circle(float radius, int segments) : Mesh(Transform()) {
    generateVertices(radius, segments);
    init();
}

void Circle::generateVertices(float radius, int segments) {
    positions.clear();
    normals.clear();
    uvs.clear();
    colors.clear();

    float angleIncrement = 2.0f * glm::pi<float>() / static_cast<float>(segments);

    for (int i = 0; i < segments; ++i) {
        float angle1 = i * angleIncrement;
        float angle2 = (i + 1) * angleIncrement;

        float x1 = radius * std::cos(angle1);
        float y1 = radius * std::sin(angle1);

        float x2 = radius * std::cos(angle2);
        float y2 = radius * std::sin(angle2);

        // Center point
        positions.emplace_back(0, 0, 0);
        normals.emplace_back(0, 0, 1); // Assuming the circle lies in the XY plane
        uvs.emplace_back(0.5f, 0.5f);  // Center of the UV space
        colors.emplace_back(Color::SkyBlue, 1);

        // First point on the circle
        positions.emplace_back(x1, y1, 0);
        normals.emplace_back(0, 0, 1);
        uvs.emplace_back((x1 + 1.0f) * 0.5f, (y1 + 1.0f) * 0.5f); // Map to UV space
        colors.emplace_back(Color::SkyBlue, 1);

        // Second point on the circle
        positions.emplace_back(x2, y2, 0);
        normals.emplace_back(0, 0, 1);
        uvs.emplace_back((x2 + 1.0f) * 0.5f, (y2 + 1.0f) * 0.5f); // Map to UV space
        colors.emplace_back(Color::SkyBlue, 1);
    }
}
