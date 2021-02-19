#include "pch.h"
#include "DrawFunctions.h"

#include <algorithm>

using namespace std;
using namespace guten::core;

namespace guten
{
	namespace draw
	{
		GUTEN_API void horizontalLine(Matrix& mat, const Point & p1, size_t width, const color::Color & color, bool doubleLines)
		{
			const auto & HORIZONTAL = (doubleLines ? lines::double_horizontal : lines::horizontal);

			for (size_t col = p1.col; col < p1.col + width; col++) {
				mat[p1.row][col].character += HORIZONTAL;
				mat[p1.row][col].color = color;
			}
		}

		GUTEN_API void verticalLine(Matrix& mat, const Point & p1, size_t height, const color::Color & color, bool doubleLines)
		{
			const auto & VERTICAL = (doubleLines ? lines::double_vertical : lines::vertical);

			for (size_t row = p1.row; row < p1.row + height; row++) {
				mat[row][p1.col].character += VERTICAL;
				mat[row][p1.col].color = color;
			}
		}

		GUTEN_API void rectangle(Matrix& mat, const Point & p1, const Point & p2, const color::Color & color, bool doubleLines)
		{
			Point origin{
				min(p1.row, p2.row),
				min(p1.col, p2.col)
			};

			Size size{
				std::abs(p1.row - p2.row),
				std::abs(p1.col - p2.col)
			};

			rectangle(mat, origin, size, color, doubleLines);
		}

		GUTEN_API void rectangle(Matrix& mat, const Point & origin, const Size & size, const color::Color & color, bool doubleLines)
		{
			Point lowerLeft = Point{ origin.row + size.height - 1, origin.col };
			Point upperRight = Point{ origin.row, origin.col + size.width - 1 };
			Point lowerRigth = origin + size - Point{ 1, 1 };

			// --- Top Line ---
			horizontalLine(mat, origin + Size{ 0, 1 }, size.width - 2, color, doubleLines);

			// --- Bottom Line ---
			horizontalLine(mat, lowerLeft + Size{ 0, 1 }, size.width - 2, color, doubleLines);

			// --- Left Line ---
			verticalLine(mat, origin + Size{ 1, 0 }, size.height - 2, color, doubleLines);

			// --- Right Line ---
			verticalLine(mat, upperRight + Size{ 1, 0 }, size.height - 2, color, doubleLines);

			// --- Corners ---
			if (doubleLines) {
				mat(origin).character = lines::double_down + lines::double_right;
				mat(origin).color = color;
				mat(lowerLeft).character = lines::double_up + lines::double_right;
				mat(lowerLeft).color = color;
				mat(upperRight).character = lines::double_down + lines::double_left;
				mat(upperRight).color = color;
				mat(lowerRigth).character = lines::double_up + lines::double_left;
				mat(lowerRigth).color = color;
			}
			else {
				mat(origin).character = lines::down + lines::right;
				mat(origin).color = color;
				mat(lowerLeft).character = lines::up + lines::right;
				mat(lowerLeft).color = color;
				mat(upperRight).character = lines::down + lines::left;
				mat(upperRight).color = color;
				mat(lowerRigth).character = lines::up + lines::left;
				mat(lowerRigth).color = color;
			}
		}
	} // namespace draw
} // namespace guten