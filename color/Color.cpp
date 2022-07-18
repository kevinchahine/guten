#include "../pch.h"
#include "Color.h"

#include "../GutenExports.h"
#include "../termcolor/termcolor.hpp"

namespace guten
{
	namespace color
	{
		// --- Externs ---

		GUTEN_API const termcolor::Color blue(0, 0, 127);
		GUTEN_API const termcolor::Color green(0, 127, 0);
		GUTEN_API const termcolor::Color cyan(0, 127, 127);
		GUTEN_API const termcolor::Color red(127, 0, 0);
		GUTEN_API const termcolor::Color magenta(127, 0, 127);
		GUTEN_API const termcolor::Color yellow(255, 255, 0);
		GUTEN_API const termcolor::Color darkyellow(128, 128, 0);
		GUTEN_API const termcolor::Color lightblue(0, 0, 255);
		GUTEN_API const termcolor::Color lightgreen(0, 255, 0);
		GUTEN_API const termcolor::Color lightcyan(0, 255, 255);
		GUTEN_API const termcolor::Color lightred(255, 0, 0);
		GUTEN_API const termcolor::Color lightmagenta(255, 0, 255);
		GUTEN_API const termcolor::Color brown(127, 90, 0);
		GUTEN_API const termcolor::Color black(0, 0, 0);
		GUTEN_API const termcolor::Color gray(85, 85, 85);
		GUTEN_API const termcolor::Color lightgray(170, 170, 170);
		GUTEN_API const termcolor::Color white(255, 255, 255);
	} // namespace color
} // namespace guten