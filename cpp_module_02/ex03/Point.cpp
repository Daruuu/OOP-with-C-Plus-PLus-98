#include "Point.hpp"

Point::Point() : x_(0), y_(0)
{
}

//	when is constant variables we need to init in the same line
Point::Point(const float numFloatOne, const float numFloatTwo) :
	x_(numFloatOne), y_(numFloatTwo)
{
	this->x_ = numFloatOne;
}

Point::Point(const Point& other)
{
}

Point& Point::operator=(const Point& other)
{
}

Point::~Point()
{
}
