
Rabewar Moradi - 1702601

	Collaborated with:
		- Syed Hasan Tamid - 1779230
		- Gavin Vickers - 1838216


#include "2DMotion.h"

Point::Point()
    : m_x(0), m_y(0)
{}

Point::Point(float x, float y)
    : m_x(x), m_y(y)
{}

Point::Point(const Point& p)
    : m_x(p.m_x), m_y(p.m_y)
{

}

std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.m_x;
    is >> point.m_y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& point) {
    os << "(" << point.m_x << ", " << point.m_y << ")";
    return os;
}

Point& operator+(Point& p, Force& f) {
    int f_x = cos(f.getAngle()) * f.getMag();
    int f_y = sin(f.getAngle()) * f.getMag();

    p.m_x += f_x;
    p.m_y += f_y;

    Point new_point = Point(p);

    return new_point;
}

int Point::quadrant() {
    float angle = atan(m_y / m_x);
    int quadrant = (angle / 90) + 1;

    return quadrant;
}

// Force

Force::Force()
    : m_mag(0), m_angle(0)
{}

Force::Force(float mag, float angle)
    : m_mag(mag), m_angle(angle)
{}

std::istream& operator>>(std::istream& is, Force& force) {
    is >> force.m_mag;
    is >> force.m_angle;
    return is;
}

std::ostream& operator<<(std::ostream& os, Force& force) {
    os << force.m_angle << " degrees with magnitude of " << force.m_mag;
    return os;
}

Force& operator*(Force& f, float& scalar) {
    f.m_mag *= scalar;
    return f;
}

float Force::getMag() {
    return m_mag;
}

float Force::getAngle() {
    return m_angle;
}
