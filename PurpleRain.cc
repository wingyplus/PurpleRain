#include <iostream>

#include <SDL2/SDL.h>

class Background {
private:
  int r, g, b;

public:
  Background() : r(230), g(230), b(250) {}

  // Render update background to renderer
  void Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
  }
};

class Drop {
private:
  float x, y;
  int r, g, b;

public:
  Drop(float x, float y) : x(x), y(y), r(138), g(43), b(226) {}

  void Render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x, y, x, y + 10);
  }
};

int main(int argc, char **argv) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Purple Rain", 0, 0, 640, 360, SDL_WINDOW_OPENGL);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  Background background;
  int w;
  SDL_GetWindowSize(window, &w, nullptr);
  Drop d(w / 2, 0);

  SDL_Event evt;
  while (1) {
    SDL_PollEvent(&evt);
    if (evt.type == SDL_QUIT) {
      break;
    }

    background.Render(renderer);
    d.Render(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
