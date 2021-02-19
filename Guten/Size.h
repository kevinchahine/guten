#pragma once

#include "GutenExports.h"

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

		int & rows() { return height; }
		const int & rows() const { return height; }

		int & cols() { return width; }
		const int & cols() const { return width; }

	public:

		int height = 0;
		int width = 0;
	};
} // namespace guten

