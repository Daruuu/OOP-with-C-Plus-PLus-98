#include "Point.hpp"

Point::Point() : x_(0), y_(0)
{
}

//	when is constant variables we need to init in the same line
//	constructor with float parameters
Point::Point(const float numFloatOne, const float numFloatTwo) :
	x_(numFloatOne), y_(numFloatTwo)
{
}

//	Copy constructor
Point::Point(const Point& other) : x_(other.x_), y_(other.y_)
{
}

Point::~Point()
{
	std::cout << RED "Destructor POINT called" RESET << std::endl;
}

Fixed Point::getX() const
{
	return x_;
}

Fixed Point::getY() const
{
	return y_;
}
