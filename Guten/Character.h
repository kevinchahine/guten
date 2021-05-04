#pragma once

#include "pch.h"
#include "GutenExports.h"

#include "Color.h"
#include "LineChar.h"
#include "BlockChar.h"

#include <iostream>
#include <memory>

#include <boost/variant/variant_fwd.hpp>

namespace guten
{
	namespace core
	{
		class GUTEN_API Character
		{
		public:
			using variant_t = boost::variant<uint8_t, lines::LineChar, blocks::BlockChar>;

		public:
			Character();
			Character(uint8_t ch);
			Character(const lines::LineChar & lineChar);
			Character(const blocks::BlockChar & blockChar);
			Character(const Character & rhs);
			Character(Character &&) noexcept;
			virtual ~Character() noexcept;
			Character & operator=(const Character & rhs);
			Character & operator=(Character &&) noexcept;

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

			bool operator==(const Character & rhs) const; 

			GUTEN_API friend std::ostream & operator<<(std::ostream & os, const Character & rhs);

		protected:
			std::unique_ptr<variant_t> m_value;
		};
	} // namespace core
} // namespace guten
