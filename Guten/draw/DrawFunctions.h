#pragma once

#include "../GutenExports.h"
#include "../core/Character.h"
#include "../core/Matrix.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

namespace guten
{
	namespace draw
	{
		// -------------------------------- DECLARATIONS --------------------------

		GUTEN_API void horizontalLine(core::Matrix& mat, const Point& p1, size_t width, const color::Color& color = color::white, bool doubleLines = false);
		template<typename CHAR_T>
		GUTEN_API void horizontalLine(core::Matrix& mat, const Point& p1, size_t width, const CHAR_T& character = lines::horizontal, const color::Color& color = color::white);

		GUTEN_API void verticalLine(core::Matrix& mat, const Point& p1, size_t height, const color::Color& color = color::white, bool doubleLines = false);
		template<typename CHAR_T>
		GUTEN_API void verticalLine(core::Matrix& mat, const Point& p1, size_t height, const CHAR_T& character = lines::vertical, const color::Color& color = color::white);

		GUTEN_API void rectangle(core::Matrix& mat, const Point& p1, const Point& p2, const color::Color& color = color::white, bool doubleLines = false);
		template<typename CHAR_T>
		GUTEN_API void rectangle(core::Matrix& mat, const Point& p1, const Point& p2, const CHAR_T& character = lines::cross, const color::Color& color = color::white);
		template<>
		GUTEN_API void rectangle<lines::LineChar>(core::Matrix& mat, const Point& p1, const Point& p2, const lines::LineChar& character, const color::Color& color);

		GUTEN_API void rectangle(core::Matrix& mat, const Point& origin, const Size& size, const color::Color& color = color::white, bool doubleLines = false);
		template<typename CHAR_T>
		GUTEN_API void rectangle(core::Matrix& mat, const Point& origin, const Size& size, const CHAR_T& character = lines::cross, const color::Color& color = color::white);
		template<>
		GUTEN_API void rectangle<lines::LineChar>(core::Matrix& mat, const Point& origin, const Size& size, const lines::LineChar& character, const color::Color& color);

		GUTEN_API void putText(core::Matrix& mat, const std::string& text, const Point& origin, const color::Color& color = color::white);

		template<typename CHAR_T>
		void horizontalLine(core::Matrix& mat, const Point& p1, size_t width, const CHAR_T& character, const color::Color& color)
		{
			for (size_t col = p1.col; col < p1.col + width; col++) {
				mat.at(p1.row, col).character += character;
				mat.at(p1.row, col).color = color;
			}
		}

		template<typename CHAR_T>
		void verticalLine(core::Matrix& mat, const Point& p1, size_t height, const CHAR_T& character, const color::Color& color)
		{
			for (size_t row = p1.row; row < p1.row + height; row++) {
				mat.at(row, p1.col).character += character;
				mat.at(row, p1.col).color = color;
			}
		}

		template<typename CHAR_T>
		void rectangle(core::Matrix& mat, const Point& p1, const Point& p2, const CHAR_T& character, const color::Color& color)
		{
			Point origin{
				std::min(p1.row, p2.row),
				std::min(p1.col, p2.col)
			};

			Size size{
				std::abs(p1.row - p2.row),
				std::abs(p1.col - p2.col)
			};

			rectangle(mat, origin, size, character, color);
		}

		template<typename CHAR_T>
		void rectangle(core::Matrix& mat, const Point& origin, const Size& size, const CHAR_T& character, const color::Color& color)
		{
			Point lowerLeft = Point{ origin.row + size.height - 1, origin.col };
			Point upperRight = Point{ origin.row, origin.col + size.width - 1 };
			Point lowerRigth = origin + size - Point{ 1, 1 };

			// --- Top Line ---
			horizontalLine(mat, origin + Size{ 0, 1 }, size.width - 2, character, color);

			// --- Bottom Line ---
			horizontalLine(mat, lowerLeft + Size{ 0, 1 }, size.width - 2, character, color);

			// --- Left Line ---
			verticalLine(mat, origin + Size{ 1, 0 }, size.height - 2, character, color);

			// --- Right Line ---
			verticalLine(mat, upperRight + Size{ 1, 0 }, size.height - 2, character, color);

			// --- Corners ---
			mat(origin).character = character;
			mat(origin).color = color;
			mat(lowerLeft).character = character;
			mat(lowerLeft).color = color;
			mat(upperRight).character = character;
			mat(upperRight).color = color;
			mat(lowerRigth).character = character;
			mat(lowerRigth).color = color;
		}
	} // namespace draw
} // namespace guten