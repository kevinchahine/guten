#include "pch.h"
#include "Matrix2.h"

#include <boost/multi_array.hpp>

using namespace std;

namespace guten
{
	namespace core
	{
		using colored_char_t = ColoredChar<Character>;
		using multi_array_t = boost::multi_array<colored_char_t, 2>;

		// ----- PRIVATE IMPLEMENTATION -----

		class Matrix2::Impl : public multi_array_t
		{
		public:
			Impl() = default;
			Impl(size_t nRows, size_t nCols) { resize(nRows, nCols); }
			Impl(const Impl &) = default;
			Impl(Impl &&) noexcept = default;
			~Impl() noexcept = default;
			Impl & operator=(const Impl &) = default;
			Impl & operator=(Impl &&) noexcept = default;

			colored_char_t & at(size_t row, size_t col) { return (*this)[row][col]; }
			const colored_char_t & at(size_t row, size_t col) const { return (*this)[row][col]; }

			inline void resize(size_t nRows, size_t nCols) {
				multi_array_t::extent_gen extents;
				this->multi_array_t::resize(extents[nRows][nCols]);
			}
			inline void resize(const Size & size) { resize(size.rows(), size.cols()); }

			int nRows() const { return static_cast<int>(this->shape()[0]); }
			int nCols() const { return static_cast<int>(this->shape()[1]); }
			Size size() const { return Size(nRows(), nCols()); }

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;
		};

		void Matrix2::Impl::print(size_t nTabs, std::ostream & os) const
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

		Matrix2::Matrix2() :
			pImpl(make_unique<Impl>())
		{
		}

		Matrix2::Matrix2(size_t row, size_t col) :
			pImpl(make_unique<Impl>(row, col))
		{
		}

		Matrix2::Matrix2(const Matrix2 & m) :
			pImpl(make_unique<Impl>(*m.pImpl)) {}

		Matrix2::Matrix2(Matrix2 && m) noexcept :
			pImpl(std::move(m.pImpl)) {}

		Matrix2::~Matrix2() { }

		Matrix2 & Matrix2::operator=(const Matrix2 & m)
		{
			this->pImpl = make_unique<Impl>(*m.pImpl);

			return *this;
		}

		Matrix2 & Matrix2::operator=(Matrix2 && m) noexcept
		{
			this->pImpl = std::move(m.pImpl);

			return *this;
		}
		
		colored_char_t & Matrix2::at(size_t row, size_t col)
		{
			return pImpl->at(row, col);
		}

		const colored_char_t & Matrix2::at(size_t row, size_t col) const
		{
			return pImpl->at(row, col);
		}

		void Matrix2::print(size_t nTabs, std::ostream & os) const
		{
			pImpl->print(nTabs, os);
		}

		int Matrix2::nRows() const
		{
			return pImpl->nRows();
		}
		
		int Matrix2::nCols() const
		{
			return pImpl->nCols();
		}
		
		Size Matrix2::size() const
		{
			return pImpl->size();
		}
	} // namespace core
} // namespace guten
