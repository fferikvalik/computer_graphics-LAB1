#include "draw.h"
// TODO: Implement rotation of the cardioid around a user-selected point, with a step size of 10 pixels per mouse click.
// TODO: Implement the ability to set the radius within the program itself.

/**
 * @brief The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return int The exit status of the program.
 */
int main(int argc, char* argv[]) {
    if (!initialize()) {
        return 1;
    }

    float a = 74;
    float x_move = 0;
    float y_move = 0;
    double alpha = 0;

    // Variables for tracking FPS
    int frameCount = 0;
    Uint32 startTime = SDL_GetTicks();
    Uint32 lastTime = startTime;

    // Desired frame rate
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;

    bool quit = false;
    while (!quit) {
        frameStart = SDL_GetTicks();

        quit = !handleEvents(a, x_move, y_move, alpha);
        if (quit)
            break;

        updateFPS(frameCount, lastTime);

        render(a, x_move, y_move, alpha);

        limitFPS(frameStart, frameDelay);
    }

    close();
    return 0;
}
