#include "pch.h"
#include "Matrix.h"

#include <algorithm>	// for std::min()

using namespace std;

namespace guten
{
	namespace core
	{
		Matrix::Matrix(size_t nRows, size_t nCols)
		{
			resize(nRows, nCols);
		}


		void Matrix::print(size_t nTabs, std::ostream & os) const
		{
			const size_t N_ROWS = this->shape()[0];
			const size_t N_COLS = this->shape()[1];

			for (size_t row = 0; row < N_ROWS; row++) {
				os << color::push();

				for (size_t tab = 0; tab < nTabs; tab++) {
					os << "    ";
				}

				for (size_t col = 0; col < N_COLS; col++) {
					os << (*this)[row][col];
				}

				os << color::pop() << '\n';
			}
		}

		void Matrix::resize(size_t nRows, size_t nCols)
		{
			multi_array_t::extent_gen extents;
			this->multi_array_t::resize(extents[nRows][nCols]);
		}

		void Matrix::rotate180()
		{
			cout << __FUNCTION__ << "() still needs to be implemented\n";
		}

		void Matrix::copyTo(Matrix & dst) const
		{
			const int ROW_LIMIT = min(this->nRows(), dst.nRows());
			const int COL_LIMIT = min(this->nCols(), dst.nCols());

			for (int row = 0; row < ROW_LIMIT; row++) {
				for (int col = 0; col < COL_LIMIT; col++) {
					dst[row][col] = (*this)[row][col];
				}
			}
		}

		void Matrix::copyTo(Matrix & dst, Point at) const
		{
			const int ROW_LIMIT = min(this->nRows(), dst.nRows() - at.row);
			const int COL_LIMIT = min(this->nCols(), dst.nCols() - at.col);

			for (int row = 0; row < ROW_LIMIT; row++) {
				for (int col = 0; col < COL_LIMIT; col++) {
					dst[row + at.row][col + at.col] = (*this)[row][col];
				}
			}
		}
	} // namespace core
} // namespace guten

