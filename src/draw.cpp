/**
 * @file draw.cpp
 * @brief Implementation file for drawing functions.
 *
 * This file contains the implementation of various drawing functions used in the program.
 * It includes functions for handling alpha changes, object movement, SDL events, rendering graphics,
 * initializing and closing SDL, putting pixels on an SDL surface, clearing a surface, getting pixels from a surface,
 * rotating coordinates, drawing axes, and drawing a grid.
 */
/**
 * @file draw.cpp
 * @brief Implementation file for drawing functions.
 */
#include "draw.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#define RGB32(r, g, b) static_cast<uint32_t>((((static_cast<uint32_t>(r) << 8) | g) << 8) | b)

/**
 * @brief Handles the change in alpha value and updates the position coordinates.
 *
 * This function takes in the current position coordinates (x_move and y_move), the alpha value,
 * and the direction of change. It updates the alpha value by adding 5 times the direction,
 * fills the loadedSurface with a white color, and clamps the position coordinates within certain limits.
 *
 * @param x_move The current x-coordinate of the position.
 * @param y_move The current y-coordinate of the position.
 * @param alpha The current alpha value.
 * @param direction The direction of change (-1 for decrease, 1 for increase).
 */
void handleAlphaChange(float& x_move, float& y_move, double& alpha, int direction) {
    alpha += 5 * direction;
    SDL_FillRect(loadedSurface, nullptr, 0x00FFFFFF);
    x_move = std::min(x_move, 170.0f);
    x_move = std::max(x_move, -310.0f);
    y_move = std::min(y_move, 230.0f);
    y_move = std::max(y_move, -230.0f);
}

/**
 * Handles the movement of an object.
 *
 * This function updates the position of an object based on the given direction and limit.
 *
 * @param move The current position of the object.
 * @param direction The direction of movement. Positive values indicate forward movement, while negative values indicate backward movement.
 * @param limit The maximum limit for the object's position.
 */
void handleMove(float& move, int direction, float limit) {
    printf("Move key has been pressed\n");
    if (direction > 0 && move + 10 < limit) {
        move += 10;
    } else if (direction < 0 && move - 10 > -limit) {
        move -= 10;
    }
}

/**
 * Handles SDL events and updates the values of `a`, `x_move`, `y_move`, and `alpha` accordingly.
 *
 * @param a The reference to the `a` variable.
 * @param x_move The reference to the `x_move` variable.
 * @param y_move The reference to the `y_move` variable.
 * @param alpha The reference to the `alpha` variable.
 * @return `true` if the program should continue running, `false` if the program should exit.
 */
bool handleEvents(float& a, float& x_move, float& y_move, double& alpha) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (SDL_QUIT == e.type) {
            return false;
        }
        //if (SDL_MOUSEBUTTONDOWN == e.type){
            //e.button.x;
        //}
        if (SDL_KEYDOWN == e.type) {
            switch (e.key.keysym.scancode) {
                case SDL_SCANCODE_Q:
                    handleAlphaChange(x_move, y_move, alpha, -1);
                    break;
                case SDL_SCANCODE_E:
                    handleAlphaChange(x_move, y_move, alpha, 1);
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
                    handleMove(x_move, 1, 170);
                    break;
                case SDL_SCANCODE_A:
                    handleMove(x_move, -1, 310);
                    break;
                case SDL_SCANCODE_W:
                    handleMove(y_move, -1, 230);
                    break;
                case SDL_SCANCODE_S:
                    handleMove(y_move, 1, 230);
                    break;
                case SDL_SCANCODE_ESCAPE:
                    return false;
                default:
                    break;
            }
        }
    }
    return true;
}

/**
 * Renders the graphics on the screen.
 *
 * @param a The value of 'a' used in the draw function.
 * @param x_move The amount of horizontal movement.
 * @param y_move The amount of vertical movement.
 * @param alpha The angle in degrees.
 */

