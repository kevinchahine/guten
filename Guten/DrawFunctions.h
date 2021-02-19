#pragma once

#include "GutenExports.h"
#include "Character.h"
#include "Matrix.h"

#include <iostream>
#include <iomanip>

namespace guten
{
	namespace draw
	{
		// -------------------------------- DECLARATIONS --------------------------

		GUTEN_API void horizontalLine(core::Matrix & mat, const Point & p1, size_t width, const color::Color & color = color::white, bool doubleLines = false);

		GUTEN_API void verticalLine(core::Matrix & mat, const Point & p1, size_t height, const color::Color & color = color::white, bool doubleLines = false);

		GUTEN_API void rectangle(core::Matrix & mat, const Point & p1, const Point & p2, const color::Color & color = color::white, bool doubleLines = false);

		GUTEN_API void rectangle(core::Matrix & mat, const Point & origin, const Size & size, const color::Color & color = color::white, bool doubleLines = false);

		GUTEN_API void putText(core::Matrix & mat, const std::string & text, const Point & origin, const color::Color & color = color::white);

	} // namespace draw
} // namespace guten