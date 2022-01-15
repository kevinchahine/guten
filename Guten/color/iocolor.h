// Contains a set of stream manipulators used to change the color of the terminal.

#pragma once

#include "../GutenExports.h"

#include "Color.h"

#include <iostream>
#include <stack>
#include <exception>

#define NOMINMAX   
#include "../framework.h"

namespace guten
{
	namespace color
	{
		extern GUTEN_API WORD currColor;
		extern GUTEN_API HANDLE h;
		extern GUTEN_API CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
		extern GUTEN_API std::stack<std::ios_base::fmtflags> flags;
		extern GUTEN_API std::stack<WORD> colorStack;
		
		// Stream Manipulator class
		// Purpose: Sets color of the next characters printed to console
		// Ex: 
		//		using namespace guten;
		//		
		//		cout << setcolor(color::GREEN) << "Hello";
		class setcolor
		{
		public:
			setcolor(WORD color) :
				newColor(color) {}

			setcolor(Color::type foreground, Color::type background) :
				newColor(Color::calcColor(foreground, background)) {}

			setcolor(const Color & foreground, const Color & background) :
				newColor(Color::calcColor(foreground.getcolor(), background.getcolor())) {}

			friend std::ostream& operator<<(std::ostream& os, const setcolor& rhs)
			{
				if (currColor != rhs.newColor) {
					#ifdef _WIN32	// TODO: Linux: Make this cross-platform compatible
					SetConsoleTextAttribute(h, rhs.newColor);
					#endif // _WIN32
					currColor = rhs.newColor;
				}

				return os;
			}

		protected:
			WORD newColor;
		};

		// Stream Manipulator class
		// Purpose: Sets color of the next characters printed to console
		class setfg : public setcolor
		{
		public:
			setfg(Color::type fgColor) :
				setcolor(fgColor, Color::calcBackground(static_cast<Color::type>(currColor))) {}

			setfg(const Color & fgColor) :
				setcolor(fgColor, Color::calcBackground(static_cast<Color::type>(currColor))) {}
		};

		class setbg : public setcolor
		{
		public:
			setbg(Color::type bgColor) :
				setcolor(Color::calcForeground(static_cast<Color::type>(currColor)), bgColor) {}

			setbg(const Color & bgColor) :
				setcolor(Color::calcForeground(static_cast<Color::type>(currColor)), bgColor) {}
		};

		class push
		{
		public:

			friend std::ostream& operator<<(std::ostream& os, const push& push)
			{
				flags.push(os.flags());
				colorStack.push(currColor);
				return os;
			}
		};

		class pop
		{
		public:

			friend std::ostream& operator<<(std::ostream& os, const pop& pop)
			{
				if (colorStack.empty()) {
					// throw std::exception("...");	// <-- string overload only works with MSVC
					throw std::runtime_error("Color Stack is empty. Make sure push() and pop() manipulators are balanced.");
				}
				os << setcolor(colorStack.top());
				colorStack.pop();
				os.flags(flags.top());
				flags.pop();
				return os;
			}
		};
	} // namespace color
} // namespace guten

// Intentionally declared outside a namespace 
GUTEN_API std::ostream& operator<<(std::ostream& os, const guten::color::Color& rhs);
