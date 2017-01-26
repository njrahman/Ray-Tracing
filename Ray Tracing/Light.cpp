#include "Light.hpp"
#include "obj.hpp"
#include <math.h>

Light::Light(double x, double y, double z){
	Vector loc(x,y,z);
	this->loc = loc;
}


color_t Light::illuminate(ray_t ray, color_t closest_obj_color, Vector int_pt, Vector normal){
	color_t color;
	Light light;
	double dot, dot_2;
	Vector reflected;
	Vector L;
	normal.normalize();

	//ambient
	color.R = 0.1 * closest_obj_color.R;
	color.G = 0.1 * closest_obj_color.G;
	color.B = 0.1 * closest_obj_color.B;

	// diffuse
	L = this->loc - int_pt;
	L.normalize();
	dot = L.dot(normal);
	if (dot > 0){
		color.R += dot * closest_obj_color.R;
		color.G += dot * closest_obj_color.G;
		color.B += dot * closest_obj_color.B;
		//specular
		reflected = L - (normal * dot) * 2;
		reflected.normalize();
		dot_2 = reflected.dot(ray.dir);
		if (dot_2 > 0){
			color.R += pow(dot_2, 200);
			color.G += pow(dot_2, 200);
			color.B += pow(dot_2, 200);
		}
	}

	return color;
}