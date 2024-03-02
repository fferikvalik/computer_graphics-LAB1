#pragma once
#include <SDL.h>
#include <cassert>

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

void draw(SDL_Surface *s);

void drawCardioid(SDL_Surface* surface, float a);
