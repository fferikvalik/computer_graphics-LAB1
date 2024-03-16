#pragma once
#include <SDL.h>
#include <cassert>
// Function definitions

bool init();
void close();
int my_put_pixel(int x, int y, double alpha);
void draw(SDL_Surface *s, float a, float x_move, float y_move, double alpha);
int my_put_pixel(int x, int y, double alpha);

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern SDL_Texture *gTexture;
extern SDL_Surface *loadedSurface;

