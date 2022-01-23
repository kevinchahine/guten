#include "../pch.h"
#include "CheckerBoard.h"
#include "../color/Color.h"
#include "../draw/DrawFunctions.h"

#include "../termcolor/termcolor.hpp"

using namespace guten::core;
using namespace std;

namespace guten
{
	namespace boards
	{
		CheckerBoard::CheckerBoard() :
			Matrix(8, 8),
			cellSize(3, 7)
		{
			setCellSize(cellSize);
			clearHighlights();
		}

		void CheckerBoard::setCellSize(const Size & cellSize)
		{
			setCellSize(cellSize.height, cellSize.width);
		}

		void CheckerBoard::setCellSize(int nRows, int nCols)
		{
			cellSize = Size{ nRows, nCols };
		}

		void CheckerBoard::placePiece(char piece, int row, int col, bool isLight)
		{
			(*this).at(row, col).character = piece;
			
			(*this).at(row, col).color.foreground = termcolor::ColorFG(1, 2, 3);// = (isLight ? lightPiece : darkPiece);

			// (*this).at(row, col).color.setfgAlpha(0b1111);
		}

		void CheckerBoard::placePiece(char piece, const Point & pos, bool isLight)
		{
			placePiece(piece, pos.row, pos.col, isLight);
		}

		void CheckerBoard::placePieces(char piece, std::bitset<64> bitboard, bool isLight)
		{
			for (int row = 0; row < 8; row++) {
				for (int col = 0; col < 8; col++) {
					// same as (row * 8) + col
					int bit = (row << 3) + col;

					if (bitboard[bit]) {
						placePiece(piece, row, col, isLight);
					}
				}
			}
		}

		void CheckerBoard::highlight(
			int row, int col, 
			const termcolor::Color & bgColor1, 
			const termcolor::Color & bgColor2)
		{
			(*this).at(row, col).color.background = (row % 2 == col % 2 ? bgColor1 : bgColor2);
			(*this).at(row, col).color.background.alpha = 255;
		}

		void CheckerBoard::highlight(int row, int col)
		{
			highlight(row, col, darkHighlight, lightHighlight);
		}

		void CheckerBoard::highlight(const Point & pos)
		{
			highlight(pos.row, pos.col);
		}

		void CheckerBoard::highlight(const std::bitset<64> & bitboard, const termcolor::Color & bgColor1, const termcolor::Color & bgColor2)
		{
			for (int row = 0; row < 8; row++) {
				for (int col = 0; col < 8; col++) {
					// same as (row * 8) + col
					int bit = (row << 3) + col;

					if (bitboard[bit]) {
						highlight(row, col, bgColor1, bgColor2);
					}
				}
			}
		}

		void CheckerBoard::highlight(const std::bitset<64> & bitboard)
		{
			highlight(bitboard, darkHighlight, lightHighlight);
		}

		void CheckerBoard::clearHighlights()
		{
			for (size_t row = 0; row < nRows(); row++) {
				for (size_t col = 0; col < nCols(); col++) {
					(*this).at(row, col).color.background.alpha = 0;
				}
			}
		}

		Matrix CheckerBoard::draw() const
		{
			size_t totalRows = this->nRows() * cellSize.rows() + 4;
			size_t totalCols = this->nCols() * cellSize.cols() + 4; 

			Matrix img{ totalRows, totalCols };

			drawBoarder(img);

			drawRibbon(img, cellSize);

			drawCells(img, cellSize);

			return img;
		}

		core::Matrix CheckerBoard::drawMini() const
		{
			size_t totalRows = this->nRows() + 4;
			size_t totalCols = this->nCols() + 4;

			Matrix img{ totalRows, totalCols };

			drawBoarder(img);

			drawRibbon(img, Size{ 1, 1 });
			
			drawCells(img, Size{ 1, 1 });

			return img;
		}

		void CheckerBoard::print(size_t nTabs, std::ostream & os) const
		{
			guten::core::Matrix img = this->draw();

			img.print(nTabs, os);

			// draw().print(nTabs, os);
		}
		
		void CheckerBoard::printMini(size_t nTabs, std::ostream& os) const
		{
			this->drawMini().print(nTabs, os);
		}

