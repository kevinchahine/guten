#pragma once

#include "GutenExports.h"
#include "color.h"
#include "Matrix.h"

namespace guten
{
	namespace boards
	{
		class GUTEN_API CheckerBoard : public core::Matrix
		{
		public:
			CheckerBoard();
			CheckerBoard(const CheckerBoard &) = default;
			CheckerBoard(CheckerBoard &&) noexcept = default;
			virtual ~CheckerBoard() noexcept = default;
			CheckerBoard & operator=(const CheckerBoard &) = default;
			CheckerBoard & operator=(CheckerBoard &&) noexcept = default;

			void setCellSize(const Size & cellSize);
			void setCellSize(int nRows, int nCols);

			// Removes any placed pieces.
			// Pieces need to be placed after calling this method
			// by calling .placePiece()
			void drawBackground();

			void placePiece(char piece, int row, int col, bool isLight);

			void placePiece(char piece, const Point & pos, bool isLight);

			void highlight(int row, int col);

			void highlight(const Point & pos);

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;

		protected:
			void drawBoarder();

			void drawCells();

			void drawRibbon();

		protected:
			color::Color darkCell = color::green;
			color::Color lightCell = color::brown;
			color::Color darkHighlight = color::red;
			color::Color lightHighlight = color::lightred;
			color::Color darkPiece = color::black;
			color::Color lightPiece = color::yellow;
			color::Color darkBoarder = color::green;
			color::Color lightBoarder = color::brown;

			Size cellSize{ 3, 5 };
		};
	} // namespace boards
} // namespace guten

