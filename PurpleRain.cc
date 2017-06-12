#include <array>
#include <iostream>

#include <SDL2/SDL.h>

#include "Window.h"
#include "rnd.h"

// Height is global variable to use for other class to access window height.
int Height;

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
  float x, y, yspeed;
  int r, g, b;

  // Fall the drop by yspeed
  void Fall() {
    y += yspeed;

    // re-position y when drop is outside window
    if (y > Height) {
      y = RAND_LH(-200, -100);
    }
  }

public:
  Drop() : Drop(0, 0) {}
  Drop(float x, float y) : x(x), y(y), yspeed(1), r(138), g(43), b(226) {}

  // Update position of drop
  void Update() { Fall(); }

  // Render the drop
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

  Window *window = new Window("Purple Rain", 640, 360);
  Height = window->Height();
  SDL_Renderer *renderer = window->Renderer();

  Background background;
  // TODO: find the way to create 100 drops in efficient way.
  std::array<Drop, 100> drops;
  for (int i = 0; i < drops.size(); i++) {
    drops[i] = Drop(RAND(window->Width()), RAND_LH(-200, -100));
  }

  SDL_Event evt;
  while (1) {
    SDL_PollEvent(&evt);
    if (evt.type == SDL_QUIT) {
      break;
    }

    background.Render(renderer);
    for (int i = 0; i < drops.size(); i++) {
      drops[i].Update();
      drops[i].Render(renderer);
    }
    SDL_RenderPresent(renderer);
  }

  delete window;
  SDL_Quit();
  return 0;
}
