#include <SDL.h>

#include "Background.h"

void Background::Render(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
}
