#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x_;
	const Fixed y_;

public:
	Point();
	Point(const float numFloatOne, const float numFloatTwo);
	Point(const Point& other); //copy constructor
	Point& operator=(const Point& other); //copy operator overload
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif //POINT_HPP
