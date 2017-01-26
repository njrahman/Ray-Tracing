#include "rt.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <math.h>

Sphere::Sphere(Vector center, double radius){
	this->set(center, radius);
}

Sphere::Sphere(double x, double y, double z, double radius){
	Vector center(x,y,z);
	this->set(center, radius);
}

void Sphere::set(Vector center, double radius){
	this->center = center;
	this->radius = radius;
}

void Sphere::set(double x, double y, double z, double radius){
	Vector center(x,y,z);
	this->center = center;
	this->radius = radius;
}

bool Sphere::intersect(ray_t ray, double &t, Vector &int_pt, Vector &normal){
	double A,B,C;
	double t0, t1;
	

	A = 1;
	B = (ray.dir.dot(ray.orig - this->center)) * 2;
	C = (ray.orig - this->center).dot(ray.orig - this->center) - (this->radius * this->radius); 

	

	if ((B*B - 4*A*C) < 0){
		return false;
	}

	//Checks both the + and - options for the quadratic equation
	t0 = (-B + sqrt(B*B - 4*A*C)) / (2*A);
	t1 = (-B - sqrt(B*B - 4*A*C)) / (2*A);

	//Sphere is behind the origin
	if (t0 < 0 && t1 < 0){	
		return false;
	}

	//Else we just want the shorter distance
	else if (t0 < t1){
		t = t0;
	}

	else if (t1 < t0){
		t = t1;
	}

	int_pt = ray.orig + (ray.dir * t);
	normal = (int_pt - this->center) / radius;
	
	return true;
}