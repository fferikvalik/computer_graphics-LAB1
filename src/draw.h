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

/**
 * Adjusts the alpha value based on the given direction.
 *
 * This function updates the alpha value based on the given direction and adjusts the x and y movement accordingly.
 *
 * @param x_move The current x movement value.
 * @param y_move The current y movement value.
 * @param alpha The current alpha value.
 * @param direction The direction of the change (positive or negative).
 */
void handleAlphaChange(float& x_move, float& y_move, double& alpha, int direction);

/**
 * @brief Handles the movement of an object within a specified limit.
 *
 * This function updates the value of the `move` parameter based on the specified `direction`.
 * The `limit` parameter defines the maximum value that `move` can reach.
 *
 * @param move The current position or movement value to be updated.
 * @param direction The direction of movement. Positive values indicate forward movement, while negative values indicate backward movement.
 * @param limit The maximum value that `move` can reach.
 */
void handleMove(float& move, int direction, float limit);

/**
 * Handles events and updates the values of the parameters.
 *
 * This function is responsible for handling events and updating the values of the parameters passed as references.
 * The function takes in the current value of 'a', 'x_move', 'y_move', and 'alpha' as parameters and modifies them based on the events.
 *
 * @param a The current value of 'a'.
 * @param x_move The current value of 'x_move'.
 * @param y_move The current value of 'y_move'.
 * @param alpha The current value of 'alpha'.
 * @return True if the events were handled successfully, false otherwise.
 */
bool handleEvents(float& a, float& x_move, float& y_move, double& alpha);

/**
 * Renders the object with the specified parameters.
 *
 * @param a The value of parameter 'a'.
 * @param x_move The value of parameter 'x_move'.
 * @param y_move The value of parameter 'y_move'.
 * @param alpha The value of parameter 'alpha'.
 */
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

