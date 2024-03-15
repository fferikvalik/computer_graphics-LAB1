#pragma once
#include <SDL.h>
#include <cassert>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

void draw(SDL_Surface *s, float a, float x_move, float y_move, double alpha);

int my_put_pixel(int x, int y, double alpha);
