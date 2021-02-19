#include "pch.h"
#include "LineChar.h"

namespace guten
{
	namespace lines
	{
		// Look up table for line characters:
		//	index - bitwise line character value where each bit corresponds to a direction
		//	value - printable line character value 
		//
		// Ex:
		//	cout << LINES[0b0000'0011];		// prints horizontal line character
		//
		// '#' are invalid line characters
		GUTEN_API const unsigned char LINES[] = {
		' ',								// 0000 0000	(space)
		'#', '#',
		static_cast<unsigned char>(196),	// 0000 0011	(horizontal)
		'#',
		static_cast<unsigned char>(218),	// 0000 0101
		static_cast<unsigned char>(191),	// 0000 0110
		static_cast<unsigned char>(194),	// 0000 0111
		'#',
		static_cast<unsigned char>(192),	// 0000 1001
		static_cast<unsigned char>(217),	// 0000 1010
		static_cast<unsigned char>(193),	// 0000 1011
		static_cast<unsigned char>(179),	// 0000 1100	(vertical)
		static_cast<unsigned char>(195),	// 0000 1101
		static_cast<unsigned char>(180),	// 0000 1110
		static_cast<unsigned char>(197),	// 0000 1111	(cross)
		'#', '#', '#', '#', '#',
		static_cast<unsigned char>(213),	// 0001 0101
		'#', '#', '#',
		static_cast<unsigned char>(212),	// 0001 1001
		'#', '#', '#',
		static_cast<unsigned char>(198),	// 0001 1101
		'#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(184),	// 0010 0110
		'#', '#', '#',
		static_cast<unsigned char>(190),	// 0010 1010
		'#', '#', '#',
		static_cast<unsigned char>(181),	// 0010 1110
		'#', '#', '#', '#',
		static_cast<unsigned char>(205),	// 0011 0011
		'#', '#', '#',
		static_cast<unsigned char>(209),	// 0011 0111
		'#', '#', '#',
		static_cast<unsigned char>(207),	// 0011 1011
		'#', '#', '#',
		static_cast<unsigned char>(216),	// 0011 1111
		'#', '#', '#', '#', '#',
		static_cast<unsigned char>(214),	// 0100 0101
		static_cast<unsigned char>(183),	// 0100 0110
		static_cast<unsigned char>(210),	// 0100 0111
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(201),	// 0101 0101
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(187),	// 0110 0110
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(203),	// 0111 0111
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(211), 	// 1000 1001
		static_cast<unsigned char>(189), 	// 1000 1010
		static_cast<unsigned char>(208), 	// 1000 1011
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(200), 	// 1001 1001
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(188), 	// 1010 1010
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(202), 	// 1011 1011
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(186), 	// 1100 1100
		static_cast<unsigned char>(199), 	// 1100 1101
		static_cast<unsigned char>(182), 	// 1100 1110
		static_cast<unsigned char>(215), 	// 1100 1111
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(204), 	// 1101 1101
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(185), 	// 1110 1110
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		static_cast<unsigned char>(206), 	// 1111 1111	// (double cross)
		};

		const size_t LINES_SIZE = sizeof(LINES) / sizeof(char);

		// Constants (used as indicies of LINES[])
		const unsigned char UP = (1 << 3);
		const unsigned char DOWN = (1 << 2);
		const unsigned char LEFT = (1 << 1);
		const unsigned char RIGHT = (1 << 0);
		const unsigned char DOUBLE_UP = (1 << 7) | UP;
		const unsigned char DOUBLE_DOWN = (1 << 6) | DOWN;
		const unsigned char DOUBLE_LEFT = (1 << 5) | LEFT;
		const unsigned char DOUBLE_RIGHT = (1 << 4) | RIGHT;

		// Short Names (used as indicies of LINES[])
		const unsigned char& DU = DOUBLE_UP;
		const unsigned char& DD = DOUBLE_DOWN;
		const unsigned char& DL = DOUBLE_LEFT;
		const unsigned char& DR = DOUBLE_RIGHT;
		const unsigned char& U = UP;
		const unsigned char& D = DOWN;
		const unsigned char& L = LEFT;
		const unsigned char& R = RIGHT;
	} // namespace lines
} // namespace guten