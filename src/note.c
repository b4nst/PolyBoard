#include "note.h"

short is_note_in_scale(const unsigned char note, const unsigned char scale,
                       const int scale_index) {
  int idx = (note - scale) % OCTAVE;
  if (idx < 0) {
    idx += OCTAVE;
  }

  return scales[scale_index][idx];
}
