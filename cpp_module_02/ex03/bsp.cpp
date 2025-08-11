#include "Point.hpp"

// Calculate the area of triangle
// base * height / 2

static float triangleArea(const Point& p1, const Point& p2, const Point& p3)
{
	float x1 = p1.getX().toFloat();
	float y1 = p1.getY().toFloat();

	float x2 = p2.getX().toFloat();
	float y2 = p2.getY().toFloat();

	float x3 = p3.getX().toFloat();
	float y3 = p3.getY().toFloat();

	float area = std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f;
	return area;
}

/**
 *	a , b  and c (are the vertix of triangle)
 *	point : the point to check if exist inside the triangle
 *
 *	@return :
 *	true (if the point is inside the triangle)
 *	false (not find)
 *	info here: https://stackoverflow.com/a/2049593/11362525
 *
 */

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float A = triangleArea(a, b, c);
	float A1 = triangleArea(point, b, c);
	float A2 = triangleArea(a, point, c);
	float A3 = triangleArea(a, b, point);

	if (roundf(A1) == 0 || roundf(A2) == 0 || roundf(A3) == 0)
		return false;

	float sum = A1 + A2 + A3;

	if (roundf(sum) == roundf(A))
		return true;
	return (false);
}
