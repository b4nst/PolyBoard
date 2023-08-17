#include "layout.h"

void render_layout(const int layout[PAD_COUNT]) {
  int r, g, b;

  for (int i = 0; i < PAD_COUNT; i++) {
    r = (layout[i] & 0xFF0000) >> 16;
    g = (layout[i] & 0x00FF00) >> 8;
    b = (layout[i] & 0x0000FF);
    hal_plot_led(TYPEPAD, PAD_INDEXES[i], r, g, b);
  }
}
