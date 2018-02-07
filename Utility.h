#ifndef UTILITY_H
#define UTILITY_H

/* Converts 2D x,y indices to a 1D index */
unsigned int toIndex(
    unsigned int x,
    unsigned int y,
    unsigned int xMax,
    unsigned int yMax // technically unnecessary
) {
    return x * xMax + y;
}

#endif
