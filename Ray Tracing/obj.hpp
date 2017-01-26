#ifndef obj_hpp
#define obj_hpp 
#include "Sphere.hpp"
#include "rt.hpp"

typedef struct object {
	Sphere sphere;
	color_t color;
	struct object *next;
} obj_t;

#endif