#pragma once

#include <SDL.h>
#include <stdio.h>
#include <cassert>

/**
 * @brief Initializes the SDL library.
 *
 * @return true if initialization is successful, false otherwise.
 */
bool init();

/**
 * @brief Closes the SDL library and frees any resources used.
 */
void close();

/**
 * @brief Sets the color of a pixel on the given surface.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param alpha The alpha value of the pixel (transparency).
 * @return 0 if successful, -1 if an error occurred.
 */
int my_put_pixel(int x, int y, double alpha);

void handleAlphaChange(float& x_move, float& y_move, double& alpha, int direction);

void handleMove(float& move, int direction, float limit);

bool handleEvents(float& a, float& x_move, float& y_move, double& alpha);

void render(float a, float x_move, float y_move, double alpha);
/**
 * @brief Draws an SDL surface on the screen with the specified transformations.
 *
 * @param s The surface to draw.
 * @param a The rotation angle in degrees.
 * @param x_move The horizontal translation.
 * @param y_move The vertical translation.
 * @param alpha The alpha value of the surface (transparency).
 */
void draw(SDL_Surface *s, float a, float x_move, float y_move, double alpha);

/**
 * @brief Sets the color of a pixel on the given surface.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param alpha The alpha value of the pixel (transparency).
 * @return 0 if successful, -1 if an error occurred.
 */
int my_put_pixel(int x, int y, double alpha);

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern SDL_Texture *gTexture;
extern SDL_Surface *loadedSurface;

