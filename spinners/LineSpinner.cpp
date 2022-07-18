#include "../pch.h"
#include "LineSpinner.h"
#include "../lines/LineChar.h"

using namespace std;

namespace guten
{
	namespace spinners
	{
		static const char chars[] =
		{
			(lines::up + lines::right).as<char>(),		// 0
			(lines::right + lines::down).as<char>(),	// 1
			(lines::down + lines::left).as<char>(),		// 2
			(lines::left + lines::up).as<char>(),		// 3
		};

		GUTEN_API ostream & operator<<(ostream & os, LineSpinner & spinner)
		{
			os << chars[spinner.state % sizeof(chars)];
			spinner.state++;

			return os;
		}
	} // namespace spinners
} // namespace guten