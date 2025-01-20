#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 700
#define CELL_WIDTH 25
#define LINE_WIDTH 1
#define CENTER_WIDTH SCREEN_WIDTH / 2
#define CENTER_HEIGHT SCREEN_HEIGHT / 2

void draw_x_y(SDL_Renderer *renderer) {

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_Rect rect = (SDL_Rect){CENTER_WIDTH - 5, CENTER_HEIGHT - 5, 10, 10};
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);

  SDL_Point x_left[2] = {
      (SDL_Point){CENTER_WIDTH, CENTER_HEIGHT},
      (SDL_Point){CENTER_WIDTH - CELL_WIDTH * 10, CENTER_HEIGHT}};
  SDL_Point x_right[2] = {
      (SDL_Point){CENTER_WIDTH, CENTER_HEIGHT},
      (SDL_Point){CENTER_WIDTH + CELL_WIDTH * 10, CENTER_HEIGHT}};

  SDL_Point y_up[2] = {
      (SDL_Point){CENTER_WIDTH, CENTER_HEIGHT},
      (SDL_Point){CENTER_WIDTH, CENTER_HEIGHT - CELL_WIDTH * 10}};

  SDL_Point y_down[2] = {
      (SDL_Point){CENTER_WIDTH, CENTER_HEIGHT},
      (SDL_Point){CENTER_WIDTH, CENTER_HEIGHT + CELL_WIDTH * 10}};

  SDL_RenderDrawLines(renderer, x_left, 2);
  SDL_RenderDrawLines(renderer, x_right, 2);
  SDL_RenderDrawLines(renderer, y_up, 2);
  SDL_RenderDrawLines(renderer, y_down, 2);
}

void draw_grid(SDL_Renderer *renderer) {
  // ROW
  for (size_t i = CELL_WIDTH; i < SCREEN_HEIGHT; i += CELL_WIDTH) {
    SDL_Rect rect = (SDL_Rect){0, i, SCREEN_WIDTH, LINE_WIDTH};
    SDL_SetRenderDrawColor(renderer, 169, 169, 169, 1);
    SDL_RenderFillRect(renderer, &rect);
  }

  // COLUMN
  for (size_t i = CELL_WIDTH; i < SCREEN_WIDTH; i += CELL_WIDTH) {
    SDL_Rect rect = (SDL_Rect){i, 0, LINE_WIDTH, SCREEN_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 169, 169, 169, 1);

    SDL_RenderFillRect(renderer, &rect);
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("Hello coordinate", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 900, 700, 0);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
  SDL_RenderClear(renderer);

  SDL_Event event;
  int running = 1;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        running = 0;
    }
    draw_grid(renderer);
    draw_x_y(renderer);

    SDL_Delay(16);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}