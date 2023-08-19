#ifndef SURFACE_H
#define SURFACE_H

enum SurfaceKeyType { SURFACE_PAD, SURFACE_CTRL };

/**
 * @brief index_to_surface_key_type Convert an index to a SurfaceKeyType
 * @param index The index to convert
 * @return The SurfaceKeyType
 */
enum SurfaceKeyType index_to_surface_key_type(unsigned char index);

struct NoteParams {
  unsigned char root;
  unsigned char octave;
  unsigned char interval;
} __attribute__((aligned(4)));

/**
 * @brief index_to_note Convert an index of the surface to a note
 * @param index The index to convert
 * @param params The note parameters
 * @param scale The scale to use
 * @return The note
 */
unsigned char index_to_note(unsigned char index,
                            const struct NoteParams *params,
                            const unsigned char scale[8]);

#endif // SURFACE_H
