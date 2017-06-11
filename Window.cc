#include "Window.h"

Window::Window(const std::string title, const int width, const int height) {
  this->title = title;
  this->width = width;
  this->height = height;
  this->window =
    SDL_CreateWindow(title.c_str(), 0, 0, width, height, SDL_WINDOW_OPENGL);
  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

SDL_Renderer *Window::Renderer() { return renderer; }

const int Window::Width() { return width; }

const int Window::Height() { return height; }
