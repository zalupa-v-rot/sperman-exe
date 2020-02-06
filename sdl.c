#include "./sdl.h"
#include <errno.h>
#include <stdio.h>
#include <SDL/SDL.h>

/* https://www.badprog.com/c-sdl-simple-directmedia-layer-creating-a-rectangle-and-moving-it */

int core(struct sdl_head *psdl);
int event_handler(struct sdl_head *psdl);
int sprite_update(struct sdl_head *psdl);

#define ERROR()                                                         \
  fprintf(stderr, "error: %s, line: %i, file: %s\n", SDL_GetError(), __LINE__, __FILE__); \
  return 1

int core(struct sdl_head *psdl) {


  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {

    fprintf(stderr, "Error: %s\n", strerror(errno));
    return 1;
  }

  if ((psdl->pscreen =
       SDL_SetVideoMode(800, 600, 32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {

    ERROR();
  }

  SDL_WM_SetCaption("zalupa spermana :D", NULL);

  if (SDL_FillRect(psdl->pscreen,
                   NULL, SDL_MapRGB(psdl->pscreen->format, 255, 32, 45)) == -1) {

    ERROR();
  }

  if (SDL_Flip(psdl->pscreen) == -1) {

    ERROR();
  }

  psdl->pposition->x = 0;
  psdl->pposition->y = 0;

  if (event_handler(psdl)) {

    ERROR();
  }

  SDL_FreeSurface(psdl->prectangle);
  SDL_Quit();
  return 0;
}

int event_handler(struct sdl_head *psdl) {

  SDL_Event  sevent;


  for ( ; ; ) {

    SDL_WaitEvent(&sevent);


    if (sevent.type == SDL_QUIT) {

      return 0;
    }

    if (sevent.type == SDL_KEYDOWN) {

      switch(sevent.key.keysym.sym) {

      case SDLK_ESCAPE:
        return 0;

      case SDLK_RIGHT:
        psdl->pposition->x += 10;
        break;

      case SDLK_LEFT:
        psdl->pposition->x -= 10;
        break;

      case SDLK_UP:
        psdl->pposition->y -= 10;
        break;

      case SDLK_DOWN:
        psdl->pposition->y += 10;
        break;

      default:
        ERROR();
      }
    }

    sprite_update(psdl);
  }

  return 0;
}


int sprite_update(struct sdl_head *psdl) {


  if (SDL_FillRect(psdl->pscreen,
                   NULL,
                   SDL_MapRGB(psdl->pscreen->format, 255, 32, 45)) == -1) {

    ERROR();
  }


  psdl->prectangle = NULL;

  if ((psdl->prectangle
       = SDL_CreateRGBSurface(SDL_HWSURFACE,
                              220, 180, 32, 0, 0, 0, 0)) == NULL) {

    ERROR();
  }

  if (SDL_FillRect(psdl->prectangle,
                   NULL,
                   SDL_MapRGB(psdl->pscreen->format, 255, 255, 45)) == -1) {

    ERROR();
  }

  if (SDL_BlitSurface(psdl->prectangle,
                      NULL, psdl->pscreen, psdl->pposition) == -1) {

    ERROR();
  }

  if (SDL_Flip(psdl->pscreen) == -1) {

    ERROR();
  }

  return 0;
}
