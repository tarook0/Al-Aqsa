#pragma once
#include "Renderer.h"
#include <SFML/System/Clock.hpp>
#include<SFML/Audio/Music.hpp>
#include<Window.h>
class App{
public:
  App();
  bool loop();
private:
  Window window;
  Renderer renderer;
  sf::Clock frameTime;
  sf::Music music;
};
