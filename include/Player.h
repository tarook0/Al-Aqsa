#pragma once

#include<glm/glm.hpp>
#include<Transform.h>
#include<Window.h>
#include<SFML/Window/Keyboard.hpp>
#include<SFML/Window/Mouse.hpp>

#define FOV 45.0f
#define ASPECT_RATIO 16.0f/9.0f
#define SPEED 10.0f
#define MOUSE_SENSTIVITY 50
class Player{
public:
  Player(Transform transform=Transform());
  glm::mat4 updateView();
  void move(float deltaTime,Window& window);

  Transform transform;
private:
  glm::vec2 mouseDelta;
  glm::vec3 eularAngles;
};
