#pragma once

#include "GutenExports.h"
#include "Size.h"

namespace guten
{
	class GUTEN_API Point {
	public:
		Point() = default;
		Point(int row, int col) :
			row(row),
			col(col) {}
		Point(const Point &) = default;
		Point(Point &&) noexcept = default;
		virtual ~Point() noexcept = default;
		Point & operator=(const Point &) = default;
		Point & operator=(Point &&) noexcept = default;

		Point operator+(const Point & p) const {
			return Point{ this->row + p.row, this->col + p.col };
		}

		Point operator-(const Point & p) const {
			return Point{ this->row - p.row, this->col - p.col };
		}

		Point & operator+=(const Point & p) {
			this->row += p.row;
			this->col += p.col;

			return *this;
		}

		Point & operator-=(const Point & p) {
			this->row -= p.row;
			this->col -= p.col;

			return *this;
		}

		Point operator+(const Size & p) const {
			return Point{ this->row + p.height, this->col + p.width };
		}

		Point operator-(const Size & p) const {
			return Point{ this->row - p.height, this->col - p.width };
		}

		Point & operator+=(const Size & p) {
			this->row += p.height;
			this->col += p.width;

			return *this;
		}

		Point & operator-=(const Size & p) {
			this->row -= p.height;
			this->col -= p.width;

			return *this;
		}

		int row = 0;
		int col = 0;
	};
} // namespace guten