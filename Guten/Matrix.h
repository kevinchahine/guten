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
		public:

			Matrix();
			Matrix(size_t nRows, size_t nCols);
			Matrix(const Matrix &) = default;
			Matrix(Matrix &&) noexcept = default;
			~Matrix();
			Matrix & operator=(const Matrix &) = default;
			Matrix & operator=(Matrix &&) noexcept = default;

			colored_char_t & operator()(const Point & p) { colored_char_t temp; return temp; }/// (*this)[p.row][p.col];
			
			const colored_char_t & operator()(const Point & p) const { colored_char_t temp; return temp; } /// return (*this)[p.row][p.col];

			colored_char_t & at(size_t row, size_t col);
			const colored_char_t & at(size_t row, size_t col) const;

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;

			void resize(size_t nRows, size_t nCols);

			inline void resize(const Size & size) { resize(size.rows(), size.cols()); }
			
			int nRows() const;
			int nCols() const;
			Size size() const;

			void rotate180();

			void copyTo(Matrix & dst) const;
			void copyTo(Matrix & dst, Point at) const;

		protected:
			class Impl;
			Impl * pImpl;
			//std::unique_ptr<Impl> pImpl;// = std::make_unique<Impl>();
		};
	} // namespace core
} // namespace guten
