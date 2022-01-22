#pragma once

#include "../GutenExports.h"

#include "../core/ColoredChar.h"
#include "../core/Character.h"
#include "../core/Point.h"

#include <iostream>
#include <iomanip>
#include <memory>

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

			colored_char_t & at(Point point) { return at(point.row, point.col); }
			const colored_char_t & at(Point point) const { return at(point.row, point.col); }

			colored_char_t & operator()(const Point & p) { return (*this).at(p.row, p.col); }
			const colored_char_t & operator()(const Point & p) const { return (*this).at(p.row, p.col); }

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;

			int nRows() const;
			int nCols() const;
			Size size() const;

			void resize(size_t nRows, size_t nCols);
			void resize(const Size & size);

			void copyTo(Matrix & dst) const;
			void copyTo(Matrix & dst, Point at) const;

			void clear();

		private:
			std::unique_ptr<Impl> pImpl;
		};
	} // namespace core
} // namespace guten
