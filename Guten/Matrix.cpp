#include "pch.h"
#include "Matrix.h"

using namespace std;

namespace guten
{
	namespace core
	{
		Matrix::Matrix(size_t nRows, size_t nCols)
		{
			resize(nRows, nCols);
		}

		void Matrix::print(std::ostream & os, size_t nTabs) const
		{
			const size_t N_ROWS = this->shape()[0];
			const size_t N_COLS = this->shape()[1];

			for (size_t row = 0; row < N_ROWS; row++) {

				for (size_t tab = 0; tab < nTabs; tab++) {
					os << "    ";
				}

				for (size_t col = 0; col < N_COLS; col++) {
					os << (*this)[row][col];
				}

				os << '\n';
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
	} // namespace core
} // namespace guten

