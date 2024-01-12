#pragma once

#include <Mesh.h>

class Circle : public Mesh {
public:
    Circle(float radius = 1.0f, int segments = 30);

private:
    void generateVertices(float radius, int segments);
};
