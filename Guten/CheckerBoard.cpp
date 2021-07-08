#include "pch.h"
#include "CheckerBoard.h"
#include "Color.h"
#include "DrawFunctions.h"

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
			(*this).at(row, col).color.setfg(isLight ? lightPiece : darkPiece);
			(*this).at(row, col).color.setfgAlpha(0b1111);
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
			const guten::color::Color & bgColor1, 
			const guten::color::Color & bgColor2)
		{
			(*this).at(row, col).color.setbg(row % 2 == col % 2 ? bgColor1 : bgColor2);
			(*this).at(row, col).color.setbgAlpha(0b1111);
		}

		void CheckerBoard::highlight(int row, int col)
		{
			highlight(row, col, darkHighlight, lightHighlight);
		}

		void CheckerBoard::highlight(const Point & pos)
		{
			highlight(pos.row, pos.col);
		}

		void CheckerBoard::highlight(std::bitset<64> bitboard, const guten::color::Color & bgColor1, const guten::color::Color & bgColor2)
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

		void CheckerBoard::highlight(std::bitset<64> bitboard)
		{
			highlight(bitboard, darkHighlight, lightHighlight);
		}

		void CheckerBoard::clearHighlights()
		{
			for (size_t row = 0; row < nRows(); row++) {
				for (size_t col = 0; col < nCols(); col++) {
					(*this).at(row, col).color.setbgAlpha(0);
				}
			}
		}

		Matrix CheckerBoard::draw() const
		{
			size_t totalRows = this->nRows() * cellSize.rows() + 4;
			size_t totalCols = this->nCols() * cellSize.cols() + 4; 

			Matrix img{ totalRows, totalCols };
			
			drawBoarder(img);

			drawRibbon(img);

			drawCells(img);
			
			return img;
		}

		void CheckerBoard::print(size_t nTabs, std::ostream & os) const
		{
			draw().print(nTabs, os);
		}

		void CheckerBoard::drawBoarder(core::Matrix & img) const
		{
			color::Color color{ lightBoarder, darkBoarder };

			draw::rectangle(img, guten::Point{ 0, 0 }, img.size(), color, true);
		}

		void CheckerBoard::drawCells(core::Matrix & img) const
		{
			for (int cellRow = 0; cellRow < this->nRows(); cellRow++) {
				for (int cellCol = 0; cellCol < this->nCols(); cellCol++) {

					const Point origin{
						2 + cellRow * cellSize.height,
						2 + cellCol * cellSize.width
					};

					// --- Draw Background Color ---
					color::Color base = (cellRow % 2 == cellCol % 2 ? lightCell : darkCell);
					color::Color highlight = this->at(cellRow, cellCol).color;
					color::Color color = base | highlight;

					for (int row = 0; row < cellSize.height; row++) {
						for (int col = 0; col < cellSize.width; col++) {

							const int r = origin.row + row;
							const int c = origin.col + col;

							img.at(r, c).color.setbg(color);
						}
					}

					// --- Draw Piece ---

					const Point piecePos{
						origin.row + cellSize.height / 2,
						origin.col + cellSize.width / 2 };

					const colored_char_t & piece = this->at(cellRow, cellCol);
					colored_char_t & dstCell = img.at(piecePos);

					if (piece.character != ' ') {
						dstCell.character = piece.character;
						dstCell.color.setfg(piece.color.getfg());
						///dstCell.color.setbg(piece.color.negative().getfg());
					}
				}
			}
		}

		void CheckerBoard::drawRibbon(core::Matrix & img) const
		{
			// --- Draw Coordinate Ribbons ---
			const int TOP_ROW = 1;
			const int BOT_ROW = img.nRows() - 2;
			const int LEF_COL = 1;
			const int RIG_COL = img.nCols() - 2;

			// -- TOP and BOTTOM --
			for (int cellCol = 0; cellCol < this->nCols(); cellCol++) {
				color::Color topColor{ (cellCol % 2 ? lightCell : darkCell) };
				color::Color botColor{ (cellCol % 2 ? darkCell : lightCell) };

				for (int col = 0; col < cellSize.width; col++) {
					const int c = 2 + cellCol * cellSize.width + col;

					img.at(TOP_ROW, c).color.setbg(topColor);
					img.at(BOT_ROW, c).color.setbg(botColor);
				}

				// - Place Letter -
				const int c = 2 + cellCol * cellSize.width + (cellSize.width / 2);
				img.at(TOP_ROW, c).character = 'A' + cellCol;
				img.at(TOP_ROW, c).color.setfg(botColor);
				img.at(BOT_ROW, c).character = 'A' + cellCol;
				img.at(BOT_ROW, c).color.setfg(topColor);
			}

			// -- LEFT and RIGHT --
			for (int cellRow = 0; cellRow < this->nRows(); cellRow++) {
				color::Color lefColor{ (cellRow % 2 ? lightCell : darkCell) };
				color::Color rigColor{ (cellRow % 2 ? darkCell : lightCell) };

				for (int row = 0; row < cellSize.height; row++) {
					const int r = 2 + cellRow * cellSize.height + row;

					img.at(r, LEF_COL).color.setbg(lefColor);
					img.at(r, RIG_COL).color.setbg(rigColor);
				}

				// - Place Letter -
				const int r = 2 + cellRow * cellSize.height + (cellSize.height / 2);
				img.at(r, LEF_COL).character = '8' - cellRow;
				img.at(r, LEF_COL).color.setfg(rigColor);
				img.at(r, RIG_COL).character = '8' - cellRow;
				img.at(r, RIG_COL).color.setfg(lefColor);
			}

			// -- Corners --
			img.at(TOP_ROW, LEF_COL).color.setbg(lightCell);
			img.at(TOP_ROW, RIG_COL).color.setbg(darkCell);
			img.at(BOT_ROW, LEF_COL).color.setbg(darkCell);
			img.at(BOT_ROW, RIG_COL).color.setbg(lightCell);
		}
	} // namespace board
} // namespace guten