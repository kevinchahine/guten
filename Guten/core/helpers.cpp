#include "../pch.h"
#include "helpers.h"

#include <iomanip>

using namespace std;

namespace guten
{
	namespace core 
	{
		void eraseLine(ostream & os)
		{
			auto flags = os.flags();

			// TODO: Make this better. This only will erase 101 characters from the line. 
			// How can we make it erase all characters without over doing it.
			// See this: https://man7.org/linux/man-pages/man4/console_codes.4.html
			// https://stackoverflow.com/questions/1799063/how-can-i-display-unicode-characters-in-a-linux-terminal-using-c
			os << setfill('\b') << setw(100) << '\b';

			os.flags(flags);
		}
	} // namespace core
} // namespace guten