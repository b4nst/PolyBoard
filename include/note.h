#ifndef NOTE_H
#define NOTE_H

#define OCTAVE 12

enum ScaleIndex {
  MAJOR_SCALE = 0,
  MINOR_SCALE,
};

static const short scales[][12] = {{1, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, 0},
                                   {1, -1, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1}};

/**
 * @brief Checks if a note is in a scale.
 * @param note The note to check.
 * @param scale The root note of the scale.
 * @param scale_index The index of the scale table.
 * @return -1 if the note is not in the scale, 0 if it is, 1 if it is and it's
 * the root note.
 */
short is_note_in_scale(unsigned char note, unsigned char scale,
                       int scale_index);

#endif // NOTE_H
