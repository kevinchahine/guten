#include "pch.h"
#include "Matrix.h"
#include <stdint.h>

#include <boost/multi_array.hpp>	// Break this down into only the headers we need

#include <algorithm>	// for std::min()

using namespace std;

namespace guten
{
	namespace core
	{
		// ----- Implementation Definitions -----

		using multi_array_t = boost::multi_array<colored_char_t, 2>;

		class Matrix::Impl //: public multi_array_t
		{
		public:

			Impl();
			Impl(size_t nRows, size_t nCols);
			Impl(const Impl &) = default;
			Impl(Impl &&) noexcept = default;
			~Impl() noexcept;
			Impl & operator=(const Impl &) = default;
			Impl & operator=(Impl &&) noexcept = default;
			
			///colored_char_t & operator()(const Point & p) { return (*this)[p.row][p.col]; }
			///const colored_char_t & operator()(const Point & p) const { return (*this)[p.row][p.col]; }
			///
			///void print(size_t nTabs = 0, std::ostream & os = std::cout) const;
			///
			///void resize(size_t nRows, size_t nCols);
			///
			///inline void resize(const Size & size) { resize(size.rows(), size.cols()); }
			///
			///int nRows() const { return static_cast<int>(this->shape()[0]); }
			///int nCols() const { return static_cast<int>(this->shape()[1]); }
			///Size size() const { return Size(nRows(), nCols()); }
			///
			///void rotate180();

		protected:
		};

		Matrix::Impl::Impl()
		{
		}

		

		Matrix::Impl::~Impl() noexcept
		{
		}

		// ----- Interface Definitions -----

		Matrix::Matrix()
		{
		}

		Matrix::Matrix(size_t nRows, size_t nCols) /*:
			pImpl(make_unique<Impl>(nRows, nCols))*/ {}

		Matrix::~Matrix()
		{
		}

		colored_char_t & Matrix::at(size_t row, size_t col)
		{
			// TODO: insert return statement here
			colored_char_t c;	// TODO: BAD
			return c;			// TODO: BAD
		}

		const colored_char_t & Matrix::at(size_t row, size_t col) const
		{
			// TODO: insert return statement here
			return colored_char_t();// TODO: BAD
		}

		void Matrix::print(size_t nTabs, std::ostream & os) const
		{
			//pImpl->print(nTabs, os);
		}

		void Matrix::resize(size_t nRows, size_t nCols)
		{
		}
		
		int Matrix::nRows() const
		{
			return 0;/// static_cast<int>(pImpl->shape()[0]);
		}

		int Matrix::nCols() const
		{
			return 0;/// static_cast<int>(pImpl->shape()[1]);
		}

		Size Matrix::size() const
		{
			return Size(nRows(), nCols());
		}

		void Matrix::rotate180()
		{
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