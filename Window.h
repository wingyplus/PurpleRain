#ifndef PR_WINDOW_H
#define PR_WINDOW_H

#include <iostream>

#include <SDL.h>

class Window {
private:
  int width, height;
  std::string title;

  SDL_Window *window;
  SDL_Renderer *renderer;

public:
  Window(const std::string title, const int width, const int height);
  ~Window();

  SDL_Renderer *Renderer();
  const int Width();
  const int Height();
};

#endif
