#pragma once

#include <SDL.h>
#include <stdio.h>
#include <cassert>
#include <string>

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
 * Limits the frames per second (FPS) of the program.
 *
 * @param frameStart The starting time of the frame.
 * @param frameDelay The delay between frames in milliseconds.
 */
void limitFPS(Uint32 frameStart, int frameDelay);

/**
 * @brief Updates the frames per second (FPS) count.
 *
 * This function updates the frame count and calculates the elapsed time since the last update.
 *
 * @param frameCount A reference to the frame count variable.
 * @param lastTime A reference to the last update time variable.
 */
void updateFPS(int& frameCount, Uint32& lastTime);

/**
 * @brief Initializes the graphics library.
 *
 * This function initializes the graphics library and returns a boolean value indicating whether the initialization was successful or not.
 *
 * @return true if the initialization was successful, false otherwise.
 */
bool initialize();

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

/**
 * @brief The main window used by the application.
 *
 * This variable represents the main window used by the application. It is of type `SDL_Window*`.
 * The window is created and managed by the SDL library.
 */
extern SDL_Window *gWindow;
/**
 * @brief The rendering context used by SDL.
 *
 * The `SDL_Renderer` is responsible for rendering graphics to a window or texture. It provides functions for drawing basic shapes, rendering images, and applying transformations. The renderer is associated with a specific window or texture and is used to update the screen or texture with the rendered content.
 *
 * @see SDL_CreateRenderer
 * @see SDL_DestroyRenderer
 * @see SDL_RenderPresent
 */
extern SDL_Renderer *gRenderer;
/**
 * @brief The texture used for rendering.
 *
 * This variable represents the SDL texture used for rendering graphics on the screen.
 * It is an external variable, meaning it is defined in another file and can be accessed
 * from this file using the `extern` keyword.
 */
extern SDL_Texture *gTexture;
/**
 * @brief Represents a 2D image surface that can be used for rendering.
 *
 * The `SDL_Surface` structure represents a 2D image surface that can be used for rendering
 * with the SDL library. It contains pixel data and information about the format and size
 * of the surface.
 *
 * @see SDL_CreateRGBSurface()
 * @see SDL_LoadBMP()
 * @see SDL_BlitSurface()
 */
extern SDL_Surface *loadedSurface;

