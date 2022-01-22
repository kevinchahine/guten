#pragma once

#include "../GutenExports.h"

#include "../color/Color.h"
#include "../termcolor/termcolor.hpp"

namespace guten
{
	namespace core
	{
		// Stores a color and a character in one object.
		// When streamed, it automatically converts terminals color to match its value.
		template<typename CharT = uint8_t>
		class ColoredChar
		{
		public:
			ColoredChar() = default;
			ColoredChar(const termcolor::Color & color, CharT character) :
				color(color),
				character(character) {}
			ColoredChar(const ColoredChar &) = default;
			ColoredChar(ColoredChar &&) noexcept = default;
			virtual ~ColoredChar() noexcept = default;

			ColoredChar & operator=(const ColoredChar &) = default;
			ColoredChar & operator=(ColoredChar &&) noexcept = default;
			ColoredChar & operator=(const CharT & character) { this->character = character; return *this; }
			ColoredChar & operator=(const termcolor::ColorFBG & color) { this->color = color; return *this; }

			ColoredChar & operator+(const CharT & character) { return this->character + character; }
			ColoredChar & operator-(const CharT & character) { return this->character - character; }
			ColoredChar & operator+=(const CharT & character) { this->character += character; return *this; }
			ColoredChar & operator-=(const CharT & character) { this->character -= character; return *this; }

			bool operator==(const ColoredChar & cc) const { return this->character == cc.character; }

			friend std::ostream & operator<<(std::ostream & os, const ColoredChar & cc) {
				os << cc.color << cc.character;

				return os;
			}

		public:
			termcolor::ColorFBG color;
			// color::Color color;

			CharT character = ' ';
		};
	} // namespace core
} // namespace guten

