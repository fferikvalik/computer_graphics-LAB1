#include "draw.h"
// TODO: Implement frame rate limiting for animation rendering.
// TODO: Implement dynamic window title update with current coordinates of the cardioid center and current FPS count.
// TODO: Implement rotation of the cardioid around a user-selected point, with a step size of 10 pixels per mouse click.
// TODO: Implement the ability to set the rotation point by clicking on a specific part of the screen.
// TODO: Implement the ability to set the radius within the program itself.


#include <SDL.h>
#include <string>

/**
 * @brief The main function of the program.
 *
 * This function is the entry point of the program. It initializes the necessary components,
 * creates a window, and enters the main loop where events are handled and rendering is performed.
 * The main loop continues until the user quits the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return An integer representing the exit status of the program.
 */
int main(int argc, char* argv[]) {
    if (!init()) {
        printf("Failed to initialize!\n");
        return 1;
    }

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

    if (nullptr == gTexture) {
        printf("Failed to load media!\n");
        close();
        return 1;
    }

    // Variables for tracking FPS
    int frameCount = 0;
    Uint32 startTime = SDL_GetTicks();
    Uint32 lastTime = startTime;

    bool quit = false;
    while (!quit) {
        quit = !handleEvents(a, x_move, y_move, alpha);
        if (quit)
            break;

        // Update frame counter
        frameCount++;

        // If more than one second has passed since the last update, update the window title
        if (SDL_GetTicks() - lastTime > 1000) {
            std::string title = "FPS: " + std::to_string(frameCount);
            SDL_SetWindowTitle(gWindow, title.c_str());

            // Reset frame counter
            frameCount = 0;
            lastTime = SDL_GetTicks();
        }

        render(a, x_move, y_move, alpha);
    }

    close();
    return 0;
}
