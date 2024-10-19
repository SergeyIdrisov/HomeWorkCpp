#include <iostream>
#include <math.h>

using namespace std;

class Vector
{ 
public:
	Vector(double x, double y, double z):
		_x(x), _y(y), _z(z) {}
	~Vector() {}
	double norm() const { return sqrt(_x*_x + _y*_y + _z*_z); }
	double dot(const Vector& vec) {return _x * vec.xGet() + _y * vec.yGet() + _z * vec.zGet();}
	Vector cross(const Vector& vec) { return Vector(
		_y*vec.zGet() - _z * vec.yGet(),
		-_x*vec.zGet() + _z*vec.xGet(),
		_x*vec.yGet() - _y*vec.xGet(); }
	double xGet const () { return _x; }
	double yGet const () { return _y; }
	double zGet const () { return _z; }
private:
	double _x;
	double _y;
	double _z;
};
int main() {
	Vector a{ 1,0,0 };
	Vector b{ 1,0,0 };
	auto c = a.cross(b);
	cout << c.xGet() << " " << c.yGet() << " " << c.zGet() << endl;
}
