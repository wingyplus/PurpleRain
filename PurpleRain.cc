#include <SDL2/SDL.h>

int main(int argc, char **argv) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Purple Rain", 0, 0, 640, 360, SDL_WINDOW_OPENGL);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event evt;
  while (1) {
    SDL_PollEvent(&evt);
    if (evt.type == SDL_QUIT) {
      break;
    }
    SDL_SetRenderDrawColor(renderer, 230, 230, 250, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
