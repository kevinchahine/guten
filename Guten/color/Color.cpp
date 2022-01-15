#include "../pch.h"
#include "Color.h"
#include "iocolor.h"

namespace guten
{
	namespace color
	{
		Color::type negatives[] = {
			Color::WHITE,		// BLACK
			Color::CYAN,		// BLUE	???
			Color::RED,			// GREEN
			Color::BLUE,		// CYAN	???
			Color::GREEN,		// RED
			Color::YELLOW,		// MAGENTA
			Color::MAGENTA,		// YELLOW
			Color::GRAY,		// LIGHTGRAY
			Color::LIGHTGRAY,	// GRAY
			Color::LIGHTCYAN,	// LIGHTBLUE	???
			Color::LIGHTRED,	// LIGHTGREEN
			Color::LIGHTBLUE,	// LIGHTCYAN	???
			Color::LIGHTGREEN,	// LIGHTRED
			Color::BROWN,		// LIGHTMAGENTA
			Color::LIGHTMAGENTA,// BROWN
			Color::BLACK,		// WHITE
		};

		void Color::setfg(type hue)
		{
			type bg = calcBackground(this->hue);

			this->hue = calcColor(hue, bg);
		}

		void Color::setfg(const Color & hue)
		{
			setfg(hue.getfg());
		}

		void Color::setbg(type hue)
		{
			type fg = calcForeground(this->hue);

			this->hue = calcColor(fg, hue);
		}

		void Color::setbg(const Color & hue)
		{
			setbg(hue.getfg());
		}

		void Color::setcolor(type hue)
		{
			this->hue = hue;
		}

		void Color::setcolor(const Color & hue)
		{
			setcolor(hue.getcolor());
		}

		void Color::setAlpha(bool isSolidFg, bool isSolidBg)
		{
			alpha[fgIndex] = isSolidFg;
			alpha[bgIndex] = isSolidBg;
		}

		void Color::setfgAlpha(bool fgAlpha)
		{
			alpha[fgIndex] = fgAlpha;
		}

		void Color::setbgAlpha(bool bgAlpha)
		{
			alpha[bgIndex] = bgAlpha;
		}

		Color::type Color::getfg() const
		{
			return calcForeground(this->hue);
		}

		Color::type Color::getbg() const
		{
			return calcBackground(this->hue);
		}

		Color::type Color::getcolor() const
		{
			return this->hue;
		}

		Color Color::inverted() const
		{
			Color ret = (*this);
			
			ret.setcolor(Color(calcBackground(hue), calcForeground(hue)));
				
			bool temp = ret.alpha[fgIndex];
			ret.alpha[fgIndex] = ret.alpha[bgIndex];
			ret.alpha[bgIndex] = temp;

			return ret;
		}

		Color Color::negative() const
		{
			return negatives[hue];
		}

		// --- Externs ---

		GUTEN_API const Color black(Color::BLACK);
		GUTEN_API const Color blue(Color::BLUE);
		GUTEN_API const Color green(Color::GREEN);
		GUTEN_API const Color cyan(Color::CYAN);
		GUTEN_API const Color red(Color::RED);
		GUTEN_API const Color magenta(Color::MAGENTA);
		GUTEN_API const Color yellow(Color::YELLOW);
		GUTEN_API const Color lightgray(Color::LIGHTGRAY);
		GUTEN_API const Color gray(Color::GRAY);
		GUTEN_API const Color lightblue(Color::LIGHTBLUE);
		GUTEN_API const Color lightgreen(Color::LIGHTGREEN);
		GUTEN_API const Color lightcyan(Color::LIGHTCYAN);
		GUTEN_API const Color lightred(Color::LIGHTRED);
		GUTEN_API const Color lightmagenta(Color::LIGHTMAGENTA);
		GUTEN_API const Color brown(Color::BROWN);
		GUTEN_API const Color white(Color::WHITE);
	} // namespace color
} // namespace guten