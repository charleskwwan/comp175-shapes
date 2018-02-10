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

inline PVList rotatePVs(Matrix mtx, PVList lst) {
    PVList res;
    for (int i = 0; i < lst.size(); i++) {
        PV pv = lst[i];
        pv.p = mtx * pv.p;
        pv.v = mtx * pv.v;
        res.push_back(pv);
    }
    return res;
}

#endif
