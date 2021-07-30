#include "examples_draw_functions.h"

#include "Guten/Matrix.h"
#include "Guten/LineChar.h"
#include "Guten/DrawFunctions.h"

namespace examples
{
	namespace draw
	{
		void lines()
		{
			guten::core::Matrix img;
			img.resize(10, 30);

			guten::draw::verticalLine(img, guten::Point{ 2, 2 }, 7, guten::lines::vertical, guten::color::green);
			guten::draw::horizontalLine(img, guten::Point{ 2, 2 }, 7, guten::lines::horizontal, guten::color::red);

			guten::draw::rectangle(img, guten::Point{ 1, 1 }, guten::Point{ img.nRows() - 2, img.nCols() - 2 }, guten::lines::LineChar{}, guten::color::magenta);
			guten::draw::rectangle(img, guten::Point{ 0, 0 }, img.size(), guten::lines::LineChar{}, guten::color::magenta);

			img.print();
		}
	} // namespace draw
} // namespace examples
