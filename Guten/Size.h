#pragma once

#include "GutenExports.h"

#include <iostream>

namespace guten
{
	class GUTEN_API Size {
	public:
		Size() = default;
		Size(int height, int width) :
			height(height),
			width(width) {}
		Size(const Size &) = default;
		Size(Size &&) noexcept = default;
		virtual ~Size() noexcept = default;
		Size & operator=(const Size &) = default;
		Size & operator=(Size &&) noexcept = default;

		Size operator*(int multiplier) const {
			return Size{ height * multiplier, width * multiplier };
		}

		Size operator/(int divisor) const {
			return Size{ height / divisor, width / divisor };
		}

		Size operator-(int rhs) const {
			return Size{ height - rhs, width - rhs };
		}

		Size operator+(int rhs) const {
			return Size{ height + rhs, width + rhs };
		}

		int & rows() { return height; }
		const int & rows() const { return height; }

		int & cols() { return width; }
		const int & cols() const { return width; }
		
		//friend std::ostream & operator<<(std::ostream & os, const Size & size);

	public:

		int height = 0;
		int width = 0;
	};
} // namespace guten

//std::ostream & operator<<(std::ostream & os, const guten::Size & size)
//{
//	os << '[' << size.rows() << "][" << size.cols() << ']';
//}