#include "Transform.h"
#include "Window.h"
#include <Player.h>
#include <SFML/Window/Keyboard.hpp>

using namespace glm;
using namespace sf;

Player::Player(Transform transform) : transform(transform) {
  eularAngles={0,0,0};
}

mat4 Player::updateView() {
  vec3 camPos = transform.getPosition();
  vec3 camDir = vec3(0, 0, -1);
  vec3 camUp = vec3(0, 1, 0);
  mat3 rotationMat = mat3(transform.getRotation());
  camDir = rotationMat * camDir;
  camUp = rotationMat * camUp;
  vec3 lookedAt = camDir + camPos;
  mat4 viewPerspective = perspective(FOV, ASPECT_RATIO, 0.1f, 100.0f) *
                         lookAt(camPos, lookedAt, camUp);
  return viewPerspective;
}

void Player::move(float deltaTime, ::Window& window) {
  vec3 velocity(0, 0, 0);
  if (Keyboard::isKeyPressed(Keyboard::W)) {
    velocity.z -= 1;
  }
  if (Keyboard::isKeyPressed(Keyboard::S)) {
    velocity.z += 1;
  }
  if (Keyboard::isKeyPressed(Keyboard::D)) {
    velocity.x += 1;
  }
  if (Keyboard::isKeyPressed(Keyboard::A)) {
    velocity.x -= 1;
  }
  if(Keyboard::isKeyPressed(Keyboard::P)){
    printf("%f %f %f\n",transform.getPosition().x,transform.getPosition().y,transform.getPosition().z);
  }
  if (length(velocity) > 0) {
    velocity = normalize(velocity)*SPEED;
  }
  auto mousePos = Mouse::getPosition(window.getInternal());
  mouseDelta = {mousePos.x - WINDOW_WIDTH / 2.0f,
                mousePos.y - WINDOW_HEIGHT / 2.0f};
  mouseDelta *= -MOUSE_SENSTIVITY;
  Mouse::setPosition(Vector2i{static_cast<int>(WINDOW_WIDTH / 2.0f), static_cast<int>(WINDOW_HEIGHT / 2.0f)}, window.getInternal());

  vec3 appliedVelocity = mat3(transform.getRotation()) * velocity;
  appliedVelocity.y=0;
  if(Keyboard::isKeyPressed(Keyboard::LShift)){
    appliedVelocity.y+=SPEED;
  }
  if(Keyboard::isKeyPressed(Keyboard::LControl)){
    appliedVelocity.y-=SPEED;
  }
  transform.translateGlobal(appliedVelocity * deltaTime);
  vec3 pos=transform.getPosition();
  transform.setPosition({clamp(pos.x,-71.0f,71.0f),pos.y,clamp(pos.z,-46.0f,46.0f)});
  eularAngles.x += mouseDelta.y * deltaTime;
  eularAngles.y += mouseDelta.x * deltaTime;
  eularAngles.x = glm::clamp<float>(eularAngles.x, -60.0f, 80.0f);
  transform.setRotation(eularAngles);
}
