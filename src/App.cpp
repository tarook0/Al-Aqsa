#include "Circle.h"
#include "glass.h"
#include "Floor.h"
#include "Grass.h"
#include "Cube.h"
#include "Fence.h"
#include "DirectionalLight.h"
#include "DummyTriangle.h"
#include "Octagon.h"
#include "Polygon.h"
#include "Skybox.h"
#include "TexturedQuad.h"
#include "Transform.h"
#include "qibliCuboid.h"
#include "qibliPrism.h"
#include "sphere.h"
#include "Tree.h"
#include "Luster.h"
#include "Cylinder.h"
#include "CrescentMoon.h"
#include <App.h>
#include <PointLight.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

App::App()
{
    GLfloat width, hight, cubeScaleW, cubeScaleH;
    width = 49.9f;
    hight = 74.4f;
    cubeScaleH = 150.0f;
    cubeScaleW = 100.0f;
    renderer.skybox = Skybox("./assets/SkyBoxes/Daylight.png");

    // Floor Darwing
    renderer.meshes.push_back(Floor(Color::White, "./assets/stone_1.jpg"));
    renderer.meshes[0].transform.translate(glm::vec3(0.0f, -0.5f, 0.0f));
    renderer.meshes[0].transform.scale(glm::vec3(cubeScaleH * 2, 0.1f, cubeScaleW * 2));

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/floor.jpg"));
    renderer.meshes[1].transform.scale(glm::vec3(cubeScaleH / 3.0f, 1.75f, cubeScaleW / 2.0f));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Dome of the rock
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Dome & walls & floor& roof
    renderer.meshes.push_back(Sphere(2.9F, 50, 150, Color::Gold, 1, "./assets/Gold.png"));
    renderer.meshes.push_back(Octagon(Color::Cyan, 1, "./assets/marble.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 1, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 2, "./assets/front_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 3, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 4, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 5, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 6, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 7, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 8, "./assets/side_face.jpg"));
    renderer.meshes.push_back(Octagon(Color::White, 9, "./assets/side_face.jpg"));
    renderer.meshes[2].transform.rotate(glm::vec3(0.0f, 0.1f, 0.0f), 180);
    renderer.meshes[2].transform.translate(glm::vec3(0.0f, 7.4f, 0.0f));
    renderer.meshes[2].transform.scale(glm::vec3(0.01f, 0.03f, 0.04f));
    renderer.meshes[3].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[4].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[5].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[6].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[7].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[8].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[9].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[10].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[11].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[12].transform.scale(glm::vec3(2.2f, 0.7f, 2.2f));
    renderer.meshes[3].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[4].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[5].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[6].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[7].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[8].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[9].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[10].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[11].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    renderer.meshes[12].transform.translate(glm::vec3(0.0f, 1.6f, 0.0f));
    // Under column Cylinder Dome of the rock
    renderer.meshes.push_back(Cylinder(2.90f, 2.90f, 1.2f, 50, 50, Color::White, "./assets/under_dome.jpg"));
    renderer.meshes[13].transform.translate(glm::vec3(0.0f, 6.6f, 0.0f));
    renderer.meshes[13].transform.rotate(glm::vec3(1, 0, 0), -90.f);
    // Dome of the Rock Edit
    renderer.meshes.push_back(Cylinder(3.0f, 6.3f, 1.0f, 8, 1, Color::White, "./assets/metalbox.png"));
    renderer.meshes[14].transform.rotate(glm::vec3(1.0, 0.0, 0.0), 90.f);
    renderer.meshes[14].transform.rotate(glm::vec3(0.0, 0.0, 1.0), 23.0f);
    renderer.meshes[14].transform.setPosition(glm::vec3(0.0f, 5.5f, 0.0f));

    renderer.meshes.push_back(Cylinder(3.0f, 3.0f, 0.15f, 50, 10, Color::Cyan, "./assets/metalbox.png"));
    renderer.meshes[15].transform.rotate(glm::vec3(1.0, 0.0, 0.0), 90.f);
    renderer.meshes[15].transform.setPosition(glm::vec3(0.0f, 7.25f, 0.0f));
    // Cylinder above  column Dome of the rock
    renderer.meshes.push_back(Cylinder(0.01f, 0.01f, 1.7f, 10, 10, Color::Gold, "./assets/Gold.png"));
    renderer.meshes[16].transform.translate(glm::vec3(0.0f, 10.4f, 0.0f));
    renderer.meshes[16].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    // Teppich
    renderer.meshes.push_back(Octagon(Color::White, 1, "./assets/Teppich.png"));
    renderer.meshes[17].transform.translate(glm::vec3(0.0f, -0.6f, 0.0f));
    renderer.meshes[17].transform.rotate(glm::vec3(0, 1, 0), -90.0f);
    renderer.meshes[17].transform.scale(glm::vec3(2.2f, 0.3f, 2.2f));
    // crescent moon
    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[18].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[18].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[18].transform.setPosition(glm::vec3(0.0f, 11.35f, 0.075f));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //          Dome of the rock End
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //          multi_columns
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // multi_column
    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb", Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}},
                                       "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[19].transform.translate(glm::vec3(-20.0f, 1.2f, 0.0f));
    renderer.meshes[19].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[20].transform.translate(glm::vec3(-20.0f, 1.2f, 2.2f));
    renderer.meshes[20].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[21].transform.translate(glm::vec3(-20.0f, 1.2f, 4.4f));
    renderer.meshes[21].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[22].transform.translate(glm::vec3(-20.0f, 1.2f, -2.2f));
    renderer.meshes[22].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[23].transform.translate(glm::vec3(20.0f, 1.2f, 0.0f));
    renderer.meshes[23].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[24].transform.translate(glm::vec3(20.0f, 1.2f, 2.2f));
    renderer.meshes[24].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[25].transform.translate(glm::vec3(20.0f, 1.2f, 4.4f));
    renderer.meshes[25].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[26].transform.translate(glm::vec3(20.0f, 1.2f, -2.2f));
    renderer.meshes[26].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[27].transform.translate(glm::vec3(0.0f, 1.2f, 20.0f));
    renderer.meshes[27].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[27].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[28].transform.translate(glm::vec3(2.2f, 1.2f, 20.0f));
    renderer.meshes[28].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[28].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);
    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[29].transform.translate(glm::vec3(4.4f, 1.2f, 20.0f));
    renderer.meshes[29].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[29].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[30].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[30].transform.translate(glm::vec3(-2.2f, 1.2f, 20.0f));
    renderer.meshes[30].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[31].transform.translate(glm::vec3(0.0f, 1.2f, -20.0f));
    renderer.meshes[31].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[31].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[32].transform.translate(glm::vec3(2.2f, 1.2f, -20.0f));
    renderer.meshes[32].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[32].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);
    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[33].transform.translate(glm::vec3(4.4f, 1.2f, -20.0f));
    renderer.meshes[33].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[33].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);

    renderer.meshes.push_back(FileMesh("./assets/Models/multi_column/multi_column_model.glb",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/multi_column/multi_column.jpeg"));
    renderer.meshes[34].transform.setScale(glm::vec3(0.1f, 0.1f, 0.1f));
    renderer.meshes[34].transform.translate(glm::vec3(-2.2f, 1.2f, -20.0f));
    renderer.meshes[34].transform.setRotation(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //          multi_columns end
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //        Dome of the chain Parts
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Floor
    renderer.meshes.push_back(Polygon(10, "./assets/ceramic.jpg"));
    renderer.meshes[35].transform.scale(glm::vec3(1.3f, 2.0f, 1.3f));
    renderer.meshes[35].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    // Columns 13
    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[36].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[36].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[36].transform.translate(glm::vec3((1.90221f * 2.0f), 0.0f, (0.617731f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[37].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[37].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[37].transform.translate(glm::vec3(-(1.90221f * 2.0f), 0.0f, (0.617731f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[38].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[38].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[38].transform.translate(glm::vec3((1.90221f * 2.0f), 0.0f, -(0.617731f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[39].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[39].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[39].transform.translate(glm::vec3(-(1.90221f * 2.0f), 0.0f, -(0.617731f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[40].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[40].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[40].transform.translate(glm::vec3(-(1.17634f * 2.0f), 0.0f, -(1.61747f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[41].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[41].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[41].transform.translate(glm::vec3((1.17634f * 2.0f), 0.0f, -(1.61747f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[42].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[42].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[42].transform.translate(glm::vec3((1.17634f * 2.0f), 0.0f, (1.61747f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[43].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[43].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[43].transform.translate(glm::vec3(-(1.17634f * 2.0f), 0.0f, (1.61747f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[44].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[44].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[44].transform.translate(glm::vec3(-(0.00159255f * 2.0f), 0.0f, (2.0f * 2.0f)));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[45].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[45].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[45].transform.translate(glm::vec3(-(0.00159255f * 2.0f), 0.0f, -(2.0f * 2.0f)));
    // inner Columns
    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[46].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[46].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[46].transform.translate(glm::vec3(1.73232f, 0.0f, 0.99954f));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[47].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[47].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[47].transform.translate(glm::vec3(0.00159231f, 0.0f, 2.0f));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[48].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[48].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[48].transform.translate(glm::vec3(-1.73072f, 0.0f, 1.0023f));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[49].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[49].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[49].transform.translate(glm::vec3(-1.73391, 0.0f, -0.996781f));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[50].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[50].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[50].transform.translate(glm::vec3(-0.00477693f, 0.0f, -1.99999f));

    renderer.meshes.push_back(FileMesh("./assets/Models/single_column/singl_column_model.obj",
                                       Transform(), {{(0.956863f)}, {0.643137f}, {0.376471f}, {(1.0F)}}, "./assets/Models/single_column/single_column.jpg"));
    renderer.meshes[51].transform.setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    renderer.meshes[51].transform.translate(glm::vec3(-9.2f, 1.4f, -9.0f));
    renderer.meshes[51].transform.translate(glm::vec3(1.72912f, 0.0f, -1.00505f));

    // Roof

    renderer.meshes.push_back(Cylinder(4.8f, 4.8f, 1.0f, 10, 1, Color::White, "./assets/metalbox.png"));
    renderer.meshes[52].transform.rotate(glm::vec3(1.0, 0.0, 0.0), 90.f);
    renderer.meshes[52].transform.setPosition(glm::vec3(-9.2f, 5.4f, -9.0f));

    renderer.meshes.push_back(Cylinder(2.0f, 4.0f, 1.0f, 10, 1, Color::White, "./assets/metalbox_1.png"));
    renderer.meshes[53].transform.rotate(glm::vec3(1.0, 0.0, 0.0), 90.f);
    renderer.meshes[53].transform.setPosition(glm::vec3(-9.2f, 6.4f, -9.0f));

    renderer.meshes.push_back(Cylinder(2.0f, 2.0f, 1.5f, 6, 1, Color::White, "./assets/under_dome.jpg"));
    renderer.meshes[54].transform.rotate(glm::vec3(1.0, 0.0, 0.0), 90.f);
    renderer.meshes[54].transform.setPosition(glm::vec3(-9.2f, 7.64f, -9.0f));

    renderer.meshes.push_back(Cylinder(2.2f, 2.2f, 0.15f, 6, 1, Color::Orange, "./assets/metalbox_1.png"));
    renderer.meshes[55].transform.rotate(glm::vec3(1.0, 0.0, 0.0), 90.f);
    renderer.meshes[55].transform.setPosition(glm::vec3(-9.2f, 8.5f, -9.0f));

    renderer.meshes.push_back(Sphere(2.0F, 50, 150, Color::Grey, 1, "./assets/Dome_Silver.jpg"));
    renderer.meshes[56].transform.setPosition(glm::vec3(-9.2f, 8.6f, -9.0f));
    renderer.meshes[56].transform.setScale(glm::vec3(1.0f, 1.4f, 1.0f));

    renderer.meshes.push_back(Cylinder(0.01f, 0.01f, 0.7f, 10, 10, Color::Grey, "./assets/metal.png"));
    renderer.meshes[57].transform.rotate(glm::vec3(1, 0, 0), 90.f);
    renderer.meshes[57].transform.setPosition(glm::vec3(-9.2f, 11.7f, -9.0f));

    renderer.meshes.push_back(CrescentMoon("./assets/Dome_Silver.jpg"));
    renderer.meshes[58].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[58].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[58].transform.setPosition(glm::vec3(-9.2f, 12.2f, -8.925f));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //        Dome of the chain Parts End
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //            Fence
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // West
    renderer.meshes.push_back(Fence(Color::White, "./assets/wall_1_.jpg"));
    renderer.meshes[59].transform.translate(glm::vec3(74.4f, 1.5f, 0.0f));
    renderer.meshes[59].transform.scale(glm::vec3(0.2f, 5.0f, cubeScaleW));
    // East
    renderer.meshes.push_back(Fence(Color::White, "./assets/wall_1_.jpg"));
    renderer.meshes[60].transform.scale(glm::vec3(0.2f, 5.0f, 45));
    renderer.meshes[60].transform.translate(glm::vec3(-74.4f, 1.5f, -28.0f));
    // North
    renderer.meshes.push_back(Fence(Color::White, "./assets/wall_1_.jpg"));
    renderer.meshes[61].transform.translate(glm::vec3(0.0f, 1.5f, 49.9f));
    renderer.meshes[61].transform.scale(glm::vec3(cubeScaleH, 5.0f, 0.2f));
    // South
    renderer.meshes.push_back(Fence(Color::White, "./assets/wall_1_.jpg"));
    renderer.meshes[62].transform.translate(glm::vec3(0.0f, 1.5f, -49.9f));
    renderer.meshes[62].transform.scale(glm::vec3(cubeScaleH, 5.0f, 0.2f));

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // Stairs
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    // Stairs 1
    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[63].transform.translate(glm::vec3(((hight + 1.5) * (1.5f / 4.0f)), 0.0f, 0.2f));
    renderer.meshes[63].transform.scale(glm::vec3(-0.1f, -0.6f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[64].transform.translate(glm::vec3(((hight + 1.5) * (1.5f / 4.0f)) - 0.5f, 0.0f, 0.2f));
    renderer.meshes[64].transform.scale(glm::vec3(-0.1f, -0.3f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[65].transform.translate(glm::vec3(((hight + 1.5) * (1.5f / 4.0f)) - 1.0f, 0.0f, 0.2f));
    renderer.meshes[65].transform.scale(glm::vec3(-0.1f, 0.0f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[66].transform.translate(glm::vec3(((hight + 1.5) * (1.5f / 4.0f)) - 1.5f, 0.0f, 0.2f));
    renderer.meshes[66].transform.scale(glm::vec3(-0.1f, 0.3f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[67].transform.translate(glm::vec3(((hight + 1.5) * (1.5f / 4.0f)) - 2.0f, 0.0f, 0.2f));
    renderer.meshes[67].transform.scale(glm::vec3(-0.1f, 0.6f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[68].transform.translate(glm::vec3(((hight + 1.5) * (1.5f / 4.0f)) - 2.5f, 0.0f, 0.2f));
    renderer.meshes[68].transform.scale(glm::vec3(-0.1f, 1.0f, 2.0f));
    // Stairs 2
    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[69].transform.translate(glm::vec3(-(hight + 1.5) * (1.5f / 4.0f), 0.0f, 0.2f));
    renderer.meshes[69].transform.scale(glm::vec3(-0.1f, -0.6f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[70].transform.translate(glm::vec3(-((hight + 1.5) * (1.5f / 4.0f) - 0.5f), 0.0f, 0.2f));
    renderer.meshes[70].transform.scale(glm::vec3(-0.1f, -0.3f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[71].transform.translate(glm::vec3(-((hight + 1.5) * (1.5f / 4.0f) - 1.0f), 0.0f, 0.2f));
    renderer.meshes[71].transform.scale(glm::vec3(-0.1f, 0.0f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[72].transform.translate(glm::vec3(-((hight + 1.5) * (1.5f / 4.0f) - 1.5f), 0.0f, 0.2f));
    renderer.meshes[72].transform.scale(glm::vec3(-0.1f, 0.3f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[73].transform.translate(glm::vec3(-((hight + 1.5) * (1.5f / 4.0f) - 2.0f), 0.0f, 0.2f));
    renderer.meshes[73].transform.scale(glm::vec3(-0.1f, 0.6f, 2.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[74].transform.translate(glm::vec3(-((hight + 1.5) * (1.5f / 4.0f) - 2.5f), 0.0f, 0.2f));
    renderer.meshes[74].transform.scale(glm::vec3(-0.1f, 1.0f, 2.0f));
    // Stairs 3
    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[75].transform.translate(glm::vec3(0.2f, 0.0f, -((width + 7) / 2.0f)));
    renderer.meshes[75].transform.scale(glm::vec3(2.0f, -0.6f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[76].transform.translate(glm::vec3(0.2f, 0.0f, -(((width + 7) / 2.0f) - 0.5f)));
    renderer.meshes[76].transform.scale(glm::vec3(2.0f, -0.3f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[77].transform.translate(glm::vec3(0.2f, 0.0f, -(((width + 7) / 2.0f) - 1.0f)));
    renderer.meshes[77].transform.scale(glm::vec3(2.0f, 0.0f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[78].transform.translate(glm::vec3(0.2f, 0.0f, -(((width + 7) / 2.0f) - 1.5f)));
    renderer.meshes[78].transform.scale(glm::vec3(2.0f, 0.3f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[79].transform.translate(glm::vec3(0.2f, 0.0f, -(((width + 7) / 2.0f) - 2.0f)));
    renderer.meshes[79].transform.scale(glm::vec3(2.0f, 0.6f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[80].transform.translate(glm::vec3(0.2f, 0.0f, -(((width + 7) / 2.0f) - 2.5f)));
    renderer.meshes[80].transform.scale(glm::vec3(2.0f, 1.0f, -0.1f));

    //  stairs 4
    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[81].transform.translate(glm::vec3(0.2f, 0.0f, ((width + 7) / 2.0f)));
    renderer.meshes[81].transform.scale(glm::vec3(2.0f, -0.6f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[82].transform.translate(glm::vec3(0.2f, 0.0f, ((width + 7) / 2.0f) - 0.5f));
    renderer.meshes[82].transform.scale(glm::vec3(2.0f, -0.3f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[83].transform.translate(glm::vec3(0.2f, 0.0f, ((width + 7) / 2.0f) - 1.0f));
    renderer.meshes[83].transform.scale(glm::vec3(2.0f, 0.0f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[84].transform.translate(glm::vec3(0.2f, 0.0f, ((width + 7) / 2.0f) - 1.5f));
    renderer.meshes[84].transform.scale(glm::vec3(2.0f, 0.3f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[85].transform.translate(glm::vec3(0.2f, 0.0f, ((width + 7) / 2.0f) - 2.0f));
    renderer.meshes[85].transform.scale(glm::vec3(2.0f, 0.6f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[86].transform.translate(glm::vec3(0.2f, 0.0f, ((width + 7) / 2.0f) - 2.5f));
    renderer.meshes[86].transform.scale(glm::vec3(2.0f, 1.0f, -0.1f));

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // Doors
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // west
    renderer.meshes.push_back(TexturedQuad("./assets/door.png"));
    renderer.meshes[87].transform.rotate(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);
    renderer.meshes[87].transform.translate(glm::vec3(0.0f, 1.5f, hight - 0.65f));
    renderer.meshes[87].transform.scale(glm::vec3(1.2f, 1.75f, 50.0f));
    // East
    renderer.meshes.push_back(TexturedQuad("./assets/door.png"));
    renderer.meshes[88].transform.translate(glm::vec3(-76, 1.5f, -4.9f));
    renderer.meshes[88].transform.scale(glm::vec3(1.2f, 2.5f, 50.0f));
    // North
    renderer.meshes.push_back(TexturedQuad("./assets/door.png"));
    renderer.meshes[89].transform.translate(glm::vec3(0.0f, 1.1f, width - 0.65f));
    renderer.meshes[89].transform.scale(glm::vec3(1.2f, 1.75f, 50.0f));
    // South
    renderer.meshes.push_back(TexturedQuad("./assets/door.png"));
    renderer.meshes[90].transform.translate(glm::vec3(0.0f, 1.1f, -(width - 0.65f)));
    renderer.meshes[90].transform.scale(glm::vec3(1.2f, 2.5f, 50.0f));
    // South door
    renderer.meshes.push_back(Floor(Color::White, "./assets/wall_1_.jpg"));
    renderer.meshes[91].transform.scale(glm::vec3(0.2f, 5.0f, 45));
    renderer.meshes[91].transform.translate(glm::vec3(-74.4f, 1.5f, 28.0f));

    renderer.meshes.push_back(TexturedQuad("./assets/door.png"));
    renderer.meshes[92].transform.translate(glm::vec3(-76, 1.5f, 4.9f));
    renderer.meshes[92].transform.scale(glm::vec3(1.2f, 2.5f, 50.0f));


    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //                      buraq wall
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // buraq wall
    renderer.meshes.push_back(
        Cube(Color::White, "./assets/buraq_wall.jpg"));
    renderer.meshes[93].transform.translate(glm::vec3(22.0f, 3.0f, 50.0f));
    renderer.meshes[93].transform.scale(glm::vec3(1.0f, 6.0f, 15.0f));
    renderer.meshes[93].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/buraq_wall.jpg"));
    renderer.meshes[94].transform.translate(glm::vec3(15.0f, 3.0f, 53.0f));
    renderer.meshes[94].transform.scale(glm::vec3(1.0f, 6.0f, 9.0f));

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/buraq_wall.jpg"));
    renderer.meshes[95].transform.translate(glm::vec3(30.0f, 3.0f, 53.0f));
    renderer.meshes[95].transform.scale(glm::vec3(1.0f, 6.0f, 9.0f));

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    // qibli mosque
    // side
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/Teppich.png"));
    renderer.meshes[96].transform.translate(glm::vec3(75.0f, 0.1f, 20.0f));
    renderer.meshes[96].transform.scale(glm::vec3(4.0f, 1.5f, 1.0f));
    renderer.meshes[96].transform.rotate(glm::vec3(1, 0, 0), 90.0f);
    renderer.meshes[96].transform.rotate(glm::vec3(0, 0, 1), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli10.jpg"));
    renderer.meshes[97].transform.translate(glm::vec3(65.0f, 0.0f, 48.0f));
    renderer.meshes[97].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli2.jpg"));
    renderer.meshes[98].transform.translate(glm::vec3(54.0f, 0.0f, 20.0f));
    renderer.meshes[98].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[99].transform.translate(glm::vec3(48.0f, 0.0f, 20.0f));
    renderer.meshes[99].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[100].transform.translate(glm::vec3(42.0f, 0.0f, 20.0f));
    renderer.meshes[100].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[101].transform.translate(glm::vec3(38.0f, 0.0f, 20.0f));
    renderer.meshes[101].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    // front
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli6.jpg"));
    renderer.meshes[102].transform.translate(glm::vec3(38.0f, 0.0f, 20.0f));
    renderer.meshes[102].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));
    renderer.meshes[102].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli5.jpg"));
    renderer.meshes[103].transform.translate(glm::vec3(38.0f, 0.0f, 14.0f));
    renderer.meshes[103].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));
    renderer.meshes[103].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli6.jpg"));
    renderer.meshes[104].transform.translate(glm::vec3(38.0f, 0.0f, 8.0f));
    renderer.meshes[104].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));
    renderer.meshes[104].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    // side
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli4.jpg"));
    renderer.meshes[105].transform.translate(glm::vec3(66.0f, 0.0f, 2.0f));
    renderer.meshes[105].transform.scale(glm::vec3(0.5f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli7.jpg"));
    renderer.meshes[106].transform.translate(glm::vec3(60.0f, 0.0f, 2.0f));
    renderer.meshes[106].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli2.jpg"));
    renderer.meshes[107].transform.translate(glm::vec3(54.0f, 0.0f, 2.0f));
    renderer.meshes[107].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[108].transform.translate(glm::vec3(48.0f, 0.0f, 2.0f));
    renderer.meshes[108].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[109].transform.translate(glm::vec3(42.0f, 0.0f, 2.0f));
    renderer.meshes[109].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[110].transform.translate(glm::vec3(38.0f, 0.0f, 2.0f));
    renderer.meshes[110].transform.scale(glm::vec3(0.0f, -0.2f, 5.0f));

    // top
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg", {glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)}));
    renderer.meshes[111].transform.translate(glm::vec3(38.0f, 4.5f, 2.0f));
    renderer.meshes[111].transform.scale(glm::vec3(5.0f, 2.0f, 5.0f));
    renderer.meshes[111].transform.rotate(glm::vec3(1, 0, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[112].transform.translate(glm::vec3(40.0f, 4.5f, 14.0f));
    renderer.meshes[112].transform.scale(glm::vec3(0.0f, -0.7f, 0.0f));
    renderer.meshes[112].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg", {glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)}));
    renderer.meshes[113].transform.translate(glm::vec3(40.0f, 4.5f, 14.0f));
    renderer.meshes[113].transform.scale(glm::vec3(3.0f, -0.7f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[114].transform.translate(glm::vec3(40.0f, 4.5f, 8.0f));
    renderer.meshes[114].transform.scale(glm::vec3(3.0f, -0.7f, 5.0f));

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/marble.jpg"));
    renderer.meshes[115].transform.translate(glm::vec3(64.0f, 0.0f, 20.0f));
    renderer.meshes[115].transform.scale(glm::vec3(2.0f, 0.0f, 1.5f));
    renderer.meshes[115].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Sphere(2.0F, 50, 150, Color::White, 1, "./assets/metalbox.png"));
    renderer.meshes[116].transform.translate(glm::vec3(69.0f, 5.0f, 12.0f));
    renderer.meshes[116].transform.scale(glm::vec3(0.0f, 0.0f, 0.0f));

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // المئذنة الفخرية
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg", {glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)}));
    renderer.meshes[117].transform.translate(glm::vec3(60.0f, 0.0f, 47.0f));
    renderer.meshes[117].transform.scale(glm::vec3(2.0f, -0.2f, 25.0f));
    renderer.meshes[117].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg", {glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)}));
    renderer.meshes[118].transform.translate(glm::vec3(60.0f, 0.0f, 32.0f));
    renderer.meshes[118].transform.scale(glm::vec3(0.0f, -0.2f, 10.0f));
    renderer.meshes[118].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg", {glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)}));
    renderer.meshes[119].transform.translate(glm::vec3(60.0f, 0.0f, 26.0f));
    renderer.meshes[119].transform.scale(glm::vec3(0.0f, -0.2f, 10.0f));
    renderer.meshes[119].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    // top
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[120].transform.translate(glm::vec3(75.0f, 4.5f, 20.0f));
    renderer.meshes[120].transform.scale(glm::vec3(4.0f, 1.5f, 3.0f));
    renderer.meshes[120].transform.rotate(glm::vec3(1, 0, 0), 90.0f);
    renderer.meshes[120].transform.rotate(glm::vec3(0, 0, 1), 90.0f);

    ///

    renderer.meshes.push_back(Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[121].transform.translate(glm::vec3(60.0f, 0.0f, 40.0f));
    renderer.meshes[121].transform.scale(glm::vec3(-30.0f, -4.0f, -4.0f));
    renderer.meshes[121].transform.rotate(glm::vec3(0, 0, 1), -90.0f);

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[122].transform.translate(glm::vec3(58.0f, 21.0f, 47.5f));
    renderer.meshes[122].transform.scale(glm::vec3(1.5f, 0.0f, -0.5f));
    renderer.meshes[122].transform.rotate(glm::vec3(0, 1, 0), 90.0f);
    renderer.meshes[122].transform.rotate(glm::vec3(1, 0, 0), 180.0f);

    renderer.meshes.push_back(Sphere(1.0F, 50, 150, Color::White, 1, "./assets/metalbox.png"));
    renderer.meshes[123].transform.translate(glm::vec3(60.0f, 20.0f, 40.0f));
    renderer.meshes[123].transform.scale(glm::vec3(0.1f, 0.1f, 0.1f)); // Adjust the scale to make it smaller

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    // musium
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/musium2.jpg", {glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)}));
    renderer.meshes[124].transform.translate(glm::vec3(60.0f, 0.0f, 38.0f));
    renderer.meshes[124].transform.scale(glm::vec3(0.0f, -0.2f, 10.0f));
    renderer.meshes[124].transform.rotate(glm::vec3(0, 1, 0), 180.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/musium2.jpg"));
    renderer.meshes[125].transform.translate(glm::vec3(54.0f, 0.0f, 38.0f));
    renderer.meshes[125].transform.scale(glm::vec3(0.0f, -0.2f, 10.0f));
    renderer.meshes[125].transform.rotate(glm::vec3(0, 1, 0), 180.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/musium.jpg"));
    renderer.meshes[126].transform.translate(glm::vec3(48.0f, 0.0f, 38.0f));
    renderer.meshes[126].transform.scale(glm::vec3(0.0f, -0.2f, 10.0f));
    renderer.meshes[126].transform.rotate(glm::vec3(0, 1, 0), 180.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/musium3.jpg"));
    renderer.meshes[127].transform.translate(glm::vec3(42.0f, 0.0f, 38.0f));
    renderer.meshes[127].transform.scale(glm::vec3(0.0f, -0.2f, 10.0f));
    renderer.meshes[127].transform.rotate(glm::vec3(0, 1, 0), 180.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[128].transform.translate(glm::vec3(36.0f, 4.5f, 38.0f));
    renderer.meshes[128].transform.scale(glm::vec3(4.5f, 1.0f, -5.2f));
    renderer.meshes[128].transform.rotate(glm::vec3(1, 0, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[129].transform.translate(glm::vec3(36.0f, 0.0f, 50.0f));
    renderer.meshes[129].transform.scale(glm::vec3(1.0f, -0.2f, 10.0f));
    renderer.meshes[129].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Sphere(2.2F, 50, 150, Color::DarkBlue, 1, "./assets/metalbox.png"));
    renderer.meshes[130].transform.translate(glm::vec3(45.0f, 4.5f, 42.0f));
    renderer.meshes[130].transform.scale(glm::vec3(0.1f, 0.1f, 0.1f));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // maruani mosque
    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[131].transform.translate(glm::vec3(68.0f, 0.0f, -38.0f));
    renderer.meshes[131].transform.scale(glm::vec3(10.0f, 7.0f, 20.0f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[132].transform.translate(glm::vec3(60.0f, 0.0f, -29.0f));
    renderer.meshes[132].transform.scale(glm::vec3(3.0f, -0.6f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[133].transform.translate(glm::vec3(60.0f, 0.0f, -28.5f));
    renderer.meshes[133].transform.scale(glm::vec3(3.0f, -0.3f, -0.1f));

    renderer.meshes.push_back(Cube(Color::SaddleBrown, "./assets/floor.jpg"));
    renderer.meshes[134].transform.translate(glm::vec3(60.0f, 0.0f, -28.0f));
    renderer.meshes[134].transform.scale(glm::vec3(3.0f, 0.0f, -0.1f));

    // crescent moon
    /// على الكب
    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[135].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[135].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[135].transform.setPosition(glm::vec3(69.0f, 7.5f, 12.0f));
    /// على الكب
    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[136].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[136].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[136].transform.setPosition(glm::vec3(69.0f, 7.5f, 12.0f));

    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[137].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[137].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[137].transform.setPosition(glm::vec3(45.0f, 7.0f, 42.0f));

    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[138].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[138].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[138].transform.setPosition(glm::vec3(60.0f, 21.5f, 40.0f));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    // sabil qitibai
    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qitibai.jpg"));
    renderer.meshes[139].transform.translate(glm::vec3(-10.0f, 2.0f, 35.0f));
    renderer.meshes[139].transform.scale(glm::vec3(3.0f, 4.0f, 3.0f));
    renderer.meshes[139].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cylinder(1.75f, 1.75f, 3.2f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[140].transform.translate(glm::vec3(-10.0f, 4.5f, 35.0f));
    renderer.meshes[140].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(Sphere(2.0F, 50, 150, Color::White, 1, "./assets/ornament.jpg"));
    renderer.meshes[141].transform.translate(glm::vec3(-10.0f, 5.0f, 35.0f));
    renderer.meshes[141].transform.scale(glm::vec3(0.0f, 0.0f, 0.0f));

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // qibli decoration
    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/Teppich.png"));
    renderer.meshes[142].transform.translate(glm::vec3(38.0f, 0.1f, 2.0f));
    renderer.meshes[142].transform.scale(glm::vec3(5.0f, 2.0f, 5.0f));
    renderer.meshes[142].transform.rotate(glm::vec3(1, 0, 0), 90.0f);

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/qibli8.jpg"));
    renderer.meshes[143].transform.translate(glm::vec3(73.0f, -0.4f, 15.0f));
    renderer.meshes[143].transform.scale(glm::vec3(0.5f, -0.2f, 5.0f));
    renderer.meshes[143].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[144].transform.translate(glm::vec3(65.0f, 0.0f, 29.0f));
    renderer.meshes[144].transform.rotate(glm::vec3(1, 0, 0), -90.f);


    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[145].transform.translate(glm::vec3(70.0f, 0.0f, 29.0f));
    renderer.meshes[145].transform.rotate(glm::vec3(1, 0, 0), -90.f);


    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[146].transform.translate(glm::vec3(65.0f, 0.0f, 14.0f));
    renderer.meshes[146].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[147].transform.translate(glm::vec3(55.0f, 0.0f, 14.0f));
    renderer.meshes[147].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[148].transform.translate(glm::vec3(65.0f, 0.0f, 8.0f));
    renderer.meshes[148].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[149].transform.translate(glm::vec3(55.0f, 0.0f, 8.0f));
    renderer.meshes[149].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[150].transform.translate(glm::vec3(45.0f, 0.0f, 14.0f));
    renderer.meshes[150].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(Cylinder(0.5f, 0.5f, 8.5f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[151].transform.translate(glm::vec3(45.0f, 0.0f, 8.0f));
    renderer.meshes[151].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    renderer.meshes.push_back(qibliCuboid(Color::White, "./assets/fence.jpg"));
    renderer.meshes[152].transform.translate(glm::vec3(38.0f, 4.2f, 2.0f));
    renderer.meshes[152].transform.scale(glm::vec3(5.0f, 2.0f, 5.0f));
    renderer.meshes[152].transform.rotate(glm::vec3(1, 0, 0), 90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/floor.jpg"));
    renderer.meshes[153].transform.translate(glm::vec3(50.0f, 0.0f, 29.0f));
    renderer.meshes[153].transform.scale(glm::vec3(3.0f, 3.0f, 3.0f));
    renderer.meshes[153].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Sphere(1.5F, 25, 75, Color::DarkBlue, 1, "./assets/ornament.jpg"));
    renderer.meshes[154].transform.translate(glm::vec3(50.0f, 1.5f, 29.0f));
    renderer.meshes[154].transform.scale(glm::vec3(0.0f, 0.0f, 0.0f));

    /////////////////////////////////////////////////////////////////////////////////////////

    // tankzieh school + hussain  dareeh
    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[155].transform.translate(glm::vec3(-18.0f, 0.0f, 45.0f));
    renderer.meshes[155].transform.scale(glm::vec3(5.0f, 7.0f, 50.0f));
    renderer.meshes[155].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[156].transform.translate(glm::vec3(-12.0f, 0.0f, 45.0f));
    renderer.meshes[156].transform.scale(glm::vec3(-30.0f, -4.0f, -4.0f));
    renderer.meshes[156].transform.rotate(glm::vec3(0, 0, 1), -90.0f);

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/marble.jpg"));
    renderer.meshes[157].transform.translate(glm::vec3(-18.0f, 8.2f, 48.0f));
    renderer.meshes[157].transform.scale(glm::vec3(1.0f, 0.0f, -0.5f));

    renderer.meshes.push_back(Sphere(1.0F, 50, 150, Color::White, 1, "./assets/metalbox.png"));
    renderer.meshes[158].transform.translate(glm::vec3(-12.0f, 15.0f, 45.0f));
    renderer.meshes[158].transform.scale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[159].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[159].transform.translate(glm::vec3(65.0f, 0.0f, -10.0f));

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[160].transform.translate(glm::vec3(-22.0f, 5.0f, 45.0f));
    renderer.meshes[160].transform.scale(glm::vec3(2.0f, 2.0f, 6.0f));
    renderer.meshes[160].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //dar alkhatabeh

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[161].transform.translate(glm::vec3(80.0f, 0.0f, -7.0f));
    renderer.meshes[161].transform.scale(glm::vec3(10.0f, 12.0f, 10.0f));

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[162].transform.translate(glm::vec3(80.0f, 0.0f, -2.0f));
    renderer.meshes[162].transform.scale(glm::vec3(10.0f, 10.0f, 10.0f));

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[163].transform.translate(glm::vec3(80.0f, 0.0f, -7.0f));
    renderer.meshes[163].transform.scale(glm::vec3(5.0f, 15.0f, 7.0f));

    renderer.meshes.push_back(Cylinder(2.0f, 2.0f, 1.2f, 50, 50, Color::White, "./assets/under_dome.jpg"));
    renderer.meshes[164].transform.translate(glm::vec3(69.0f, 5.0f, 12.0f));
    renderer.meshes[164].transform.rotate(glm::vec3(1, 0, 0), -90.f);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
   
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ghoanimah minaret

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[165].transform.translate(glm::vec3(-68.0f, 0.0f, 38.0f));
    renderer.meshes[165].transform.scale(glm::vec3(10.0f, 9.0f, 20.0f));

    renderer.meshes.push_back(Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[166].transform.translate(glm::vec3(-68.0f, 0.0f, 38.0f));
    renderer.meshes[166].transform.scale(glm::vec3(-30.0f, -4.0f, -4.0f));
    renderer.meshes[166].transform.rotate(glm::vec3(0, 0, 1), -90.0f);

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/marble.jpg"));
    renderer.meshes[167].transform.translate(glm::vec3(-65.0f, 8.0f, 45.5f));
    renderer.meshes[167].transform.scale(glm::vec3(1.5f, 0.0f, -0.5f));
    renderer.meshes[167].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cylinder(1.5f, 1.5f, 4.0f, 10, 10, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[168].transform.rotate(glm::vec3(1, 0, 0), 90.f);
    renderer.meshes[168].transform.setPosition(glm::vec3(-68.0f, 15.0f, 38.0f));

    renderer.meshes.push_back(Sphere(1.0F, 50, 150, Color::White, 1, "./assets/metalbox.png"));
    renderer.meshes[169].transform.translate(glm::vec3(-68.0f, 17.0f, 38.0f));
    renderer.meshes[169].transform.scale(glm::vec3(0.1f, 0.1f, 0.1f));

    renderer.meshes.push_back(TexturedQuad("./assets/door2.jpg"));
    renderer.meshes[170].transform.translate(glm::vec3(-62.2f, 1.0f, 38.0f));
    renderer.meshes[170].transform.scale(glm::vec3(1.2f, 2.5f, 50.0f));
    renderer.meshes[170].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[171].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[171].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[171].transform.setPosition(glm::vec3(-68.0f, 18.5f, 38.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[172].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[172].transform.translate(glm::vec3(-60.0f, 0.0f, 45.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[173].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[173].transform.translate(glm::vec3(-60.0f, 0.0f, 30.0f));

    renderer.meshes.push_back(Sphere(2.9F, 50, 150, Color::Grey, 1, "./assets/metalbox.png"));
    renderer.meshes[174].transform.setPosition(glm::vec3(-32.0f, 4.0f, 45.0f));
    renderer.meshes[174].transform.setScale(glm::vec3(1.0f, 1.4f, 1.0f));

    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[175].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[175].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[175].transform.setPosition(glm::vec3(-32.0f, 8.5f, 45.0f));

    renderer.meshes.push_back(CrescentMoon("./assets/Gold.png"));
    renderer.meshes[176].transform.setScale(glm::vec3(0.001f, 0.001f, 0.001f));
    renderer.meshes[176].transform.rotate(glm::vec3(0, 0, 1), -270.f);
    renderer.meshes[176].transform.setPosition(glm::vec3(-12.0f, 16.0f, 45.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[177].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[177].transform.translate(glm::vec3(-35.0f, 0.0f, 38.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[178].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[178].transform.translate(glm::vec3(-47.0f, 0.0f, 45.0f));
    ///////////////////////////////////////////////////////////////////////////////
    //           *******     fix minaret
    ///////////////////////////////////////////////////////////////////////////////
    renderer.meshes.push_back(Cylinder(1.5f, 1.5f, 6.5f, 10, 10, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[179].transform.rotate(glm::vec3(1, 0, 0), 90.f);
    renderer.meshes[179].transform.setPosition(glm::vec3(60.0f, 17.0f, 40.0f));

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/marble.jpg"));
    renderer.meshes[180].transform.translate(glm::vec3(63.0f, 11.0f, 47.5f));
    renderer.meshes[180].transform.scale(glm::vec3(1.5f, 0.0f, -0.5f));
    renderer.meshes[180].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cylinder(0.1f, 0.1f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[181].transform.translate(glm::vec3(58.5f, 16.0f, 38.5f));
    renderer.meshes[181].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cylinder(0.1f, 0.1f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[182].transform.translate(glm::vec3(58.5f, 16.0f, 41.5f));
    renderer.meshes[182].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cylinder(0.1f, 0.1f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[183].transform.translate(glm::vec3(62.0f, 16.0f, 38.5f));
    renderer.meshes[183].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cylinder(0.1f, 0.1f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[184].transform.translate(glm::vec3(62.0f, 16.0f, 41.5f));
    renderer.meshes[184].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/qibli.jpg"));
    renderer.meshes[185].transform.translate(glm::vec3(60.0f, 15.0f, 40.0f));
    renderer.meshes[185].transform.scale(glm::vec3(0.0f, 3.0f, 3.0f));
    renderer.meshes[185].transform.rotate(glm::vec3(0, 0, 1), -90.0f);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              sabil sulaiman
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[186].transform.translate(glm::vec3(-68.0f, 0.0f, 18.0f));
    renderer.meshes[186].transform.scale(glm::vec3(2.0f, 11.0f, 5.0f));

    renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/asbat.jpg"));
    renderer.meshes[187].transform.translate(glm::vec3(-66.3f, 0.0f, 21.0f));
    renderer.meshes[187].transform.scale(glm::vec3(0.0f, 0.0f, 0.0f));
    renderer.meshes[187].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    // Bab al-Rahma Cemetery

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[188].transform.translate(glm::vec3(-24.0f, 2.0f, -40.0f));
    renderer.meshes[188].transform.scale(glm::vec3(2.0f, 11.0f, 5.0f));
    renderer.meshes[188].transform.rotate(glm::vec3(0, 0, 1), 90.0f);
    renderer.meshes[188].transform.rotate(glm::vec3(1, 0, 0), 90.0f);

    renderer.meshes.push_back(Sphere(2.0F, 50, 150, Color::White, 1, "./assets/metalbox.png"));
    renderer.meshes[189].transform.translate(glm::vec3(-24.0f, 3.0f, -40.0f));
    renderer.meshes[189].transform.scale(glm::vec3(0.1f, 0.1f, 0.1f));

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                        asbat manaret
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    renderer.meshes.push_back(Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[190].transform.translate(glm::vec3(-74.0f, 0.0f, -25.0f));
    renderer.meshes[190].transform.scale(glm::vec3(-30.0f, -4.0f, -4.0f));
    renderer.meshes[190].transform.rotate(glm::vec3(0, 0, 1), -90.0f);

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/marble.jpg"));
    renderer.meshes[191].transform.translate(glm::vec3(-71.0f, 8.0f, -17.5f));
    renderer.meshes[191].transform.scale(glm::vec3(1.5f, 0.0f, -0.5f));
    renderer.meshes[191].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cylinder(1.5f, 1.5f, 4.0f, 10, 10, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[192].transform.rotate(glm::vec3(1, 0, 0), 90.f);
    renderer.meshes[192].transform.setPosition(glm::vec3(-74.0f, 15.0f, -25.0f));

    renderer.meshes.push_back(Sphere(1.0F, 50, 150, Color::White, 1, "./assets/metalbox.png"));
    renderer.meshes[193].transform.translate(glm::vec3(-74.0f, 17.0f, -25.0f));
    renderer.meshes[193].transform.scale(glm::vec3(0.1f, 0.1f, 0.1f));

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              grass
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // المدخل
    renderer.meshes.push_back(
        Grass(Color::White, "./assets/cobble.png"));
    renderer.meshes[194].transform.translate(glm::vec3(-60.0f, -0.4f, 0.5f));
    renderer.meshes[194].transform.scale(glm::vec3(28.0f, 0.2f, 5.0f));
    //
    // grass_1
    renderer.meshes.push_back(Cube(Color::White, "./assets/grass_1.jpg"));
    renderer.meshes[195].transform.translate(glm::vec3(-35.0f, 0.0f, -26.0f));
    renderer.meshes[195].transform.scale(glm::vec3(15.0f, -0.8f, 10.5f));
    renderer.meshes[195].transform.rotate(glm::vec3(0, 1, 0), -90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/grass_1.jpg"));
    renderer.meshes[196].transform.translate(glm::vec3(-35.0f, 0.0f, -5.0f));
    renderer.meshes[196].transform.scale(glm::vec3(15.0f, -0.8f, 10.5f));
    renderer.meshes[196].transform.rotate(glm::vec3(0, 1, 0), -90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/grass_1.jpg"));
    renderer.meshes[197].transform.translate(glm::vec3(20.3f, 0.0f, -36.0f));
    renderer.meshes[197].transform.scale(glm::vec3(20.2f, -0.8f, 10.5f));

    renderer.meshes.push_back(Cube(Color::White, "./assets/grass_1.jpg"));
    renderer.meshes[198].transform.translate(glm::vec3(35.0f, 0.0f, -20.0f));
    renderer.meshes[198].transform.scale(glm::vec3(15.0f, -0.8f, 10.5f));
    renderer.meshes[198].transform.rotate(glm::vec3(0, 1, 0), -90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/grass_1.jpg"));
    renderer.meshes[199].transform.translate(glm::vec3(-35.0f, 0.0f, 20.0f));
    renderer.meshes[199].transform.scale(glm::vec3(15.0f, -0.8f, 10.5f));
    renderer.meshes[199].transform.rotate(glm::vec3(0, 1, 0), -90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/grass_1.jpg"));
    renderer.meshes[200].transform.translate(glm::vec3(-5.3f, 0.0f, -36.0f));
    renderer.meshes[200].transform.scale(glm::vec3(20.2f, -0.8f, 10.5f));
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                              trees
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[201].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[201].transform.translate(glm::vec3(15.0f, 0.0f, 35.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[202].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[202].transform.translate(glm::vec3(22.0f, 0.0f, 40.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[203].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[203].transform.translate(glm::vec3(20.0f, 0.0f, 35.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[204].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[204].transform.translate(glm::vec3(-35.0f, 0.7f, -28.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[205].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[205].transform.translate(glm::vec3(-35.0f, 0.7f, -20.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[206].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[206].transform.translate(glm::vec3(-35.0f, 0.7f, -10.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[207].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[207].transform.translate(glm::vec3(-35.0f, 0.7f, 0.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[208].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[208].transform.translate(glm::vec3(-35.0f, 0.7f, 21.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[209].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[209].transform.translate(glm::vec3(-35.0f, 0.7f, 16.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[210].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[210].transform.translate(glm::vec3(22.3f, 0.7f, -36.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[211].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[211].transform.translate(glm::vec3(14.3f, 0.7f, -36.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[212].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[212].transform.translate(glm::vec3(-8.3f, 0.7f, -36.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[213].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[213].transform.translate(glm::vec3(0.3f, 0.7f, -36.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[214].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[214].transform.translate(glm::vec3(-70.0f, 0.0f, -45.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[215].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[215].transform.translate(glm::vec3(-65.0f, 0.0f, -40.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[216].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[216].transform.translate(glm::vec3(-69.0f, 0.0f, -39.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[217].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[217].transform.translate(glm::vec3(40.0f, 0.0f, 28.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[218].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[218].transform.translate(glm::vec3(40.0f, 0.0f, 25.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[219].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[219].transform.translate(glm::vec3(35.0f, 0.0f, 28.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[220].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[220].transform.translate(glm::vec3(40.0f, 0.0f, -28.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[221].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[221].transform.translate(glm::vec3(40.0f, 0.0f, -25.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[222].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[222].transform.translate(glm::vec3(35.0f, 0.0f, -28.0f));

    ///////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    // flowers

    renderer.meshes.push_back(qibliPrism(Color::White, "./assets/marble.jpg"));
    renderer.meshes[223].transform.translate(glm::vec3(7.0f, -2.3f, 58.0f));
    renderer.meshes[223].transform.scale(glm::vec3(3.0f, 0.0f, 4.0f));
    renderer.meshes[223].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/flowers3.png"));
    renderer.meshes[224].transform.translate(glm::vec3(-50.0f, 0.0f, -25.0f));
    renderer.meshes[224].transform.scale(glm::vec3(25.0f, -0.8f, 15.5f));
    renderer.meshes[224].transform.rotate(glm::vec3(0, 1, 0), -90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/flowers3.png"));
    renderer.meshes[225].transform.translate(glm::vec3(-50.0f, 0.0f, 25.0f));
    renderer.meshes[225].transform.scale(glm::vec3(25.0f, -0.8f, 15.5f));
    renderer.meshes[225].transform.rotate(glm::vec3(0, 1, 0), -90.0f);

    renderer.meshes.push_back(Cube(Color::White, "./assets/flowers3.png"));
    renderer.meshes[226].transform.translate(glm::vec3(1.0f, 0.0f, 38.5f));
    renderer.meshes[226].transform.scale(glm::vec3(10.0f, -0.8f, 5.5f));

    renderer.meshes.push_back(Cube(Color::White, "./assets/flowers3.png"));
    renderer.meshes[227].transform.translate(glm::vec3(-33.0f, 0.0f, 38.5f));
    renderer.meshes[227].transform.scale(glm::vec3(10.0f, -0.8f, 5.5f));

    renderer.meshes.push_back(Cube(Color::White, "./assets/flowers2.jpg"));
    renderer.meshes[228].transform.translate(glm::vec3(50.0f, 0.0f, -15.0f));
    renderer.meshes[228].transform.scale(glm::vec3(15.0f, -0.8f, 14.5f));

    renderer.meshes.push_back(Cube(Color::White, "./assets/marwani_door.jpg"));
    renderer.meshes[229].transform.translate(glm::vec3(62.0f, 2.0f, -35.0f));
    renderer.meshes[229].transform.scale(glm::vec3(3.0f, -0.8f, 1.0f));
    renderer.meshes[229].transform.rotate(glm::vec3(0, 0, 1), 90.0f);

  

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//fix marwani mosque

  renderer.meshes.push_back(
        qibliCuboid(Color::White, "./assets/Teppich.png"));
    renderer.meshes[230].transform.translate(glm::vec3(77.5f, 0.1f, -48.0f));
    renderer.meshes[230].transform.scale(glm::vec3(2.4f, 1.5f, 0.4f));
    renderer.meshes[230].transform.rotate(glm::vec3(1, 0, 0), 90.0f);
    renderer.meshes[230].transform.rotate(glm::vec3(0, 0, 1), 90.0f);

    renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[231].transform.translate(glm::vec3(68.0f, 6.5f, -38.0f));
    renderer.meshes[231].transform.scale(glm::vec3(10.0f, 1.0f, 20.0f));

    renderer.meshes.push_back(Cylinder(0.2f, 0.2f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[232].transform.translate(glm::vec3(63.0f, 5.0f, -37.5f));
    renderer.meshes[232].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cylinder(0.2f, 0.2f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[233].transform.translate(glm::vec3(63.0f, 5.0f, -47.5f));
    renderer.meshes[233].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cylinder(0.2f, 0.2f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[234].transform.translate(glm::vec3(63.0f, 5.0f, -28.5f));
    renderer.meshes[234].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    renderer.meshes.push_back(Cylinder(0.2f, 0.2f, 3.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[235].transform.translate(glm::vec3(73.0f, 5.0f, -28.5f));
    renderer.meshes[235].transform.rotate(glm::vec3(1, 0, 0), -270.f);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                  Glass
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    renderer.meshes.push_back(Glass(Color::White, Material(glm::vec4({0.0215, 0.1745, 0.0215, 0.1f}), glm::vec4({0.07568, 0.61424, 0.07568, 0.6f}),
                                                           glm::vec4({0.07568, 0.61424, 0.07568, 0.6f}), (8.0f), (0.1f))));
    renderer.meshes[236].transform.translate(glm::vec3(63.5f, 5.0f, -38.5f));
    renderer.meshes[236].transform.scale(glm::vec3(9.0f, 0.0f, 0.0f));
    renderer.meshes[236].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Glass(Color::White, Material(glm::vec4({0.135, 0.2225, 0.1575, 0.1f}), glm::vec4({0.54, 0.89, 0.63, 0.6f}),
                                                           glm::vec4({0.316228, 0.316228, 0.316228, 0.1f}), (8.0f), (0.1f))));
    renderer.meshes[237].transform.setPosition(glm::vec3(68.5f, 5.0f, -28.5f));
    renderer.meshes[237].transform.scale(glm::vec3(4.0f, 0.0f, 0.0f));

    renderer.meshes.push_back(Glass(Color::White, Material(glm::vec4({0.0215, 0.1745, 0.0215, 0.1f}), glm::vec4({0.07568, 0.61424, 0.07568, 0.6f}),
                                                           glm::vec4({0.07568, 0.61424, 0.07568, 0.6f}), (8.0f), (0.1f))));
    renderer.meshes[238].transform.setPosition(glm::vec3(-62.0f, 3.0f, 45.0f));
    renderer.meshes[238].transform.rotate(glm::vec3(0, 1, 0), 90.0f);

    renderer.meshes.push_back(Glass(Color::White, Material(glm::vec4({0.135, 0.2225, 0.1575, 0.6f}), glm::vec4({0.54, 0.89, 0.63, 0.6f}),
                                                           glm::vec4({0.316228, 0.316228, 0.316228, 0.6f}), (8.0f), (0.1f))));
    renderer.meshes[239].transform.setPosition(glm::vec3(-62.0f, 3.0f, 30.0f));
    renderer.meshes[239].transform.rotate(glm::vec3(0, 1, 0), 90.0f);


  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sabil alkass

    renderer.meshes.push_back(Cylinder(2.0f, 2.0f, 0.8f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[240].transform.translate(glm::vec3(30.0f, 0.5f, 10.0f));
    renderer.meshes[240].transform.rotate(glm::vec3(1, 0, 0), -90.f);


    renderer.meshes.push_back(Cylinder(2.0f, 2.0f, 0.2f, 50, 50, Color::Green, "./assets/ornament.jpg"));
    renderer.meshes[241].transform.translate(glm::vec3(30.0f, 1.0f, 10.0f));
    renderer.meshes[241].transform.rotate(glm::vec3(1, 0, 0), -90.f);

     renderer.meshes.push_back(Cylinder(0.1f, 0.1f, 1.6f, 50, 50, Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[242].transform.translate(glm::vec3(30.0f, 0.6f, 10.0f));
    renderer.meshes[242].transform.rotate(glm::vec3(1, 0, 0), -90.f);

   renderer.meshes.push_back(Sphere(0.4F, 50, 150, Color::White, 1, "./assets/metal.png"));
    renderer.meshes[243].transform.translate(glm::vec3(30.0f, 1.2f, 10.0f));
    renderer.meshes[243].transform.rotate(glm::vec3(1, 0, 0), 180.f);

      renderer.meshes.push_back(Circle(2.0f,50));
    renderer.meshes[244].transform.translate(glm::vec3(30.0f, 1.0f, 10.0f));
    renderer.meshes[244].transform.rotate(glm::vec3(1, 0, 0), 90.f);

////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //window 
 renderer.meshes.push_back(Cube(Color::White, "./assets/window.jpg"));
    renderer.meshes[245].transform.translate(glm::vec3(-23.0f, 5.0f, 43.5f));
    renderer.meshes[245].transform.scale(glm::vec3(3.0f, -0.9f, 1.0f));
    renderer.meshes[245].transform.rotate(glm::vec3(1, 0, 0), 270.f);


//window 
 renderer.meshes.push_back(Cube(Color::White, "./assets/window.jpg"));
    renderer.meshes[246].transform.translate(glm::vec3(74.0f, 5.0f, -5.5f));
    renderer.meshes[246].transform.scale(glm::vec3(3.0f, -0.9f, 1.0f));
    renderer.meshes[246].transform.rotate(glm::vec3(1, 0, 0), 270.f);
    renderer.meshes[246].transform.rotate(glm::vec3(0, 0, 1), 90.f);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

///// south side /////

 renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[247].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[247].transform.translate(glm::vec3(65.0f, 0.0f, -10.0f));

renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[248].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[248].transform.translate(glm::vec3(-70.0f, 0.0f, -35.0f));
    
    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[249].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[249].transform.translate(glm::vec3(-70.0f, 0.0f, -25.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[250].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[250].transform.translate(glm::vec3(-70.0f, 0.0f, -15.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[251].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[251].transform.translate(glm::vec3(-70.0f, 0.0f, -7.0f));

    renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[252].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[252].transform.translate(glm::vec3(-70.0f, 0.0f, 7.0f));

 renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[253].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[253].transform.translate(glm::vec3(-70.0f, 0.0f, 11.0f));

renderer.meshes.push_back(Tree("./assets/Trees/tree.png"));
    renderer.meshes[254].transform.scale(glm::vec3(-0.5f, -0.6f, -0.5f));
    renderer.meshes[254].transform.translate(glm::vec3(-70.0f, 0.0f, 25.0f));


 renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[255].transform.translate(glm::vec3(-80.0f, 0.0f, -20.0f));
    renderer.meshes[255].transform.scale(glm::vec3(5.0f, 15.0f, 7.0f));


renderer.meshes.push_back(Cube(Color::White, "./assets/window.jpg"));
    renderer.meshes[256].transform.translate(glm::vec3(-77.0f, 6.0f, -20.5f));
    renderer.meshes[256].transform.scale(glm::vec3(3.0f, -0.9f, 1.0f));
    renderer.meshes[256].transform.rotate(glm::vec3(1, 0, 0), 270.f);
    renderer.meshes[256].transform.rotate(glm::vec3(0, 0, 1), 90.f);
    
renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[257].transform.translate(glm::vec3(-80.0f, 0.0f, -14.0f));
    renderer.meshes[257].transform.scale(glm::vec3(5.0f, 12.0f, 7.0f));

renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[258].transform.translate(glm::vec3(-80.0f, 0.0f, 14.0f));
    renderer.meshes[258].transform.scale(glm::vec3(5.0f, 12.0f, 7.0f));

renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[259].transform.translate(glm::vec3(-80.0f, 0.0f, 20.0f));
    renderer.meshes[259].transform.scale(glm::vec3(5.0f, 15.0f, 7.0f));


renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[260].transform.translate(glm::vec3(-80.0f, 0.0f, -32.0f));
    renderer.meshes[260].transform.scale(glm::vec3(9.0f, 10.0f, 9.0f));

renderer.meshes.push_back(
        Cube(Color::White, "./assets/qibli3.jpg"));
    renderer.meshes[261].transform.translate(glm::vec3(-80.0f, 0.0f, 32.0f));
    renderer.meshes[261].transform.scale(glm::vec3(9.0f, 10.0f, 9.0f));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// luster

 renderer.meshes.push_back(Luster("./assets/Gold.png"));
    renderer.meshes[262].transform.setScale(glm::vec3(0.05f * 0.35f, 0.05f * 0.35f, 0.05f * 0.35f));
    renderer.meshes[262].transform.rotate(glm::vec3(0, 1, 0), 90.f);
    renderer.meshes[262].transform.setPosition(glm::vec3(0.0f, 3.5f, 0.0f));

renderer.meshes.push_back(Luster("./assets/Gold.png"));
    renderer.meshes[263].transform.setScale(glm::vec3(0.05f * 0.45f, 0.05f * 0.45f, 0.05f * 0.45f));
    renderer.meshes[263].transform.rotate(glm::vec3(0, 1, 0), 90.f);
    renderer.meshes[263].transform.setPosition(glm::vec3(48.0f, 2.0f, 11.0f));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //flag

    renderer.meshes.push_back(Cube(Color::White, "./assets/flag.jpg"));
    renderer.meshes[264].transform.translate(glm::vec3(-30, 8.4f, 7.5f));
    renderer.meshes[264].transform.scale(glm::vec3(3.0f, -0.9f, 1.0f));
    renderer.meshes[264].transform.rotate(glm::vec3(1, 0, 0), 270.f);
    renderer.meshes[264].transform.rotate(glm::vec3(0, 0, 1), 90.f);


    renderer.meshes.push_back(Cylinder(0.2f, 0.2f, 15.0f, 10, 10, Color::White, "./assets/marble.jpg"));
    renderer.meshes[265].transform.translate(glm::vec3(-30.0f, 0.0f, 8.5f));
       renderer.meshes[265].transform.rotate(glm::vec3(1, 0, 0), 90.f);

















    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {20.0f, 30.0f, 30.0f}));
    renderer.lights.push_back(DirectionalLight({0.3, 0.24, 0.14, 1.0}, {0.7, 0.42, 0.26, 1.0}, {0.5, 0.5, 0.5, 1.0}, {-0.2, -1.0, -0.3}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {-20.0f, -10.0f, -30.0f}));
    renderer.lights.push_back(DirectionalLight({0.3f, 0.24f, 0.14f, 1}, {0.7f, 0.42f, 0.26f, 1}, {0.5f, 0.5f, 0.5f, 1}, {-0.2f, -1.0f, -0.3f}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {-20.0f, 30.0f, 30.0f}));
    renderer.lights.push_back(DirectionalLight({0.3f, 0.24f, 0.14f, 1}, {0.7f, 0.42f, 0.26f, 1}, {0.5f, 0.5f, 0.5f, 1}, {-0.2f, -1.0f, -0.3f}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {20.0f, -10.0f, -30.0f}));
    renderer.lights.push_back(DirectionalLight({0.3f, 0.24f, 0.14f, 1}, {0.7f, 0.42f, 0.26f, 1}, {0.5f, 0.5f, 0.5f, 1}, {-0.2f, -1.0f, -0.3f}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {20.0f, 30.0f, 30.0f}));
    renderer.lights.push_back(DirectionalLight({0.0f, 0.0f, 0.0f, 1}, {0.05f, 0.05f, 0.05, 1}, {0.2f, 0.2f, 0.2f, 1}, {-0.2f, -1.0f, -0.3f}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {-20.0f, -10.0f, -30.0f}));
    renderer.lights.push_back(DirectionalLight({0.0f, 0.0f, 0.0f, 1}, {0.05f, 0.05f, 0.05, 1}, {0.2f, 0.2f, 0.2f, 1}, {-0.2f, -1.0f, -0.3f}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {-20.0f, 30.0f, 30.0f}));
    renderer.lights.push_back(DirectionalLight({0.0f, 0.0f, 0.0f, 1}, {0.05f, 0.05f, 0.05, 1}, {0.2f, 0.2f, 0.2f, 1}, {-0.2f, -1.0f, -0.3f}));

    renderer.lights.push_back(
        PointLight({1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {20.0f, -10.0f, -30.0f}));
    renderer.lights.push_back(DirectionalLight({0.0f, 0.0f, 0.0f, 1}, {0.05f, 0.05f, 0.05, 1}, {0.2f, 0.2f, 0.2f, 1}, {-0.2f, -1.0f, -0.3f}));

    if (renderer.lights.size() > 0)
    {
        Light::constructLightUniformBuffer(renderer.lights);
        int lightsIndex =
            glGetUniformBlockIndex(renderer.getShaderProgramID(), "Lights");
        glUniformBlockBinding(renderer.getShaderProgramID(), lightsIndex, 0);
        assert(glGetError() == 0);
    }
    // Controls lighting
    renderer.shadeless = false;

    // background sound
    music.openFromFile("./assets/Azan.ogg");
    music.setVolume(100);
    music.setLoop(true);
    music.play();
}

bool App::loop()
{
    Event e;
    while (window.pollEvents(e))
    {
        switch (e.type)
        {
        case Event::EventType::KeyPressed:
            if (e.key.code == Keyboard::Escape)
            {
                return false;
            }
            break;
        case Event::EventType::Closed:
            return false;
            break;

        default:
            break;
        }
    }
    renderer.player.move(frameTime.restart().asSeconds(), window);
    renderer.render();
    auto err = glGetError();
    if (err != 0)
    {
        printf("%d\n", err);
    }
    window.swapBuffers();
    return true;
}
