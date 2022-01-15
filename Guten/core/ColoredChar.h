#pragma once

#include "../GutenExports.h"

#include "../color/Color.h"
#include "../color/iocolor.h"

namespace guten
{
	namespace core
	{
		// Stores a color and a character in one object.
		// When streamed, it automatically converts terminals color to match its value.
		template<typename CHAR_T = uint8_t>
		class ColoredChar
		{
		public:
			ColoredChar() = default;
			ColoredChar(const color::Color & color, CHAR_T character) :
				color(color),
				character(character) {}
			ColoredChar(const ColoredChar &) = default;
			ColoredChar(ColoredChar &&) noexcept = default;
			virtual ~ColoredChar() noexcept = default;

			ColoredChar & operator=(const ColoredChar &) = default;
			ColoredChar & operator=(ColoredChar &&) noexcept = default;
			ColoredChar & operator=(const CHAR_T & character) { this->character = character; return *this; }
			ColoredChar & operator=(const color::Color & color) { this->color = color; return *this; }

			ColoredChar & operator+(const CHAR_T & character) { return this->character + character; }
			ColoredChar & operator-(const CHAR_T & character) { return this->character - character; }
			ColoredChar & operator+=(const CHAR_T & character) { this->character += character; return *this; }
			ColoredChar & operator-=(const CHAR_T & character) { this->character -= character; return *this; }

			bool operator==(const ColoredChar & cc) const { return this->character == cc.character; }

			friend std::ostream & operator<<(std::ostream & os, const ColoredChar & cc) {
				os << cc.color << cc.character;

				return os;
			}

		public:
			color::Color color;

			CHAR_T character = ' ';
		};
	} // namespace core
} // namespace guten