void render(float a, float x_move, float y_move, double alpha) {
    SDL_RenderClear(gRenderer);
    draw(loadedSurface, a, x_move, y_move, alpha * 3.14 / 180);
    SDL_UpdateTexture(gTexture, NULL, loadedSurface->pixels, loadedSurface->pitch);
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
}

    SDL_Window *gWindow = NULL;
    SDL_Renderer *gRenderer = NULL;
    SDL_Texture *gTexture = NULL;
    /**
     * @brief Represents a 2D image surface that can be used for rendering in SDL.
     *
     * The `SDL_Surface` structure represents a 2D image surface that can be used for rendering in SDL.
     * It contains pixel data and various attributes like width, height, and pixel format.
     * This structure is used by many SDL functions to perform operations on surfaces, such as loading and saving images,
     * blitting surfaces onto other surfaces, and more.
     *
     * @note This structure is an opaque data type, meaning that its internal implementation is hidden from the user.
     *       Users should only interact with `SDL_Surface` pointers and use the provided functions to manipulate them.
     */
    SDL_Surface *loadedSurface = NULL;

/**
 * Initializes the SDL library and creates a window and renderer.
 *
 * @return true if initialization is successful, false otherwise.
 */
bool init()
{
  bool success = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    gWindow = SDL_CreateWindow("AOKG Lab 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_SOFTWARE);
      if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        success = false;
      } else {
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
      }
    }
  }
  return success;
}

/**
 * @brief Closes the SDL window and cleans up resources.
 *
 * This function destroys the SDL texture, renderer, and window, and then quits the SDL subsystem.
 * After calling this function, the texture, renderer, and window pointers are set to NULL.
 */
void close()
{
  SDL_DestroyTexture(gTexture);
  gTexture = NULL;
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;
  SDL_Quit();
}

/**
 * Puts a pixel of the specified color at the given coordinates on the SDL surface.
 *
 * @param surface The SDL surface on which to put the pixel.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param pixel The color of the pixel in the format of Uint32.
 */
void put_pixel32(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  assert(NULL != surface); // Check if surface is not NULL
  if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
    Uint32 *pixels = (Uint32 *)surface->pixels;
    pixels[(y * surface->w) + x] = pixel;
  }
}

/**
 * Clears the given SDL_Surface by setting all pixels to black.
 *
 * @param s The SDL_Surface to be cleared.
 */
void clear_surface(SDL_Surface * s) {
  for (int x = 1; x < SCREEN_WIDTH; x++) // Loop through each x-coordinate
    for(int y = 1; y < SCREEN_HEIGHT; y++) // Loop through each y-coordinate
      put_pixel32(s,x,y,RGB32(0,0,0)); // Set pixel at (x, y) to black
}

/**
 * @brief Unsigned 32-bit integer type.
 *
 * This type represents an unsigned 32-bit integer value.
 * It is commonly used to store pixel values in graphics programming.
 */
Uint32 get_pixel32(SDL_Surface *surface, int x, int y)
{
  assert(NULL != surface); // Check if surface is not NULL
  assert(x < SCREEN_WIDTH); // Check if x is within the screen width
  assert(y < SCREEN_HEIGHT); // Check if y is within the screen height

  Uint32 *pixels = (Uint32 *)surface->pixels;
  return pixels[(y * surface->w) + x]; // Return the pixel value at (x, y)
}

/**
 * Rotates the given coordinates (x, y) using the specified angle alpha.
 *
 * @param x The x-coordinate of the point to be rotated.
 * @param y The y-coordinate of the point to be rotated.
 * @param alpha The angle (in radians) by which the point should be rotated.
 * @return The rotated coordinates (x, y).
 */
int my_put_pixel(int x, int y, double alpha)
{
  x = (int)(x * cos(alpha) - y * sin(alpha)); // Rotate x-coordinate using alpha
  y = (int)(x * sin(alpha) + y * cos(alpha)); // Rotate y-coordinate using alpha
  return x, y; // Return the rotated coordinates
}

/**
 * Draws the axes on the given SDL surface.
 *
 * @param s The SDL surface to draw on.
 */
void draw_axes(SDL_Surface *s)
{
  for (int i = 0; i < SCREEN_WIDTH; i++){ // Loop through each x-coordinate
    put_pixel32(s, i, SCREEN_HEIGHT/2, RGB32(255, 255, 255)); // Set pixel at (i, SCREEN_HEIGHT/2) to white
  }

  for (int j = 0; j < SCREEN_HEIGHT; j++){ // Loop through each y-coordinate
    put_pixel32(s, SCREEN_WIDTH/2, j, RGB32(255, 255, 255)); // Set pixel at (SCREEN_WIDTH/2, j) to white
  }
}

