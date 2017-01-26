#ifndef Light_hpp
#define Light_hpp 

#include "Vector.hpp"
#include "rt.hpp"

class Light{
private:
	Vector loc;
public:
	Light(void){};
	Light(double x, double y, double z);
	Light(Vector loc);
	color_t illuminate(ray_t ray, color_t color, Vector int_pt, Vector normal);
};

#endif