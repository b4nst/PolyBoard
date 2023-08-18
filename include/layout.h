#ifndef LAYOUT_H
#define LAYOUT_H

#include "app.h"
#include "app_defs.h"
#include "colors.h"

#define GRID_SIZE 100

static const u32 GRID_LOGO[GRID_SIZE] = {
    [25] = COLOR_MAGENTA, [26] = COLOR_MAGENTA, [35] = COLOR_MAGENTA,
    [37] = COLOR_MAGENTA, [46] = COLOR_MAGENTA, [47] = COLOR_MAGENTA,
    [57] = COLOR_MAGENTA,

    [42] = COLOR_TEAL,    [52] = COLOR_TEAL,    [53] = COLOR_TEAL,
    [62] = COLOR_TEAL,    [64] = COLOR_TEAL,    [73] = COLOR_TEAL,
    [74] = COLOR_TEAL,
};

/**
 * Renders the full grid
 *
 * @param layout The layout to render.
 */
void render_grid(const u32 layout[GRID_SIZE]);

#endif // LAYOUT_H
