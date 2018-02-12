#ifndef DIAMOND_H
#define DIAMOND_H

#include "Shape.h"
#include "Cone.h"

class Diamond : public Shape {
public:
	Diamond() {};
	~Diamond() {};
	
	void draw() {
	};

	void drawNormal(){};

protected:
	PVList getPoints(int segX, int segY){

		if ((int)pvs.size() != segX * (segY + 2)) {
			// free memory
			pvs.clear();
			PVList().swap(pvs);

			double r = DEFAULT_LENGTH;
			double angle_x = 2 * PI / segX;
			int upper_y, lower_y;

			PVList side;

			// segY parity
			if (segY % 2 == 0) {
				upper_y = segY / 2;
				lower_y = segY / 2;
			} else {
				upper_y = segY / 2 + 1;
				lower_y = segY / 2;
			}

			// upper cone
			for (int i = 0; i < upper_y + 1; i++){
				Point p(
					r * ( i / float(upper_y) ),
					DEFAULT_LENGTH - ( i / float(upper_y) ) / 2,
					0
				);
				Vector v(0.5f, 0.5f, 0);
				v.normalize();
				PV pv = {p, v};
				side.push_back(pv);
			}
			// lower cone
			for (int i = 0 ; i < lower_y + 1; i++){
				Point p(
					r * ( lower_y - i ) / float(lower_y),
					-DEFAULT_LENGTH + ( lower_y - i ) / float(lower_y) / 2,
					0
				);
				Vector v(0.5f, -0.5f, 0);
				v.normalize();
				PV pv = {p, v};
				side.push_back(pv);
			}
			// rotate the side
			for (int i = 0 ; i < segX; i++){
				Matrix mtx = rotY_mat( i * angle_x );
				PVList rotSide = rotatePVs(mtx, side);
				pvs.insert(pvs.end(), rotSide.begin(), rotSide.end());
			}

		}

		return pvs;

	};

	Surface getSurface(int segX, int segY){

		if ( int(surface.size()) != segX * ((segY - 1) * 2 + 2) ){
			surface.clear();
			Surface().swap(surface);

			int upper_y, lower_y;
			// segY parity
			if (segY % 2 == 0) {
				upper_y = segY / 2;
				lower_y = segY / 2;
			} else {
				upper_y = segY / 2 + 1;
				lower_y = segY / 2;
			}

			for (int i = 0; i < segX; i++){
				int ri = (i + 1) % segX; // right line index
				// upper cone
				for (int j = 0; j < upper_y + 1; j++){
					if ( j == 0 ){
						surface.push_back(toTriangle(
							0,
							toIndex(i, j + 1, segY + 2),
							toIndex(ri, j + 1, segY + 2)
						));
					} else {
						surface.push_back(toTriangle(
							toIndex(i, j, segY + 2 ),
							toIndex(i, j + 1, segY + 2 ),
							toIndex(ri, j + 1, segY + 2 )
						));
						surface.push_back(toTriangle(
							toIndex(i, j, segY + 2),
							toIndex(ri, j + 1, segY + 2),
							toIndex(ri, j, segY + 2)
						));
					}
				}
				// lower cone
				for (int j = 1; j < lower_y + 1; j++){

					if ( j == lower_y) { // bottom
						surface.push_back(toTriangle(
							toIndex(i, j + upper_y, segY + 2),
							int( pvs.size() - 1 ),
							toIndex(ri, j + upper_y, segY + 2)
						));
					} else {
						surface.push_back(toTriangle(
							toIndex(i, j + upper_y, segY + 2),
							toIndex(i, j + upper_y + 1, segY + 2),
							toIndex(ri, j + upper_y + 1, segY + 2)
						));
						surface.push_back(toTriangle(
							toIndex(i, j + upper_y, segY + 2),
							toIndex(ri, j + upper_y + 1, segY + 2),
							toIndex(ri, j + upper_y, segY + 2)
						));
					}
				}
			}


		}

		return surface;
	};

};

#endif