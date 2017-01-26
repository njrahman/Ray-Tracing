#ifndef rt_hpp
#define rt_hpp 
#include "Vector.hpp"

typedef struct {
	Vector orig;
	Vector dir;
}ray_t;

typedef struct {
	double R;
	double G;
	double B;
} color_t;

#endif