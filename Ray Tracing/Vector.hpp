#ifndef Vector_hpp
#define Vector_hpp

class Vector{
private:
	double x,y,z;
public:
	Vector(void){};
	Vector(double x, double y, double z);
	void set(double x, double y, double z);
	double dot(Vector v2);
	void normalize(void);
	Vector add(Vector v2);
	Vector operator+(Vector v2);
	Vector subtract(Vector v2);
	Vector operator-(Vector v2);
	Vector scalar_multiply(double v2);
	Vector multiply(Vector v2);
	Vector operator*(Vector v2);
	Vector operator*(double v2);
	Vector divide(Vector v2);
	Vector scalar_divide(double v2);
	Vector operator/(double v2);
	Vector operator/(Vector v2);
};

#endif