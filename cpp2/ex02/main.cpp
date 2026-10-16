#include "Fixed.hpp"
#include <iostream>

static void extraTests(void)
{
	Fixed x(3.5f);
	Fixed y(2);
	Fixed const cx(1.25f);
	Fixed const cy(-4);

	std::cout << "\n--- extra tests ---" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "x + y  = " << (x + y) << std::endl;
	std::cout << "x - y  = " << (x - y) << std::endl;
	std::cout << "x * y  = " << (x * y) << std::endl;
	std::cout << "x / y  = " << (x / y) << std::endl;

	std::cout << std::boolalpha;
	std::cout << "x >  y : " << (x > y) << std::endl;
	std::cout << "x <  y : " << (x < y) << std::endl;
	std::cout << "x >= y : " << (x >= y) << std::endl;
	std::cout << "x <= y : " << (x <= y) << std::endl;
	std::cout << "x == y : " << (x == y) << std::endl;
	std::cout << "x != y : " << (x != y) << std::endl;
	std::cout << "y == Fixed(2.0f) : " << (y == Fixed(2.0f)) << std::endl;

	std::cout << "--y = " << --y << std::endl;
	std::cout << "y-- = " << y-- << std::endl;
	std::cout << "y   = " << y << std::endl;

	std::cout << "min(x, y)   = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y)   = " << Fixed::max(x, y) << std::endl;
	std::cout << "min(cx, cy) = " << Fixed::min(cx, cy) << std::endl;
	std::cout << "max(cx, cy) = " << Fixed::max(cx, cy) << std::endl;

	Fixed::max(x, y) = Fixed(100);
	std::cout << "after max(x, y) = 100 -> x = " << x << std::endl;
}

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	extraTests();
	return 0;
}
