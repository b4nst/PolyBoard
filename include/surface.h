#ifndef SURFACE_H
#define SURFACE_H

enum SurfaceKeyType { SURFACE_PAD, SURFACE_CTRL };

/**
 * @brief index_to_surface_key_type Convert an index to a SurfaceKeyType
 * @param index The index to convert
 * @return The SurfaceKeyType
 */
enum SurfaceKeyType index_to_surface_key_type(unsigned char index);

#endif // SURFACE_H
