#ifndef UTILITY_H
#define UTILITY_H

/* Converts 2D x,y indices to a 1D index */
inline unsigned toIndex(
    unsigned x,
    unsigned y,
    unsigned yMax
) {
    return x * yMax + y;
}

#endif
