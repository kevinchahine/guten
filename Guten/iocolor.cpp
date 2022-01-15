#include "pch.h"
#include "iocolor.h"

namespace guten
{
	namespace color
	{
		// TODO: Linux: Fix this to make it cross platform compatible 
		#ifdef _WIN32
		GUTEN_API WORD currColor = Color::calcColor(Color::WHITE, Color::BLACK);
		GUTEN_API HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		GUTEN_API CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
		#endif // _WIN32
		
		GUTEN_API std::stack<std::ios_base::fmtflags> flags;
		GUTEN_API std::stack<WORD> colorStack;
	} // namespace color
} // namespace guten

GUTEN_API std::ostream & operator<<(std::ostream & os, const guten::color::Color & rhs)
{
	os << guten::color::setcolor(rhs.getcolor());

	return os;
}