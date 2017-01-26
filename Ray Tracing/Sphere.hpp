#ifndef Sphere_hpp
#define Sphere_hpp
#include "Vector.hpp"

class Sphere{
private:
	Vector center;
	double radius;
public:
	Sphere(void){};
	Sphere(Vector center, double radius);
	Sphere(double x, double y, double z, double radius);
	void set(Vector center, double radius);
	void set(double x, double y, double z, double radius);
	bool intersect(ray_t ray, double &t, Vector &int_pt, Vector &normal);
};


#endif