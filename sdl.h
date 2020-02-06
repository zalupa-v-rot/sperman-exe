#include <SDL/SDL.h>

struct sdl_head {

  SDL_Surface *pscreen;
  SDL_Surface *prectangle;
  SDL_Rect    *pposition;
};

int core(struct sdl_head *sdl);
