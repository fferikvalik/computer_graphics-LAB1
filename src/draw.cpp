#include "draw.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#define RGB32(r, g, b) static_cast<uint32_t>((((static_cast<uint32_t>(b) << 8) | g) << 8) | r)

void put_pixel32(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  assert(NULL != surface);
  assert(x < SCREEN_WIDTH);
  assert(y < SCREEN_HEIGHT);

  Uint32 *pixels = (Uint32 *)surface->pixels;
  pixels[(y * surface->w) + x] = pixel;
}

Uint32 get_pixel32(SDL_Surface *surface, int x, int y)
{
  assert(NULL != surface);
  assert(x < SCREEN_WIDTH);
  assert(y < SCREEN_HEIGHT);

  Uint32 *pixels = (Uint32 *)surface->pixels;
  return pixels[(y * surface->w) + x];
}

void draw(SDL_Surface *s)
{
  glm::vec4 Position = glm::vec4(glm::vec3(0.0f), 1.0f);
  glm::mat4 Model = glm::translate(    glm::mat4(1.0f), glm::vec3(1.0f));
  glm::vec4 Transformed = Model * Position;

  // Ваш код
  // ...
  for (int i = 30; i < 100; i++)
    for (int j = 30; j < 100; j++)
      put_pixel32(s, i, j, 0x00FF0000);

  // Формат цвета в HEX коде:
  //     0x00RRGGBB
  //  где R: от 00 до FF
  //      G: от 00 до FF
  //      B: от 00 до FF

  for (int i = 100; i < 200; i++)
    for (int j = 100; j < 180; j++)
      put_pixel32(s, i, j, RGB32(0, 255, 0));

  // или использу¤ макрос можно получить код цвета:
  //   RGB32(0, 255, 0) эквивалентно записи 0x0000FF00
}

void drawCardioid(SDL_Surface* surface, float a){
  if (surface == nullptr) return;

  Uint32* pixels = (Uint32*)surface->pixels;

  Uint32 redColor = SDL_MapRGB(surface->format, 255, 0, 0);

  for (float t = 0; t<2 * M_PI; t+= 0.001f){

    float x = a*cos(t) * (1 +cos(t));
    float y = a*sin(t) * (1+ cos(t));

    int screen_x = static_cast<int>(x + SCREEN_WIDTH/2);
    int screen_y = static_cast<int>(x + SCREEN_HEIGHT/2);

    if(screen_x >= 0 && screen_x < SCREEN_WIDTH && screen_y < SCREEN_HEIGHT && screen_y >= 0){

        pixels[screen_y * SCREEN_WIDTH + screen_x] = redColor;

    }

  }

  int ax = static_cast<int>(2 * a + SCREEN_WIDTH / 2);
  int ay = SCREEN_HEIGHT / 2;
  pixels[ay * SCREEN_WIDTH + ax] = redColor;

  float xc = 3 * a / 4;
  float yc = sqrt(3) * xc;
  int screen_xc = static_cast<int>(xc + SCREEN_WIDTH / 2);
  int screen_yc = static_cast<int>(SCREEN_HEIGHT / 2 - yc);
  int screen_yd = static_cast<int>(SCREEN_HEIGHT / 2 + yc);

  pixels[screen_yc * SCREEN_WIDTH + screen_xc] = redColor;
  pixels[screen_yd * SCREEN_WIDTH + screen_xc] = redColor;
}

