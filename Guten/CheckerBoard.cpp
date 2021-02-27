#include "pch.h"
#include "CheckerBoard.h"
#include "Color.h"
#include "DrawFunctions.h"

namespace guten
{
	namespace boards
	{
		CheckerBoard::CheckerBoard() :
			cellSize(3, 7)
		{
			setCellSize(cellSize);
		}

		void CheckerBoard::setCellSize(const Size & cellSize)
		{
			setCellSize(cellSize.height, cellSize.width);
		}

		void CheckerBoard::setCellSize(int nRows, int nCols)
		{
			cellSize = Size{ nRows, nCols };

			int totalRows = nRows * 8 + 4;
			int totalCols = nCols * 8 + 4;

			resize(totalRows, totalCols);
		}

		void CheckerBoard::drawBackground()
		{
			drawBoarder();

			drawCells();

			drawRibbon();
		}

		void CheckerBoard::placePiece(char piece, int row, int col, bool isLight)
		{
			int r = 2 + cellSize.rows() * row + (cellSize.rows() / 2);
			int c = 2 + cellSize.cols() * col + (cellSize.cols() / 2);

			(*this)[r][c].character = piece;
			(*this)[r][c].color.setfg(isLight ? lightPiece : darkPiece);
		}

		void CheckerBoard::placePiece(char piece, const Point & pos, bool isLight)
		{
			placePiece(piece, pos.row, pos.col, isLight);
		}

		void CheckerBoard::highlight(int row, int col)
		{
			for (int r = 0; r < cellSize.rows(); r++) {
				for (int c = 0; c < cellSize.cols(); c++) {
					int rr = 2 + cellSize.rows() * row + r;
					int cc = 2 + cellSize.cols() * col + c;

					(*this)[rr][cc].color.setbg(row % 2 == col % 2 ? darkHighlight : lightHighlight);
				}
			}
		}

		void CheckerBoard::highlight(const Point & pos)
		{
			highlight(pos.row, pos.col);
		}

		void CheckerBoard::print(size_t nTabs, std::ostream & os) const
		{
			this->Matrix::print(nTabs, os);
		}

		void CheckerBoard::drawBoarder()
		{
			color::Color color{ lightBoarder, darkBoarder };

			draw::rectangle(*this, guten::Point{ 0, 0 }, this->size(), color, true);
		}

		void CheckerBoard::drawCells()
		{
			for (int cellRow = 0; cellRow < 8; cellRow++) {
				for (int cellCol = 0; cellCol < 8; cellCol++) {

					color::Color color{ (cellRow % 2 == cellCol % 2 ? lightCell : darkCell) };

					for (int row = 0; row < cellSize.height; row++) {
						for (int col = 0; col < cellSize.width; col++) {

							const int r = 2 + cellRow * cellSize.height + row;
							const int c = 2 + cellCol * cellSize.width + col;

							(*this)[r][c].character = ' ';		// Remove any placed pieces
							(*this)[r][c].color.setbg(color);
						}
					}
				}
			}
		}

		void CheckerBoard::drawRibbon()
		{
			// --- Draw Coordinate Ribbons ---
			const int TOP_ROW = 1;
			const int BOT_ROW = nRows() - 2;
			const int LEF_COL = 1;
			const int RIG_COL = nCols() - 2;

			// -- TOP and BOTTOM --
			for (int cellCol = 0; cellCol < 8; cellCol++) {
				color::Color topColor{ (cellCol % 2 ? lightCell : darkCell) };
				color::Color botColor{ (cellCol % 2 ? darkCell : lightCell) };

				for (int col = 0; col < cellSize.width; col++) {
					const int c = 2 + cellCol * cellSize.width + col;

					(*this)[TOP_ROW][c].color.setbg(topColor);
					(*this)[BOT_ROW][c].color.setbg(botColor);
				}

				// - Place Letter -
				const int c = 2 + cellCol * cellSize.width + (cellSize.width / 2);
				(*this)[TOP_ROW][c].character = 'A' + cellCol;
				(*this)[TOP_ROW][c].color.setfg(botColor);
				(*this)[BOT_ROW][c].character = 'A' + cellCol;
				(*this)[BOT_ROW][c].color.setfg(topColor);
			}

			// -- LEFT and RIGHT --
			for (int cellRow = 0; cellRow < 8; cellRow++) {
				color::Color lefColor{ (cellRow % 2 ? lightCell : darkCell) };
				color::Color rigColor{ (cellRow % 2 ? darkCell : lightCell) };

				for (int row = 0; row < cellSize.height; row++) {
					const int r = 2 + cellRow * cellSize.height + row;

					(*this)[r][LEF_COL].color.setbg(lefColor);
					(*this)[r][RIG_COL].color.setbg(rigColor);
				}

				// - Place Letter -
				const int r = 2 + cellRow * cellSize.height + (cellSize.height / 2);
				(*this)[r][LEF_COL].character = '8' - cellRow;
				(*this)[r][LEF_COL].color.setfg(rigColor);
				(*this)[r][RIG_COL].character = '8' - cellRow;
				(*this)[r][RIG_COL].color.setfg(lefColor);
			}

			// -- Corners --
			(*this)[TOP_ROW][LEF_COL].color.setbg(lightCell);
			(*this)[TOP_ROW][RIG_COL].color.setbg(darkCell);
			(*this)[BOT_ROW][LEF_COL].color.setbg(darkCell);
			(*this)[BOT_ROW][RIG_COL].color.setbg(lightCell);
		}
	} // namespace board
} // namespace guten