#pragma once

#include <iostream>

#include "GutenExports.h"

namespace guten
{
	namespace color
	{
		// Stores color index to be printed to terminal.
		// Has both a foreground and background color components which can be 
		// modified independently.
		// background is black by default
		// foreground is white by default
		// streaming to an output stream will change the cosole color from the cursor on
		// even if stream is destined to something other than a terminal like a filestream.
		class GUTEN_API Color
		{
		public:
			
			// Alias the data used to store color values
			using type = uint8_t;

			// --- Enums ---
			static const type BLACK = 0;
			static const type BLUE = 1;
			static const type GREEN = 2;
			static const type CYAN = 3;
			static const type RED = 4;
			static const type MAGENTA = 5;
			static const type YELLOW = 6;
			static const type LIGHTGRAY = 7;
			static const type GRAY = 8;
			static const type LIGHTBLUE = 9;
			static const type LIGHTGREEN = 10;
			static const type LIGHTCYAN = 11;
			static const type LIGHTRED = 12;
			static const type LIGHTMAGENTA = 13;
			static const type BROWN = 14;
			static const type WHITE = 15;

			// --- Static Methods ---
			/*GUTEN_API*/ static void printAllColors(std::ostream & os = std::cout);

			static type calcColor(type foreground, type background)
			{
				return ((foreground & 0b0000'1111) | (background << 4));
			}

			static type calcForeground(type color)
			{
				return (color & 0b0000'1111);
			}

			static type calcBackground(type color)
			{
				return (color >> 4);
			}

			// --- Constructors and Operator Overloads ---

			Color(type hue = WHITE) : hue(hue) {}
			Color(type foreground, type background) : hue(calcColor(foreground, background)) {}
			Color(const Color & foreground, const Color & background) :
				hue(calcColor(foreground.getfg(), background.getfg())) {}
			Color(const Color &) = default;
			Color(Color &&) noexcept = default;
			virtual ~Color() noexcept = default;
			Color & operator=(const Color &) = default;
			Color & operator=(Color &&) noexcept = default;

			void setfg(type hue);
			void setfg(const Color & hue);
			void setbg(type hue);
			void setbg(const Color & hue);
			void setcolor(type hue);
			void setcolor(const Color & hue);

			type getfg() const;
			type getbg() const;
			type getcolor() const;

			Color inverted() const;

		protected:
			// Stores shade of color
			type hue;
		};	// class color

		// --- Constant Global Colors ---

		extern GUTEN_API const Color black;
		extern GUTEN_API const Color blue;
		extern GUTEN_API const Color green;
		extern GUTEN_API const Color cyan;
		extern GUTEN_API const Color red;
		extern GUTEN_API const Color magenta;
		extern GUTEN_API const Color yellow;
		extern GUTEN_API const Color lightgray;
		extern GUTEN_API const Color gray;
		extern GUTEN_API const Color lightblue;
		extern GUTEN_API const Color lightgreen;
		extern GUTEN_API const Color lightcyan;
		extern GUTEN_API const Color lightred;
		extern GUTEN_API const Color lightmagenta;
		extern GUTEN_API const Color brown;
		extern GUTEN_API const Color white;


	}
}
