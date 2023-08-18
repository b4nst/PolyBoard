#include "layout.h"

void render_grid(const u32 layout[GRID_SIZE]) {
  u8 red = 0;
  u8 green = 0;
  u8 blue = 0;

  for (int i = 0; i < GRID_SIZE; i++) {
    red = (layout[i] & COLOR_RED) >> COLOR_RED_SHIFT;
    green = (layout[i] & COLOR_GREEN) >> COLOR_GREEN_SHIFT;
    blue = (layout[i] & COLOR_BLUE) >> COLOR_BLUE_SHIFT;
    hal_plot_led(TYPEPAD, i, red, green, blue);
  }
}
