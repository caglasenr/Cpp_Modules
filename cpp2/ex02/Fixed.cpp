#include "Fixed.hpp"
#include <cmath>

/* ---------------- Orthodox Canonical Form ---------------- */

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return *this;
}

Fixed::~Fixed()
{
}

/* ---------------- Accessors / conversions ---------------- */

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> _fractionalBits;
}

/* ---------------- Comparison operators ---------------- */

bool Fixed::operator>(const Fixed &other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_value != other._value;
}

/* ---------------- Arithmetic operators ---------------- */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(((long)this->_value * other._value) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(((long)this->_value << _fractionalBits) / other._value);
	return result;
}

/* ---------------- Increment / decrement ---------------- */

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);

	this->_value++;
	return old;
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);

	this->_value--;
	return old;
}

/* ---------------- min / max ---------------- */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

/* ---------------- Stream insertion ---------------- */

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
