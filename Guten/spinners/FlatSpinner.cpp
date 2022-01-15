#include "../pch.h"
#include "FlatSpinner.h"

using namespace std;

namespace guten
{
	namespace spinners
	{
		static const char chars[] =
		{
			'|',	// 0
			'/',	// 1
			'-',	// 2
			'\\'	// 3
		};

		GUTEN_API ostream & operator<<(ostream & os, FlatSpinner & spinner)
		{
			os << chars[spinner.state % sizeof(chars)];
			spinner.state++;

			return os;
		}
	} // namespace spinners
} // namespace guten
