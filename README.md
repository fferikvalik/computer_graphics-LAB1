![GitHub last commit](https://img.shields.io/github.com/fferikvalik/computer_graphics-LAB1?color=yellow)
# Game Rendering Project

This project is about rendering game objects on the screen using SDL. The main files involved in this project are `main.cpp`, `draw.h`, and `draw.cpp`.

## Features

- **Well-commented code**: All functions in the codebase are thoroughly commented. This makes the code easy to understand and maintain.
- **Flexible game object rendering**: The `draw` function can draw any texture at any position and rotation on the screen. This allows for a high degree of flexibility in rendering game objects.
- **Keyboard event handling**: The program includes comprehensive keyboard event handling, allowing for interactive control of game objects.
- **Use of SDL library**: The project makes extensive use of the SDL library for graphics rendering, making it a great example for those looking to learn about game development with SDL.

## main.cpp

The `main.cpp` file is the entry point of our program. It initializes SDL, creates a window and a renderer, and then enters the main loop where it handles keyboard events and calls the `draw` function.

## draw.h

The `draw.h` file contains the declaration of the `draw` function. This function is responsible for drawing the game objects on the screen. It takes a surface for drawing, a texture, x and y coordinates for placement, and an angle for rotating the texture.

## draw.cpp

The `draw.cpp` file contains the implementation of the `draw` function. It uses the SDL library to draw the texture on the given surface at the specified coordinates and rotation.

Here's a brief overview of the parameters:

- `loadedSurface`: This is the surface we will be drawing on.
- `a`: This is the texture we will be drawing.
- `x_move` and `y_move`: These are the x and y coordinates where we will place the texture on the surface.
- `alpha`: This is the angle we will rotate the texture by. It is measured in degrees, and we convert it to radians in the function.

Please refer to the source code in `draw.cpp` for more detailed information.

The result of running this function is a window displaying the game objects.
