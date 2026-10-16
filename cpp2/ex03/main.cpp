#include "Point.hpp"
#include <iostream>

static void test(const char *label, Point const &a, Point const &b,
					Point const &c, Point const &p, bool expected)
{
	bool result = bsp(a, b, c, p);

	std::cout << (result == expected ? "[OK] " : "[KO] ")
			  << label << " (" << p.getX() << ", " << p.getY() << ") -> "
			  << (result ? "inside" : "outside") << std::endl;
}

int main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 0.0f);
	Point const c(0.0f, 10.0f);

	std::cout << "Triangle: (0, 0) (10, 0) (0, 10)" << std::endl;
	test("inside           ", a, b, c, Point(2.0f, 2.0f), true);
	test("inside (near hyp)", a, b, c, Point(4.9f, 4.9f), true);
	test("outside          ", a, b, c, Point(8.0f, 8.0f), false);
	test("outside (neg)    ", a, b, c, Point(-1.0f, 3.0f), false);
	test("vertex           ", a, b, c, Point(0.0f, 0.0f), false);
	test("vertex           ", a, b, c, Point(10.0f, 0.0f), false);
	test("on edge (base)   ", a, b, c, Point(5.0f, 0.0f), false);
	test("on edge (hyp)    ", a, b, c, Point(5.0f, 5.0f), false);

	std::cout << "\nSame triangle, vertices in reverse order" << std::endl;
	test("inside           ", c, b, a, Point(2.0f, 2.0f), true);
	test("outside          ", c, b, a, Point(8.0f, 8.0f), false);

	std::cout << "\nTriangle with float vertices: (-2.5, -1) (3.5, -1) (0.5, 4.25)" << std::endl;
	Point const d(-2.5f, -1.0f);
	Point const e(3.5f, -1.0f);
	Point const f(0.5f, 4.25f);
	test("inside           ", d, e, f, Point(0.5f, 1.0f), true);
	test("outside          ", d, e, f, Point(3.0f, 3.0f), false);
	test("on edge          ", d, e, f, Point(0.0f, -1.0f), false);

	std::cout << "\nCopy / assignment" << std::endl;
	Point copy(f);
	Point assigned;
	assigned = f;
	std::cout << "copy     = (" << copy.getX() << ", " << copy.getY() << ")" << std::endl;
	std::cout << "assigned = (" << assigned.getX() << ", " << assigned.getY()
			  << ")  <- const members cannot be reassigned" << std::endl;

	return 0;
}
