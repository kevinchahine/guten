#include "pch.h"
#include "iocolor.h"

GUTEN_API std::ostream & operator<<(std::ostream & os, const guten::color::Color & rhs)
{
	os << guten::color::setcolor(rhs.getcolor());

	return os;
}