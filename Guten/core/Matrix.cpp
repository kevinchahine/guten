#include "../pch.h"
#include "Matrix.h"

#include <stdint.h>
#include <string>
#include <algorithm>	// for std::min()

#include <boost/multi_array.hpp>

using namespace std;

namespace guten
{
	namespace core
	{
		using colored_char_t = ColoredChar<Character>;
		using multi_array_t = boost::multi_array<colored_char_t, 2>;

		// ----- PRIVATE IMPLEMENTATION -----

		class Matrix::Impl : public multi_array_t
		{
		public:
			Impl() = default;
			Impl(size_t nRows, size_t nCols) { resize(nRows, nCols); }
			Impl(const Impl &) = default;
			Impl(Impl &&) noexcept = default;
			~Impl() noexcept = default;
			Impl & operator=(const Impl &) = default;
			Impl & operator=(Impl &&) noexcept = default;

			colored_char_t & at(size_t row, size_t col) 
			{ 
#ifdef _DEBUG
				if (row > nRows()) {
					string msg = "Row coordinate is out of bounds at " + std::to_string(row);
					throw std::exception(msg.c_str());
				}
				if (col > nCols()) {
					string msg = "Col coordinate is out of bounds at " + std::to_string(col);
					throw std::exception(msg.c_str());
				}
#endif // _DEBUG

				return (*this)[row][col]; 
			}

			const colored_char_t & at(size_t row, size_t col) const 
			{ 
#ifdef _DEBUG
				if (row > nRows()) {
					string msg = "Row coordinate is out of bounds at " + std::to_string(row);
					throw std::exception(msg.c_str());
				}
				if (col > nCols()) {
					string msg = "Col coordinate is out of bounds at " + std::to_string(col);
					throw std::exception(msg.c_str());
				}
#endif // _DEBUG

				return (*this)[row][col];
			}

			inline void resize(size_t nRows, size_t nCols) {
				multi_array_t::extent_gen extents;
				this->multi_array_t::resize(extents[nRows][nCols]);
			}
			inline void resize(const Size & size) { resize(size.rows(), size.cols()); }

			int nRows() const { return static_cast<int>(this->shape()[0]); }
			int nCols() const { return static_cast<int>(this->shape()[1]); }
			Size size() const { return Size(nRows(), nCols()); }

			void copyTo(Impl & dst);
			void copyTo(Impl & dst, Point at);

			void clear();

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;
		};

		void Matrix::Impl::copyTo(Impl & dst)
		{
			const int ROW_LIMIT = min(this->nRows(), dst.nRows());
			const int COL_LIMIT = min(this->nCols(), dst.nCols());

			for (int row = 0; row < ROW_LIMIT; row++) {
				for (int col = 0; col < COL_LIMIT; col++) {
					dst.at(row, col) = this->at(row, col);
				}
			}
		}

		void Matrix::Impl::copyTo(Impl & dst, Point at)
		{
			const int ROW_LIMIT = min(this->nRows(), dst.nRows() - at.row);
			const int COL_LIMIT = min(this->nCols(), dst.nCols() - at.col);

			for (int row = 0; row < ROW_LIMIT; row++) {
				for (int col = 0; col < COL_LIMIT; col++) {
					dst.at(row + at.row, col + at.col) = this->at(row, col);
				}
			}
		}

		void Matrix::Impl::clear()
		{
			for (size_t row = 0; row < nRows(); row++) {
				for (size_t col = 0; col < nCols(); col++) {
					this->at(row, col).character = ' ';
					this->at(row, col).color = guten::color::white;
				}
			}
		}

		void Matrix::Impl::print(size_t nTabs, std::ostream & os) const
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

		// ----- INTERFACE -----

		Matrix::Matrix() :
			pImpl(make_unique<Impl>())
		{
		}

		Matrix::Matrix(size_t row, size_t col) :
			pImpl(make_unique<Impl>(row, col))
		{
		}

		Matrix::Matrix(const Matrix & m) :
			pImpl(make_unique<Impl>(*m.pImpl)) {}

		Matrix::Matrix(Matrix && m) noexcept :
			pImpl(std::move(m.pImpl)) {}

		Matrix::~Matrix() { }

		Matrix & Matrix::operator=(const Matrix & m)
		{
			this->pImpl = make_unique<Impl>(*m.pImpl);

			return *this;
		}

		Matrix & Matrix::operator=(Matrix && m) noexcept
		{
			this->pImpl = std::move(m.pImpl);

			return *this;
		}

		colored_char_t & Matrix::at(size_t row, size_t col)
		{
			return pImpl->at(row, col);
		}

		const colored_char_t & Matrix::at(size_t row, size_t col) const
		{
			return pImpl->at(row, col);
		}

		void Matrix::print(size_t nTabs, std::ostream & os) const
		{
			pImpl->print(nTabs, os);
		}

		int Matrix::nRows() const
		{
			return pImpl->nRows();
		}

		int Matrix::nCols() const
		{
			return pImpl->nCols();
		}

		Size Matrix::size() const
		{
			return pImpl->size();
		}

		void Matrix::resize(size_t nRows, size_t nCols)
		{
			pImpl->resize(nRows, nCols);
		}
		
		void Matrix::resize(const Size & size)
		{
			pImpl->resize(size);
		}

		void Matrix::copyTo(Matrix & dst) const
		{
			pImpl->copyTo(*dst.pImpl);
		}

		void Matrix::copyTo(Matrix & dst, Point at) const
		{
			pImpl->copyTo(*dst.pImpl, at);
		}

		void Matrix::clear()
		{
			pImpl->clear();
		}
	} // namespace core
} // namespace guten