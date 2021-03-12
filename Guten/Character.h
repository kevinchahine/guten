#pragma once

#include "pch.h"
#include "GutenExports.h"

#include "Color.h"
#include "LineChar.h"
#include "BlockChar.h"

#include <boost/variant.hpp>	// Break this down into only the headers that we need

#include <iostream>

namespace guten
{
	namespace core
	{
		class GUTEN_API Character
		{
		public:

			Character() = default;
			Character(uint8_t ch) : m_value(ch) {};
			Character(const lines::LineChar & lineChar) : m_value(lineChar) {};
			Character(const blocks::BlockChar & blockChar) : m_value(blockChar) {};
			Character(const Character &) = default;
			Character(Character &&) noexcept = default;
			virtual ~Character() noexcept = default;
			Character & operator=(const Character &) = default;
			Character & operator=(Character &&) noexcept = default;

			Character & operator=(uint8_t ch);
			Character & operator=(const lines::LineChar & lineChar);
			Character & operator=(const blocks::BlockChar & blockChar);

			// ex:
			//	Character a = guten::LineChar::horizontal;
			//	Character b = guten::LineChar::vertical;
			//	Character c = a + b;
			Character operator+(uint8_t ch) const;
			Character operator+(const lines::LineChar & lineChar) const;
			Character operator+(const blocks::BlockChar & blockChar) const;

			Character & operator+=(uint8_t ch);
			Character & operator+=(const lines::LineChar & lineChar);
			Character & operator+=(const blocks::BlockChar & blockChar);

			Character operator-(uint8_t ch) const;
			Character operator-(const lines::LineChar & lineChar) const;
			Character operator-(const blocks::BlockChar & blockChar) const;

			bool operator==(const Character & rhs) const { return false; }// TODO: fix this }

			GUTEN_API friend std::ostream & operator<<(std::ostream & os, const Character & rhs)
			{
				os << rhs.m_value;
				
				return os;
			}

		protected:
			boost::variant<uint8_t, lines::LineChar, blocks::BlockChar> m_value;
		};
	} // namespace core
} // namespace guten

//GUTEN_API std::ostream & operator<<(std::ostream & os, const guten::core::Character & rhs);