		void CheckerBoard::drawBoarder(core::Matrix & img) const
		{
			termcolor::Color color{ lightBoarder };//, darkBoarder };

			draw::rectangle(img, guten::Point{ 0, 0 }, img.size(), color, true);
		}
		
		void CheckerBoard::drawRibbon(core::Matrix & img, const Size & imgCellSize) const
		{
			// --- Draw Coordinate Ribbons ---
			const int TOP_ROW = 1;
			const int BOT_ROW = img.nRows() - 2;
			const int LEF_COL = 1;
			const int RIG_COL = img.nCols() - 2;

			// -- TOP and BOTTOM --
			for (int cellCol = 0; cellCol < this->nCols(); cellCol++) {
				termcolor::Color topColor{ (cellCol % 2 ? lightCell : darkCell) };
				termcolor::Color botColor{ (cellCol % 2 ? darkCell : lightCell) };

				for (int col = 0; col < imgCellSize.width; col++) {
					const int c = 2 + cellCol * imgCellSize.width + col;

					img.at(TOP_ROW, c).color.background = topColor;

					img.at(BOT_ROW, c).color.background = botColor;
				}

				// - Place Letter -
				const int c = 2 + cellCol * imgCellSize.width + (imgCellSize.width / 2);
				img.at(TOP_ROW, c).character = 'A' + cellCol;
				img.at(TOP_ROW, c).color.foreground = botColor;
				img.at(BOT_ROW, c).character = 'A' + cellCol;
				img.at(BOT_ROW, c).color.foreground = topColor;
			}

			// -- LEFT and RIGHT --
			for (int cellRow = 0; cellRow < this->nRows(); cellRow++) {
				termcolor::Color lefColor{ (cellRow % 2 ? lightCell : darkCell) };
				termcolor::Color rigColor{ (cellRow % 2 ? darkCell : lightCell) };

				for (int row = 0; row < imgCellSize.height; row++) {
					const int r = 2 + cellRow * imgCellSize.height + row;

					img.at(r, LEF_COL).color.background = lefColor;
					img.at(r, RIG_COL).color.background = rigColor;
				}

				// - Place Letter -
				const int r = 2 + cellRow * imgCellSize.height + (imgCellSize.height / 2);
				img.at(r, LEF_COL).character = '8' - cellRow;
				img.at(r, LEF_COL).color.foreground = rigColor;
				img.at(r, RIG_COL).character = '8' - cellRow;
				img.at(r, RIG_COL).color.foreground = lefColor;
			}

			// -- Corners --
			img.at(TOP_ROW, LEF_COL).color.background = lightCell;
			img.at(TOP_ROW, RIG_COL).color.background = darkCell;
			img.at(BOT_ROW, LEF_COL).color.background = darkCell;
			img.at(BOT_ROW, RIG_COL).color.background = lightCell;
		}

		void CheckerBoard::drawCells(core::Matrix & img, const Size& imgCellSize) const
		{
			for (int cellRow = 0; cellRow < this->nRows(); cellRow++) {
				for (int cellCol = 0; cellCol < this->nCols(); cellCol++) {

					const Point origin{
						2 + cellRow * imgCellSize.height,
						2 + cellCol * imgCellSize.width
					};

					// --- Draw Background Color ---
					termcolor::Color base = (cellRow % 2 == cellCol % 2 ? lightCell : darkCell);
					termcolor::Color highlight = this->at(cellRow, cellCol).color.background;
					termcolor::Color color = base + highlight;
					
					for (int row = 0; row < imgCellSize.height; row++) {
						for (int col = 0; col < imgCellSize.width; col++) {

							const int r = origin.row + row;
							const int c = origin.col + col;

							img.at(r, c).color.background = color;
						}
					}

					// --- Draw Piece ---

					const Point piecePos{
						origin.row + imgCellSize.height / 2,
						origin.col + imgCellSize.width / 2 };

					const colored_char_t & piece = this->at(cellRow, cellCol);
					colored_char_t & dstCell = img.at(piecePos);

					if (piece.character != ' ') {
						dstCell.character = piece.character;
						dstCell.color.foreground = piece.color.foreground;
					}
				}
			}
		}
	} // namespace board
} // namespace guten