#include <iostream>
#include <math.h>

class Vector
{
public:
    Vector(double x, double y, double z) :
        _x(x), _y(y), _z(z) {}
    ~Vector() {}
    double norm() const
    {
        return std::sqrt(_x * _x + _y * _y + _z * _z);
    }
    double dot(const Vector& vec) const
    {
        return _x * vec.x() + _y * vec.y() + _z * vec.z();
    }
    Vector cross(const Vector& vec) const
    {
        return Vector(
            _y * vec.z() - _z * vec.y(),
            -_x * vec.z() + _z * vec.x(),
            _x * vec.y() - _y * vec.x()
        );
    }
    void normalize()
    {
        const double curNorm = norm();
        _x /= curNorm;
        _y /= curNorm;
        _z /= curNorm;
    }

    Vector normalized() const
    {
        const double curNorm = norm();
        return Vector(_x / curNorm, _y / curNorm, _z / curNorm);
    }

    friend std::istream& operator>>(std::istream& cin, Vector& c)
    {
        std::cin >> c._x >> c._y >> c._z;
        return std::cin;
    }
    friend std::ostream& operator << (std::ostream&, const Vector& c)
    {
        std::cout << "{" << c._x << ", " << c._y << ", " << c._z << "}" << std::endl;
        return std::cout;
    }

    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }
private:
    double _x;
    double _y;
    double _z;
};

class Quat {
public:
    Quat(double w, double x, double y, double z) :
        _w(w), _x(x), _y(y), _z(z) {}
    Quat() {}
    Quat(double w, const Vector& vec):
    _w(w), _x(vec.x()), _y(vec.y()), _z(vec.z()) {}
    Quat(const Vector& vec) :
        _w(0), _x(vec.x()), _y(vec.y()), _z(vec.z()) {}
    friend std::istream& operator>>(std::istream& cin, Quat& c)
    {
        std::cin >> c._w >> c._x >> c._y >> c._z;
        return std::cin;
    }
    friend std::ostream& operator << (std::ostream&, const Quat& c)
    {
        std::cout << "{" << c._w << ", " << c._x << ", " << c._y << ", " << c._z << "}" << std::endl;
        return std::cout;
    }
    double norm() const { return sqrt(_w * _w + _x * _x + _y * _y + _z * _z); }
    Vector vec() const { return Vector{ _x, _y, _z }; }
    Quat operator * (const Quat& q)
    {
        return Quat(_w * q.w() - _x * q.x() - _y * q.y() - _z * q.z(), _y * q.z() - _z * q.y(), -_x * q.z() + _z * q.x(), _x * q.y() - _y * q.x());
    }
    void normalize() {
        double curNorm = norm();
        _w /= curNorm;
        _x /= curNorm;
        _y /= curNorm;
        _z /= curNorm;
    }
    Quat normalized() const {
        double curNorm = norm();
        return Quat{
          _w / curNorm,
          _x / curNorm,
          _y / curNorm,
          _z / curNorm
        };
    }
    double w() const { return _w; }
    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }
private:
    double _w ;
    double _x ;
    double _y ;
    double _z ;
};


int main()
{
    while (true)
    {
    Quat Q1;
    Quat Q2;
    std::cin >> Q1 >> Q2;
    std::cout << Q1 << Q2 << std::endl;
    std::cout << Q1 * Q2 << std::endl;
    }

}
