#include "Vector.hpp"
#include <math.h>


Vector::Vector(double x, double y, double z){
	this->set(x,y,z);
}

void Vector::set(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::dot(Vector v2){
	return(this->x*v2.x + this->y*v2.y + this->z*v2.z);
}

void Vector::normalize(void){
	double length = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);

	this->x = (this->x / length);
	this->y = (this->y / length);
	this->z = (this->z / length);
}

Vector Vector::add(Vector v2){
	Vector ret;
	ret.x = this->x + v2.x;
	ret.y = this->y + v2.y;
	ret.z = this->z + v2.z;

	return ret;
}

Vector Vector::operator+(Vector v2){
	return this->add(v2);
}

Vector Vector::subtract(Vector v2){
	Vector ret;
	ret.x = this->x - v2.x;
	ret.y = this->y - v2.y;
	ret.z = this->z - v2.z;

	return ret;
}

Vector Vector::operator-(Vector v2){
	return this->subtract(v2);
}

Vector Vector::scalar_multiply(double v2){
	Vector ret;
	ret.x = this->x * v2;
	ret.y = this->y * v2;
	ret.z = this->z * v2;

	return ret;
}

Vector Vector::multiply(Vector v2){
	Vector ret;
	ret.x = this->x * v2.x;
	ret.y = this->y * v2.y;
	ret.z = this->z * v2.z;

	return ret;
}

Vector Vector::operator*(Vector v2){
	return this->multiply(v2);
}

Vector Vector::operator*(double v2){
	return this->scalar_multiply(v2);
}

Vector Vector::divide(Vector v2){
	Vector ret;
	ret.x = this->x / v2.x;
	ret.y = this->y / v2.y;
	ret.z = this->z / v2.z;

	return ret;
}

Vector Vector::scalar_divide(double v2){
	Vector ret;
	ret.x = this->x / v2;
	ret.y = this->y / v2;
	ret.z = this->z / v2;

	return ret;
}

Vector Vector::operator/(Vector v2){
	return this->divide(v2);
}

Vector Vector::operator/(double v2){{
	return this->scalar_divide(v2);
}}