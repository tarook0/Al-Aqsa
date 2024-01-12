#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include<Window.h>

using namespace sf;

::Window::Window(){
  ContextSettings ctxSettings(24,8,0,3,3);
  sfmlWindow.create(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Aqsa",Style::Default,ctxSettings);
  sfmlWindow.setMouseCursorVisible(false);
}

void ::Window::swapBuffers(){
  sfmlWindow.display();
}
bool ::Window::pollEvents(Event& e){
  return sfmlWindow.pollEvent(e);
}

sf::Window& ::Window::getInternal(){
  return sfmlWindow;
}
