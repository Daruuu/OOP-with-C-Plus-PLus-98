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
/*
float triangleArea(const Point& p1, const Point& p2, const Point& p3)
{
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    std::cout << "\n--- triangleArea debug ---\n";
    std::cout << "P1: (" << x1 << ", " << y1 << ")\n";
    std::cout << "P2: (" << x2 << ", " << y2 << ")\n";
    std::cout << "P3: (" << x3 << ", " << y3 << ")\n";

    float term1 = x1 * (y2 - y3);
    float term2 = x2 * (y3 - y1);
    float term3 = x3 * (y1 - y2);

    std::cout << "term1 = x1 * (y2 - y3) = " << x1 << " * (" << y2 << " - " << y3 << ") = " << term1 << "\n";
    std::cout << "term2 = x2 * (y3 - y1) = " << x2 << " * (" << y3 << " - " << y1 << ") = " << term2 << "\n";
    std::cout << "term3 = x3 * (y1 - y2) = " << x3 << " * (" << y1 << " - " << y2 << ") = " << term3 << "\n";

    float area = std::abs(term1 + term2 + term3) / 2.0f;
    std::cout << "sum = term1 + term2 + term3 = " << (term1 + term2 + term3) << "\n";
    std::cout << "area = abs(sum) / 2 = " << area << "\n";
    std::cout << "--------------------------\n";

    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A = triangleArea(a, b, c);
    float A1 = triangleArea(point, b, c);
    float A2 = triangleArea(a, point, c);
    float A3 = triangleArea(a, b, point);

    std::cout << "\n--- bsp debug ---\n";
    std::cout << "A  (main triangle) = " << A << "\n";
    std::cout << "A1 = " << A1 << "\n";
    std::cout << "A2 = " << A2 << "\n";
    std::cout << "A3 = " << A3 << "\n";

    if (roundf(A1) == 0 || roundf(A2) == 0 || roundf(A3) == 0) {
        std::cout << "Point is on edge or vertex → FALSE\n";
        return false;
    }

    float sum = A1 + A2 + A3;
    std::cout << "sum(A1+A2+A3) = " << sum << "\n";
    std::cout << "roundf(sum) = " << roundf(sum) << ", roundf(A) = " << roundf(A) << "\n";

    if (roundf(sum) == roundf(A)) {
        std::cout << "Point is inside triangle → TRUE\n";
        return true;
    } else {
        std::cout << "Point is outside triangle → FALSE\n";
        return false;
    }
}
*/
