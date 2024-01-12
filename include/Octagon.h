    #pragma once

#include<Mesh.h>
#include<glm/glm.hpp>
#include"Color.hpp"
class Octagon: public Mesh
{
public:
    Octagon(glm::vec3 c=Color::Red,int x=0,const char* texturePath=nullptr,Material material=Material());

    private:
        void upFace(glm::vec3 c);
    void octagonDarw1(glm::vec3 c);
    void octagonDarw2(glm::vec3 c);
    void octagonDarw3(glm::vec3 c);
    void octagonDarw4(glm::vec3 c);
    void octagonDarw5(glm::vec3 c);
    void octagonDarw6(glm::vec3 c);
    void octagonDarw7(glm::vec3 c);
    void octagonDarw8(glm::vec3 c);
    void downFace(glm::vec3 c);
};

