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

			os << setfill('\b') << setw(100) << '\b';

			os.flags(flags);
		}
	} // namespace core
} // namespace guten