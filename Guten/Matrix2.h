#pragma once

#include "GutenExports.h"
#include "Character.h"
#include "ColoredChar.h"
#include "Size.h"
#include "Point.h"

#include <memory>

namespace guten
{
	namespace core
	{
		using colored_char_t = ColoredChar<Character>;
		
		class GUTEN_API Matrix2
		{
			class Impl;

		public:
			Matrix2();
			Matrix2(size_t row, size_t col);
			Matrix2(const Matrix2 & m);
			Matrix2(Matrix2 && m) noexcept;
			~Matrix2() noexcept;
			Matrix2 & operator=(const Matrix2 & m);
			Matrix2 & operator=(Matrix2 && m) noexcept;

			colored_char_t & at(size_t row, size_t col);
			const colored_char_t & at(size_t row, size_t col) const;

			colored_char_t & operator()(const Point & p) { return (*this).at(p.row, p.col); }
			const colored_char_t & operator()(const Point & p) const { return (*this).at(p.row, p.col); }

			void print(size_t nTabs = 0, std::ostream & os = std::cout) const;

			int nRows() const;
			int nCols() const;
			Size size() const;

		private:
			std::unique_ptr<Impl> pImpl;
		};
	} // namespace core
} // namespace guten

