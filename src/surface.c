#include "surface.h"

enum SurfaceKeyType index_to_surface_key_type(unsigned char index) {
    if (index >= 90) { return SURFACE_CTRL; }
    if (index <= 10) { return SURFACE_CTRL; }
    if (index % 10 == 9) { return SURFACE_CTRL; }
    if (index % 10 == 1) { return SURFACE_CTRL; }
    
    return SURFACE_PAD; 
}
