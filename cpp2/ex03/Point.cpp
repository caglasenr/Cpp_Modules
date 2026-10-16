#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

/*
** _x and _y are const: they can only be set in the constructor's
** initializer list and can never be reassigned afterwards.
** The assignment operator therefore has nothing it is allowed to copy.
*/
Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Point::~Point()
{
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}
