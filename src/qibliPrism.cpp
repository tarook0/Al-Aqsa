#include "Mesh.h"
#include "Transform.h"
#include "Color.hpp"
#include "qibliPrism.h"

using namespace std;
using namespace glm;

qibliPrism::qibliPrism(glm::vec3 c) : Mesh(Transform()) {
    drawPrism(c);
    init();
}

qibliPrism::qibliPrism(glm::vec3 c, const char* texturePath) : Mesh(Transform(), texturePath) {
    drawPrism(c);
    init();
}

void qibliPrism::drawPrism(glm::vec3 c) {
    positions = {
        {2.0f, 6.2f, 0.0f},
        {4.0f, 6.2f, 0.0f},
        {3.0f, 7.2f, 0.0f},

        {2.0f, 6.2f, 0.0f},
        {3.0f, 7.2f, 0.0f},
        {3.0f, 7.2f, -10.0f},
        {2.0f, 6.2f, 0.0f},
        {2.0f, 6.2f, -10.0f},
        {3.0f, 7.2f, -10.0f},

        {4.0f, 6.2f, 0.0f},
        {4.0f, 6.2f, -10.0f},
        {3.0f, 7.2f, -10.0f},
        {4.0f, 6.2f, 0.0f},
        {3.0f, 7.2f, 0.0f},
        {3.0f, 7.2f, -10.0f},

        {2.0f, 6.2f, 0.0f},
        {4.0f, 6.2f, 0.0f},
        {2.0f, 6.2f, -10.0f},
        {4.0f, 6.2f, 0.0f},
        {4.0f, 6.2f, -10.0f},
        {2.0f, 6.2f, -10.0f},

        {2.0f, 6.2f, -10.0f},
        {4.0f, 6.2f, -10.0f},
        {3.0f, 7.2f, -10.0f},
    };

    // Calculate normals
    normals = vector<vec3>(24, {0, 1, 0});

    // Calculate UVs
    uvs = {
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {0.5f, 1.0f},
        {0.0f, 0.0f},
        {0.5f, 1.0f},
        {1.0f, 0.0f},
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {0.5f, 1.0f},
        {0.0f, 0.0f},
        {0.5f, 1.0f},
        {1.0f, 0.0f},
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {0.5f, 1.0f},
        {0.0f, 0.0f},
        {0.5f, 1.0f},
        {1.0f, 0.0f},
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {0.5f, 1.0f},
        {0.0f, 0.0f},
        {0.5f, 1.0f},
        {1.0f, 0.0f},
    };

    colors = vector<vec4>(24, {c, 1.0f});

}