/**
 * Draws a grid on the given SDL surface.
 *
 * @param s The SDL surface to draw the grid on.
 * @param step The step size between each grid line.
 */
void draw_grid(SDL_Surface *s, int step)
{
  for (int x = 0; x < SCREEN_WIDTH; x += step) { // Loop through each x-coordinate with the given step
    for (int y = 0; y < SCREEN_HEIGHT; y += step) { // Loop through each y-coordinate with the given step
      put_pixel32(s, x, y, RGB32(255, 255, 255)); // Set pixel at (x, y) to white
    }
  }
}

/**
 * Draws a shape on the given SDL surface.
 *
 * @param s The SDL surface to draw on.
 * @param a The parameter used to calculate the shape's coordinates.
 * @param x_move The amount to translate the shape along the x-axis.
 * @param y_move The amount to translate the shape along the y-axis.
 * @param alpha The angle (in radians) used to rotate the shape.
 */
void draw_main_function(SDL_Surface *s, float a, float x_move, float y_move, double alpha)
{
  for (float t = 0; t < 2 * M_PI; t += 0.001) { // Loop through each angle from 0 to 2*pi
    float x = a * cos(t) * (1 + cos(t)); // Calculate x-coordinate based on angle and parameter a
    float y = a * sin(t) * (1 + cos(t)); // Calculate y-coordinate based on angle and parameter a
    float rotate_x = x * cos(alpha) + y * sin(alpha); // Rotate x-coordinate using alpha
    float rotate_y = -x * sin(alpha) + y * cos(alpha); // Rotate y-coordinate using alpha
    x = rotate_x; // Update x-coordinate with rotated value
    y = rotate_y; // Update y-coordinate with rotated value
    x += x_move; // Translate x-coordinate by x_move
    y += y_move; // Translate y-coordinate by y_move
    put_pixel32(s, x + SCREEN_WIDTH / 2, y + SCREEN_HEIGHT / 2, RGB32(255, 105, 108)); // Set pixel at (x + SCREEN_WIDTH/2, y + SCREEN_HEIGHT/2) to RGB(255, 105, 108)
  }
}

/**
 * Draws an invisible circle on the given SDL surface.
 *
 * @param s The SDL surface to draw on.
 * @param a The radius of the circle.
 * @param x_move The amount to move the circle along the x-axis.
 * @param y_move The amount to move the circle along the y-axis.
 * @param alpha The angle in radians to rotate the circle.
 */
void draw_invisible_circle(SDL_Surface *s, float a, float x_move, float y_move, double alpha)
{
  for (float g = 0; g < 2 * M_PI; g += 0.1) { // Loop through each angle from 0 to 2*pi
    float x = (a / 2) * cos(g) + a/2; // Calculate x-coordinate based on angle and parameter a
    float y = (a / 2) * sin(g); // Calculate y-coordinate based on angle and parameter a
    float rotate_x = x * cos(alpha) + y * sin(alpha); // Rotate x-coordinate using alpha
    float rotate_y = -x * sin(alpha) + y * cos(alpha); // Rotate y-coordinate using alpha
    x = rotate_x; // Update x-coordinate with rotated value
    y = rotate_y; // Update y-coordinate with rotated value
    x += x_move; // Translate x-coordinate by x_move
    y += y_move; // Translate y-coordinate by y_move
    put_pixel32(s, x + SCREEN_WIDTH / 2, y + SCREEN_HEIGHT / 2, RGB32(255,0, 255)); // Set pixel at (x + SCREEN_WIDTH/2, y + SCREEN_HEIGHT/2) to RGB(255, 0, 255)
  }
}

/**
 * Draws a circle on the given SDL surface.
 *
 * @param s The SDL surface to draw on.
 * @param a The radius of the circle.
 * @param x_move The amount to translate the circle along the x-axis.
 * @param y_move The amount to translate the circle along the y-axis.
 * @param alpha The angle (in radians) to rotate the circle.
 */
