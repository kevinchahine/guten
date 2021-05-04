#include "pch.h"

#include "Character.h"

#include <boost/variant.hpp>
#include <boost/variant/variant.hpp>

using namespace std;
using namespace boost;

namespace guten
{
	namespace core
	{
		// ========================================================================

		Character::Character() :
			m_value(make_unique<variant_t>('\0'))
		{
		}

		Character::Character(uint8_t ch) :
			m_value(make_unique<variant_t>(ch))
		{
		}

		Character::Character(const lines::LineChar & lineChar) :
			m_value(make_unique<variant_t>(lineChar))
		{
		}

		Character::Character(const blocks::BlockChar & blockChar) :
			m_value(make_unique<variant_t>(blockChar))
		{
		}

		Character::Character(const Character & rhs) :
			m_value(make_unique<variant_t>(*rhs.m_value))
		{
		}

		Character::Character(Character && rhs) noexcept :
			m_value(std::move(rhs.m_value))
		{
		}

		Character::~Character() noexcept
		{
			m_value.reset();
		}

		Character & Character::operator=(const Character & rhs)
		{
			m_value = make_unique<variant_t>(*rhs.m_value);

			return *this;
		}

		Character & Character::operator=(Character && rhs) noexcept
		{
			m_value = std::move(rhs.m_value);

			return *this;
		}

		Character & Character::operator=(uint8_t ch)
		{
			*m_value = ch;

			return *this;
		}

		Character & Character::operator=(const lines::LineChar & lineChar)
		{
			*m_value = lineChar;

			return *this;
		}

		Character & Character::operator=(const blocks::BlockChar & blockChar)
		{
			*m_value = blockChar;

			return *this;
		}

		// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Character Character::operator+(uint8_t ch) const
		{
			Character ret;

			try {
				ret = boost::get<uint8_t>(*m_value) + ch;
			}
			catch (std::exception &) {
				ret = ch;
			}
			
			return ret;
		}

		Character Character::operator+(const lines::LineChar & lineChar) const
		{
			Character ret;

			try {
				ret = boost::get<lines::LineChar>(*m_value) + lineChar;
			}
			catch (std::exception &) {
				ret = lineChar;
			}

			return ret;
		}

		Character Character::operator+(const blocks::BlockChar & blockChar) const
		{
			Character ret;

			try {
				ret = /*boost::get<blocks::BlockChar>(*m_value) + */blockChar;
			}
			catch (std::exception &) {
				ret = blockChar;
			}

			return ret;
		}

		Character & Character::operator+=(uint8_t ch)
		{
			try {
				*m_value = boost::get<uint8_t>(*m_value) += ch;
			}
			catch (std::exception &) {
				*m_value = ch;
			}

			return *this;
		}

		Character & Character::operator+=(const lines::LineChar & lineChar)
		{
			try {
				*m_value = boost::get<lines::LineChar>(*m_value) + lineChar;
			}
			catch (std::exception &) {
				*m_value = lineChar;
			}

			return *this;
		}

		Character & Character::operator+=(const blocks::BlockChar & blockChar)
		{
			try {
				*m_value = /*boost::get<blocks::BlockChar>(*m_value) + */blockChar;
			}
			catch (std::exception &) {
				*m_value = blockChar;
			}

			return *this;
		}

		// ------------------------------------------------------------------------

		Character Character::operator-(uint8_t ch) const
		{
			Character ret;

			try {
				*m_value = boost::get<uint8_t>(*m_value) - ch;
			}
			catch (std::exception &) {
				ret = ch;
			}

			return ret;
		}

		Character Character::operator-(const lines::LineChar & lineChar) const
		{
			Character ret;

			try {
				*m_value = boost::get<lines::LineChar>(*m_value) - lineChar;
			}
			catch (std::exception &) {
				ret = lineChar;
			}

			return ret;
		}

		Character Character::operator-(const blocks::BlockChar & blockChar) const
		{
			Character ret;

			try {
				*m_value = /**boost::get<blocks::BlockChar>(*m_value) -*/ blockChar;
			}
			catch (std::exception &) {
				ret = blockChar;
			}

			return ret;
		}

		bool Character::operator==(const Character & rhs) const
		{
			//return m_value->apply_visitor(boost::equal_comp);
			return false;// *m_value == *rhs.m_value;
		}

		// << << << << << << << << << << << << << << << << << << << << << << << << 
		std::ostream & operator<<(std::ostream & os, const guten::core::Character & rhs)
		{
			os << *rhs.m_value;

			return os;
		}
	} // namespace core
} // namespace guten

