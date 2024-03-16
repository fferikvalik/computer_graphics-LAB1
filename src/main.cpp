#include "draw.h"

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cassert>

bool init();
void close();

int main(int argc, char *argv[])
{
  if (!init()) {
    printf("Failed to initialize!\n");
  } else {
    loadedSurface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
      0x00FF0000,// R
      0x0000FF00,// G
      0x000000FF,// B
      0x00000000);// alpha
    float a = 74;
    float x_move = 0;
    float y_move = 0;
    double alpha = 0;
    gTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

    if (NULL == gTexture) {
      printf("Failed to load media!\n");
    } else {
      bool quit = false;
      SDL_Event e;

      while (!quit) {
        while (SDL_PollEvent(&e) != 0) {

                if (SDL_QUIT == e.type) {
                  quit = true;
                }
                if (SDL_KEYDOWN == e.type) {
                  switch (e.key.keysym.scancode) {
                    case SDL_SCANCODE_Q:
                    alpha -= 5;
                    SDL_FillRect(loadedSurface, NULL, 0x00FFFFFF);
                    break;
                  case SDL_SCANCODE_E:
                    alpha += 5;
                    SDL_FillRect(loadedSurface, NULL, 0x00FFFFFF);
                    break;
                  case SDL_SCANCODE_KP_PLUS:
                    printf("SDL_SCANCODE_KP_PLUS have been presssed\n");
                    a += 3;
                    break;
                  case SDL_SCANCODE_KP_MINUS:
                    printf("SDL_SCANCODE_KP_MINUS have been presssed\n");
                    a -= 3;
                    break;
                 case SDL_SCANCODE_D:
                    printf("SDL_SCANCODE_D have been pressed\n");
                    if (x_move + 10 < 170){
                      x_move += 10;
                    }
                    break;
                  case SDL_SCANCODE_A:
                    printf("SDL_SCANCODE_A have been pressed\n");
                    if (x_move - 10 > -310){
                      x_move -= 10;
                    }
                    break;
                  case SDL_SCANCODE_W:
                    printf("SDL_SCANCODE_W have been pressed\n");
                    if (y_move - 10 > -230){
                      y_move -= 10;
                    }
                    break;
                  case SDL_SCANCODE_S:
                    printf("SDL_SCANCODE_S have been pressed\n");
                    if (y_move + 10 < 230){
                      y_move += 10;
                    }
                    break;
                  case SDL_SCANCODE_ESCAPE:
                    quit = true;
                    break;
                  default:
                    break;
                  }
                }
              }
              SDL_RenderClear(gRenderer);

              draw(loadedSurface, a, x_move, y_move, alpha * 3.14 / 180);

              SDL_UpdateTexture(gTexture, NULL, loadedSurface->pixels, loadedSurface->pitch);
              SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
              SDL_RenderPresent(gRenderer);
            }
          }
  }
  close();
  return 0;
}
