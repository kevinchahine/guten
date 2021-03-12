#pragma once

#include "GutenExports.h"

#include "iocolor.h"
#include "Color.h"
#include "ColoredChar.h"
#include "Character.h"
#include "Point.h"

#include <iostream>
#include <iomanip>
#include <memory>

#pragma error (disable: 2398)

namespace guten
{
	namespace core
	{
		using colored_char_t = core::ColoredChar<core::Character>;

		class GUTEN_API Matrix
		{
			class Impl;

		public:
			Matrix();
			Matrix(size_t row, size_t col);
			Matrix(const Matrix & m);
			Matrix(Matrix && m) noexcept;
			~Matrix() noexcept;
			Matrix & operator=(const Matrix & m);
			Matrix & operator=(Matrix && m) noexcept;

			colored_char_t & at(size_t row, size_t col);
			const colored_char_t & at(size_t row, size_t col) const;

			colored_char_t & operator()(const Point & p) { return (*this).at(p.row, p.col); }
			const colored_char_t & operator()(const Point & p) const { return (*this).at(p.row, p.col); }

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;

			int nRows() const;
			int nCols() const;
			Size size() const;

			void resize(size_t nRows, size_t nCols);

<<<<<<< HEAD
			void copyTo(Matrix & dst) const;
			void copyTo(Matrix & dst, Point at) const;

		protected:
			class Impl;
			Impl * pImpl;
			//std::unique_ptr<Impl> pImpl;// = std::make_unique<Impl>();
=======
			void resize(const Size & size);

		private:
			std::unique_ptr<Impl> pImpl;
>>>>>>> e5d3b89 (Swapped Matrix2 inplace of Matrix. Now Matrix is implemented using pimpl idiom. Seems to run find but not thourouly tested.)
		};
	} // namespace core
} // namespace guten
