#include "pch.h"

#include "Character.h"

namespace guten
{
	namespace core
	{
		// ========================================================================

		Character & Character::operator=(uint8_t ch)
		{
			m_value = ch;

			return *this;
		}

		Character & Character::operator=(const lines::LineChar & lineChar)
		{
			m_value = lineChar;

			return *this;
		}

		Character & Character::operator=(const blocks::BlockChar & blockChar)
		{
			m_value = blockChar;

			return *this;
		}

		// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Character Character::operator+(uint8_t ch) const
		{
			Character ret;

			if (const uint8_t * val = boost::get<uint8_t>(&m_value)) {
				ret = *val + ch;
			}
			else {
				ret = ch;
			}

			return ret;
		}

		Character Character::operator+(const lines::LineChar & lineChar) const
		{
			Character ret;

			if (const lines::LineChar * val = boost::get<lines::LineChar>(&m_value)) {
				ret = *val + lineChar;
			}
			else {
				ret = lineChar;
			}

			return ret;
		}

		Character Character::operator+(const blocks::BlockChar & blockChar) const
		{
			Character ret;

			if (const blocks::BlockChar * val = boost::get<blocks::BlockChar>(&m_value)) {
				ret = blockChar;
			}
			else {
				ret = blockChar;
			}

			return ret;
		}

		Character & Character::operator+=(uint8_t ch)
		{
			if (uint8_t * val = boost::get<uint8_t>(&m_value)) {
				*val += ch;
			}
			else {
				m_value = ch;
			}

			return *this;
		}

		Character & Character::operator+=(const lines::LineChar & lineChar)
		{
			if (lines::LineChar * val = boost::get<lines::LineChar>(&m_value)) {
				*val += lineChar;
			}
			else {
				m_value = lineChar;
			}

			return *this;
		}

		Character & Character::operator+=(const blocks::BlockChar & blockChar)
		{
			if (blocks::BlockChar * val = boost::get<blocks::BlockChar>(&m_value)) {
				*val = blockChar;
			}
			else {
				m_value = blockChar;
			}

			return *this;
		}

		// ------------------------------------------------------------------------

		Character Character::operator-(uint8_t ch) const
		{
			Character ret;

			if (const uint8_t * val = boost::get<uint8_t>(&m_value)) {
				ret = *val - ch;
			}
			else {
				ret = ch;
			}

			return ret;
		}

		Character Character::operator-(const lines::LineChar & lineChar) const
		{
			Character ret;

			if (const lines::LineChar * val = boost::get<lines::LineChar>(&m_value)) {
				ret = *val - lineChar;
			}
			else {
				ret = lineChar;
			}

			return ret;
		}

		Character Character::operator-(const blocks::BlockChar & blockChar) const
		{
			Character ret;

			if (const blocks::BlockChar * val = boost::get<blocks::BlockChar>(&m_value)) {
				ret = blockChar;
			}
			else {
				ret = blockChar;
			}

			return ret;
		}

	} // namespace core
} // namespace guten

// << << << << << << << << << << << << << << << << << << << << << << << << 
//std::ostream & operator<<(std::ostream & os, const guten::core::Character & rhs)
//{
//	os << rhs.value();
//
//	return os;
//}
