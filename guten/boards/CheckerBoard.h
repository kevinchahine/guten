#pragma once

#include "../GutenExports.h"
#include "../color/Color.h"
#include "../core/Matrix.h"

#include "../termcolor/termcolor.hpp"

namespace guten
{
	namespace boards
	{
		// An 8x8 checker board good for showing board games like chess, checkers, turkish draughts, etc.
		// Size is fixed to an 8x8 board and can't be changed in this implementation.
		// For game engines that use bit boards to represent their game, this class has an easy to use
		// method that places pieces using a 64-bit integer.
		// Only supports 2 player games with 2 colors.
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

			void placePiece(char piece, int row, int col, bool isLight);

			void placePiece(char piece, const Point & pos, bool isLight);

			void placePieces(char piece, std::bitset<64> bitboard, bool isLight);

			void highlight(int row, int col, const termcolor::Color & bgColor1, const termcolor::Color & bgColor2);

			void highlight(int row, int col);

			void highlight(const Point & pos);

			void highlight(const std::bitset<64> & bitboard, const termcolor::Color & bgColor1, const termcolor::Color & bgColor2);
			
			void highlight(const std::bitset<64> & bitboard);

			void clearHighlights();

			// Draws the CheckerBoard on a Matrix and returns it.
			// Matrix can then be printed or even copied onto another Matrix.
			core::Matrix draw() const;

			core::Matrix drawMini() const;

			void print(size_t nTabs = 0, std::ostream& os = std::cout) const;

			void printMini(size_t nTabs = 0, std::ostream& os = std::cout) const;

		protected:
			void drawBoarder(core::Matrix & img) const;

			void drawRibbon(core::Matrix & img, const Size& imgCellSize) const;

			void drawCells(core::Matrix & img, const Size& imgCellSize) const;

		public:
			termcolor::Color darkCell = guten::color::green;
			termcolor::Color lightCell = guten::color::brown;
			termcolor::Color darkHighlight = guten::color::red;
			termcolor::Color lightHighlight = guten::color::lightred;
			termcolor::Color darkPiece = guten::color::black;
			termcolor::Color lightPiece = guten::color::yellow;
			termcolor::Color darkBoarder = guten::color::green;
			termcolor::Color lightBoarder = guten::color::brown;
		
		protected:
			Size cellSize{ 3, 5 };
		};
	} // namespace boards
} // namespace guten

