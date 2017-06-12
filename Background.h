#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background {
private:
  int r, g, b;

public:
  Background() : r(230), g(230), b(250) {}

  // Render update background to renderer
  void Render(SDL_Renderer *);
};

#endif // BACKGROUND_H
