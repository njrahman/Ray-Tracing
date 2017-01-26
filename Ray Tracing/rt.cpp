#include "rt.hpp"
#include "Sphere.hpp"
#include "obj.hpp"
#include "Light.hpp"
#include <iostream>


void read_objs(obj_t **list){
	obj_t *node;
	double cx, cy, cz, rad;
	double R, G, B;
	*list = NULL;
	
	while(std::cin >> cx >> cy >> cz >> rad >> R >> G >> B ){
		
		node = new obj_t;
		
		node->sphere.set(cx, cy, cz, rad);
		node->color.R = R;
		node->color.G = G;
		node->color.B = B;
		node->next = *list;
		
		*list = node;
	}
}

color_t trace(ray_t ray, obj_t *list, Light light){
	obj_t *curr;
	obj_t *closest_obj;
	double t;
	double min_t = 1000.0;
	color_t color;
	color.R = 0;
	color.G = 0;
	color.B = 0;
	Vector int_pt;
	Vector normal;
	Vector closest_int_pt;
	Vector closest_normal;

	closest_obj = NULL;
	
	for(curr = list; curr != NULL; curr = curr->next){
		if (curr->sphere.intersect(ray, t, int_pt, normal)){
			if (t < min_t){
				min_t = t;
				closest_obj = curr;
				closest_int_pt = int_pt;
				closest_normal = normal;
				color = curr->color;
			}
		}
	}

	if (closest_obj != NULL){
		color = light.illuminate(ray, color, closest_int_pt, closest_normal);
	}
	return color;
}





int main()
{
	//initilization
	Sphere sphere;
	ray_t ray;
	obj_t *list;
	color_t color;
	Light light(5.0, 10.0, 0.0);
	int x;
	int y;
	double t;
	
	//reads file
	read_objs(&list);
	
	//PPM initialization line
	std::cout << "P6\n1000 1000\n255\n";
	
	//Iterates through each pixel and writes the color we want into it
	for(y = 0; y < 1000; y++){
		for(x = 0; x < 1000; x++){
			
			ray.orig.set(0.0, 0.0, 0.0);
			ray.dir.set(-0.5 + x/1000.0, 0.5 - y/1000.0, 1);
			ray.dir.normalize();
			
			color = trace(ray, list, light);
			
			if (color.R > 1.0){
				color.R = 1.0;
			}
			if (color.G > 1.0){
				color.G = 1.0;
			}
			if (color.B > 1.0){
				color.B = 1.0;
			}
			
			std::cout << (unsigned char)(color.R * 255) << (unsigned char)(color.G * 255) << (unsigned char)(color.B * 255);
		}
	}
	return 0;
}