#pragma once

#include "examples_checker_board.h"

namespace examples
{
	namespace checker_board
	{
		void test()
		{
			guten::boards::CheckerBoard cb;

			cb.placePiece('R', 0, 0, true);

			cb.print();
		}

		void printMini()
		{
			guten::boards::CheckerBoard cb;

			cb.placePiece('R', 0, 0, true);
			cb.placePiece('Q', 4, 5, false);

			cb.printMini();
		}
	} // namespace checker_board
} // namespace examples