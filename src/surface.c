#include "surface.h"

enum SurfaceKeyType index_to_surface_key_type(unsigned char index) {
  if (index >= 90) {
    return SURFACE_CTRL;
  }
  if (index <= 10) {
    return SURFACE_CTRL;
  }
  if (index % 10 == 9) {
    return SURFACE_CTRL;
  }
  if (index % 10 == 1) {
    return SURFACE_CTRL;
  }

  return SURFACE_PAD;
}

unsigned char index_to_note(const unsigned char index,
                            const struct NoteParams *params,
                            const unsigned char scale[8]) {
  unsigned char c_offset = scale[index % 10 - 1];
  unsigned char r_offset = (index / 10 - 1) * params->interval;

  return params->root + r_offset + c_offset + params->octave * 12;
}
