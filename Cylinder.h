#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

class Cylinder : public Shape {
public:
    Cylinder() {};
    ~Cylinder() {};

protected:
    PVList getPoints(int segX, int segY) {
        if ((int)pvs.size() != segX * (segY + 1) + 2) {
            pvs.clear();
            PVList().swap(pvs); // free memory

            double ax = 2 * PI / segX;
            double r = DEFAULT_LENGTH; // radius

            for (int x = 0; x < segX; x++) {
                for (int y = 0; y < segY + 1; y++) {
                    Point p(
                        r * cos(x * ax),
                        DEFAULT_LENGTH - y / (double)segY,
                        r * sin(x * ax)
                    );
                    Vector v(
                        r * cos(x * ax),
                        0,
                        r * sin(x * ax)
                    );
                    v.normalize();
                    PV pv = {p, v};

                    pvs.push_back(pv);
                }
            }

            PV top = {Point(0, DEFAULT_LENGTH, 0), Vector(0, 1, 0)};
            PV bot = {Point(0, -DEFAULT_LENGTH, 0), Vector(0, -1, 0)};
            pvs.push_back(top);
            pvs.push_back(bot);
        }
        return pvs;
    }

    Surface getSurface(int segX, int segY) {
        if ((int)surface.size() != segX * (2 * segY + 2)) {
            surface.clear();
            Surface().swap(surface); // free memory

            // for (int x = 0; x < segX; x++) {
            //     for 
            // }
        }
        return surface;
    }
};
#endif
