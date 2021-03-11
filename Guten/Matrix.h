#pragma once

#include "GutenExports.h"

#include "iocolor.h"
#include "Color.h"
#include "ColoredChar.h"
#include "Character.h"
#include "Point.h"

#include <boost/multi_array.hpp>	// Break this down into only the headers we need

#include <iostream>
#include <iomanip>

#pragma error (disable: 2398)

namespace guten
{
	namespace core
	{
		using colored_char_t = core::ColoredChar<core::Character>;
		using multi_array_t = boost::multi_array<colored_char_t, 2>;

		class GUTEN_API Matrix : public multi_array_t
		{
		public:

			Matrix() = default;
			Matrix(size_t nRows, size_t nCols);
			Matrix(const Matrix &) = default;
			Matrix(Matrix &&) noexcept = default;
			virtual ~Matrix() noexcept = default;
			Matrix & operator=(const Matrix &) = default;
			Matrix & operator=(Matrix &&) noexcept = default;

			colored_char_t & operator()(const Point & p) { return (*this)[p.row][p.col]; }
			const colored_char_t & operator()(const Point & p) const { return (*this)[p.row][p.col]; }

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;

			void resize(size_t nRows, size_t nCols);

			inline void resize(const Size & size) { resize(size.rows(), size.cols()); }

			int nRows() const { return static_cast<int>(this->shape()[0]); }
			int nCols() const { return static_cast<int>(this->shape()[1]); }
			Size size() const { return Size(nRows(), nCols()); }

			void rotate180();

			void copyTo(Matrix & dst) const;
			void copyTo(Matrix & dst, Point at) const;

		protected:
		};
	} // namespace core
} // namespace guten
