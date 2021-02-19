#include "pch.h"

#include "ColorHelpers.h"
#include "Color.h"
#include "iocolor.h"

#include <iomanip>
using namespace std;

namespace guten
{
	namespace color
	{
		GUTEN_API void printAllColors(std::ostream & os)
		{
			os << push() << left
				<< red << setw(12) << "red" << setbg( red ) << "    "
				<< setbg(lightred) << "    " << lightred << setw(12) << "lightred" << '\n'

				<< magenta << setw(12) << "magenta" << setbg(magenta) << "    "
				<< setbg(lightmagenta) << "    " << lightmagenta << setw(12) << "lightmagenta" << '\n'

				<< blue << setw(12) << "blue" << setbg(blue) << "    "
				<< setbg(lightblue) << "    " << lightblue << setw(12) << "lightblue" << '\n'

				<< cyan << setw(12) << "cyan" << setbg(cyan) << "    "
				<< setbg(lightcyan) << "    " << lightcyan << setw(12) << "lightcyan" << '\n'

				<< green << setw(12) << "green" << setbg(green) << "    "
				<< setbg(lightgreen) << "    " << lightgreen << setw(12) << "lightgreen" << '\n'

				<< brown << setw(12) << "brown" << setbg(brown) << "    "
				<< setbg(yellow) << "    " << yellow << setw(12) << "yellow" << '\n'

				<< white.inverted() << setw(12) << "black" << setbg(black) << "    "
				<< setbg(gray) << "    " << gray << setw(12) << "gray" << '\n'

				<< lightgray << setw(12) << "lightgray" << setbg(lightgray) << "    "
				<< setbg(white) << "    " << white << setw(12) << "white" << '\n'

				<< '\n';
		}
	} // namespace color
} // namespace guten