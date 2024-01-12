#pragma once
#include<SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include<SFML/Window/Event.hpp>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


class Window{
public:
  Window();
  void swapBuffers();
  bool pollEvents(sf::Event& e); 
  sf::Window& getInternal();
private:
  sf::Window sfmlWindow;
};
