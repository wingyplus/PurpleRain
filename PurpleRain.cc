#include <array>
#include <iostream>

#include <SDL.h>

#include "Background.h"
#include "Window.h"
#include "rnd.h"

// Height is global variable to use for other class to access window height.
int Height;

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
  Drop() : yspeed(1), r(138), g(43), b(226) {}

  void SetPosition(float x, float y) {
    this->x = x;
    this->y = y;
  }

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
  std::array<Drop, 100> drops;
  for (int i = 0; i < drops.size(); i++) {
    drops[i].SetPosition(RAND(window->Width()), RAND_LH(-200, -100));
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
