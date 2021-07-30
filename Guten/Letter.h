#pragma once

#include "pch.h"
#include "GutenExports.h"
#include "Matrix.h"
#include "Point.h"
#include "Color.h"

namespace guten
{
	namespace glyphs
	{
		class GUTEN_API Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const = 0;

			void width(uint16_t width) { m_width = width; }
			uint16_t width() const { return m_width; }

			void height(uint16_t height) { m_height = height; }
			uint16_t height() const { return m_height; }

		protected:
			uint16_t m_width = 7;	// Width of glyph in characters
			uint16_t m_height = 7;	// Height of glyph in characters

			color::Color m_color;	// Color of glyph
		};

		class GUTEN_API A : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}
		};

		class GUTEN_API B : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API C : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API D : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API E : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API F : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API G : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API H : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API I : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API J : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API K : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API L : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API M : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API N : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API O : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API P : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Q : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API R : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API S : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API T : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API U : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API V : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API W : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API X : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Y : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Z : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit0 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit1 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit2 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit3 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit4 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit5 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit6 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit7 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit8 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};

		class GUTEN_API Digit9 : public Letter
		{
		public:
			virtual void drawTo(core::Matrix& img, const Point& origin) const override {}

		};
	} // namespace glyphs
} // namespace guten