void draw_circle_points(SDL_Surface *s, float a, float x_move, float y_move, double alpha)
{
  for (float i = 0; i < 2 * M_PI; i += 0.1) { // Loop through each angle from 0 to 2*pi
    float x = 2.5 * cos(i) + a/2; // Calculate x-coordinate based on angle and parameter a
    float y = 2.5 * sin(i) + a/2; // Calculate y-coordinate based on angle and parameter a
    float rotate_x = x * cos(alpha) - y * sin(alpha); // Rotate x-coordinate using alpha
    float rotate_y = x * sin(alpha) + y * cos(alpha); // Rotate y-coordinate using alpha
    x = rotate_x; // Update x-coordinate with rotated value
    y = rotate_y; // Update y-coordinate with rotated value
    x += x_move; // Translate x-coordinate by x_move
    y -= y_move; // Translate y-coordinate by y_move
    put_pixel32(s, x + SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - y, RGB32(0, 255, 0)); // Set pixel at (x + SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - y) to RGB(0, 255, 0)
  }
}

/**
 * Draws a cardioid shape on the given SDL surface.
 *
 * @param s The SDL surface to draw on.
 * @param a The parameter value for the cardioid shape.
 * @param x_move The amount to move the shape horizontally.
 * @param y_move The amount to move the shape vertically.
 * @param alpha The angle in radians to rotate the shape.
 */
void draw_function_points(SDL_Surface *s, float a, float x_move, float y_move, double alpha)
{
  for (float i = 0; i < 2 * M_PI; i += 0.1) { // Loop through each angle from 0 to 2*pi
    float x = 2.5 * cos(i) + (3*a)/4; // Calculate x-coordinate based on angle and parameter a
    float y = 2.5 * sin(i) + sqrt(3)*(3*a)/4; // Calculate y-coordinate based on angle and parameter a

    // Rotate the cardioid
    float rotate_x = x * cos(alpha) - y * sin(alpha); // Rotate x-coordinate using alpha
    float rotate_y = x * sin(alpha) + y * cos(alpha); // Rotate y-coordinate using alpha

    // Translate the cardioid after rotating
    x = rotate_x + x_move;
    y = rotate_y - y_move;

    put_pixel32(s, x + SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - y, RGB32(0, 255, 0)); // Set pixel at (x + SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - y) to RGB(0, 255, 0)
  }

  for (float i = 0; i < 2 * M_PI; i += 0.1) { // Loop through each angle from 0 to 2*pi
    float x = 2.5 * cos(i) + (3*a)/4; // Calculate x-coordinate based on angle and parameter a
    float y = 2.5 * sin(i) + sqrt(3)*(-1)*(3*a)/4; // Calculate y-coordinate based on angle and parameter a

    // Rotate the cardioid
    float rotate_x = x * cos(alpha) - y * sin(alpha); // Rotate x-coordinate using alpha
    float rotate_y = x * sin(alpha) + y * cos(alpha); // Rotate y-coordinate using alpha

    // Translate the cardioid after rotating
    x = rotate_x + x_move;
    y = rotate_y - y_move;

    put_pixel32(s, x + SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - y, RGB32(0, 255, 0)); // Set pixel at (x + SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - y) to RGB(0, 255, 0)
  }
}

/**
 * @brief Draws various elements on the given SDL surface.
 *
 * This function clears the surface by setting all pixels to black,
 * draws axes, the main function, a grid, an invisible circle,
 * circle points, and function points.
 *
 * @param s The SDL surface to draw on.
 * @param a The scaling factor for the main function.
 * @param x_move The horizontal translation for the main function.
 * @param y_move The vertical translation for the main function.
 * @param alpha The rotation angle for the main function.
 */
void draw(SDL_Surface *s, float a, float x_move, float y_move, double alpha)
{
  clear_surface(s); // Clear the surface by setting all pixels to black
  draw_axes(s);
  draw_main_function(s, a, x_move, y_move, alpha);
  draw_grid(s, 20);
  draw_invisible_circle(s, a, x_move, y_move, alpha);
  draw_circle_points(s, a, x_move, y_move, alpha);
  draw_function_points(s, a, x_move, y_move, alpha);
}
