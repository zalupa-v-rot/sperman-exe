#include "./sdl.h"


int main () {

  struct sdl_head ssdl;

  if (core(&ssdl)) {

    return 1;
  }

  return 0;
}
