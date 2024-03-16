#include "draw.h"

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

    if (NULL == gTexture) {
        printf("Failed to load media!\n");
        close();
        return 1;
    }

    bool quit = false;
    while (!quit) {
        quit = !handleEvents(a, x_move, y_move, alpha);
        if (quit)
            break;
        render(a, x_move, y_move, alpha);
    }

    close();
    return 0;
}
