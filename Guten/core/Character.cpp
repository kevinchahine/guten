#include "../pch.h"

#include "Character.h"

#include <boost/variant.hpp>
#include <boost/variant/variant.hpp>

using namespace std;
using namespace boost;

namespace guten
{
	namespace core
	{
		using variant_t = boost::variant<uint8_t, lines::LineChar, blocks::BlockChar>;

		// --- PRIVATE IMPLEMENTATION ---

		class Character::Impl
		{
		public:
			Impl() : m_value(make_unique<variant_t>('\0')) {};
			Impl(uint8_t ch) : m_value(make_unique<variant_t>(ch)) {}
			Impl(const lines::LineChar & lineChar) : m_value(make_unique<variant_t>(lineChar)) {};
			Impl(const blocks::BlockChar & blockChar) : m_value(make_unique<variant_t>(blockChar)) {};
			Impl(const Impl & rhs) : m_value(make_unique<variant_t>(*rhs.m_value)) {};
			Impl(Impl && rhs) noexcept : m_value(std::move(rhs.m_value)) {};
			virtual ~Impl() noexcept { m_value.reset(); }

			Impl & operator=(const Impl & rhs)
			{
				m_value = make_unique<variant_t>(*rhs.m_value);

				return *this;
			}
			Impl & operator=(Impl && rhs) noexcept
			{
				m_value = std::move(rhs.m_value);

				return *this;
			}
			Impl & operator=(uint8_t ch)
			{
				*m_value = ch;

				return *this;
			}
			Impl & operator=(const lines::LineChar & lineChar)
			{
				*m_value = lineChar;

				return *this;
			}
			Impl & operator=(const blocks::BlockChar & blockChar)
			{
				*m_value = blockChar;

				return *this;
			}

			// ex:
			//	Impl a = guten::LineChar::horizontal;
			//	Impl b = guten::LineChar::vertical;
			//	Impl c = a + b;
			Impl operator+(uint8_t ch) const
			{
				Impl ret;

				try {
					ret = boost::get<uint8_t>(*m_value) + ch;
				}
				catch (std::exception &) {
					ret = ch;
				}

				return ret;
			}
			Impl operator+(const lines::LineChar & lineChar) const
			{
				Impl ret;

				try {
					ret = boost::get<lines::LineChar>(*m_value) + lineChar;
				}
				catch (std::exception &) {
					ret = lineChar;
				}

				return ret;
			}
			Impl operator+(const blocks::BlockChar & blockChar) const
			{
				Impl ret;

				try {
					ret = /*boost::get<blocks::BlockChar>(*pImpl) + */blockChar;
				}
				catch (std::exception &) {
					ret = blockChar;
				}

				return ret;
			}

			Impl & operator+=(uint8_t ch)
			{
				try {
					*m_value = boost::get<uint8_t>(*m_value) += ch;
				}
				catch (std::exception &) {
					*m_value = ch;
				}

				return *this;
			}
			Impl & operator+=(const lines::LineChar & lineChar)
			{
				try {
					*m_value = boost::get<lines::LineChar>(*m_value) + lineChar;
				}
				catch (std::exception &) {
					*m_value = lineChar;
				}

				return *this;
			}
			Impl & operator+=(const blocks::BlockChar & blockChar)
			{
				try {
					*m_value = /*boost::get<blocks::BlockChar>(*m_value) + */blockChar;
				}
				catch (std::exception &) {
					*m_value = blockChar;
				}

				return *this;
			}

			Impl operator-(uint8_t ch) const
			{
				Impl ret;

				try {
					*m_value = boost::get<uint8_t>(*m_value) - ch;
				}
				catch (std::exception &) {
					ret = ch;
				}

				return ret;
			}
			Impl operator-(const lines::LineChar & lineChar) const
			{
				Impl ret;

				try {
					*m_value = boost::get<lines::LineChar>(*m_value) - lineChar;
				}
				catch (std::exception &) {
					ret = lineChar;
				}

				return ret;
			}
			Impl operator-(const blocks::BlockChar & blockChar) const 
			{
				Impl ret;

				try {
					*m_value = /**boost::get<blocks::BlockChar>(*m_value) -*/ blockChar;
				}
				catch (std::exception &) {
					ret = blockChar;
				}

				return ret;
			}

			bool operator==(const Impl & rhs) const
			{
				return *m_value == *rhs.m_value;
			}
			
			GUTEN_API friend std::ostream & operator<<(std::ostream & os, const Impl & rhs)
			{
				os << *rhs.m_value;

				return os;
			}

		protected:
			std::unique_ptr<variant_t> m_value;
		};

		// --- PUBLIC INTERFACE ---

		// ========================================================================

		Character::Character() :
			pImpl(make_unique<Impl>('\0'))
		{
		}

		Character::Character(uint8_t ch) :
			pImpl(make_unique<Impl>(ch))
		{
		}

		Character::Character(const lines::LineChar & lineChar) :
			pImpl(make_unique<Impl>(lineChar))
		{
		}

		Character::Character(const blocks::BlockChar & blockChar) :
			pImpl(make_unique<Impl>(blockChar))
		{
		}

		Character::Character(const Character & rhs) :
			pImpl(make_unique<Impl>(*rhs.pImpl))
		{
		}

		Character::Character(Character && rhs) noexcept :
			pImpl(std::move(rhs.pImpl))
		{
		}

		Character::~Character() noexcept
		{
			pImpl.reset();
		}

		Character & Character::operator=(const Character & rhs)
		{
			pImpl = make_unique<Impl>(*rhs.pImpl);

			return *this;
		}

		Character & Character::operator=(Character && rhs) noexcept
		{
			pImpl = std::move(rhs.pImpl);

			return *this;
		}

		Character & Character::operator=(uint8_t ch)
		{
			*pImpl = ch;

			return *this;
		}

		Character & Character::operator=(const lines::LineChar & lineChar)
		{
			*pImpl = lineChar;

			return *this;
		}

		Character & Character::operator=(const blocks::BlockChar & blockChar)
		{
			*pImpl = blockChar;

			return *this;
		}

		// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Character Character::operator+(uint8_t ch) const
		{
			Character character;

			(*character.pImpl) = (*pImpl) + ch;

			return character;
		}

		Character Character::operator+(const lines::LineChar & lineChar) const
		{
			Character character;

			(*character.pImpl) = (*pImpl) + lineChar;

			return character;
		}

		Character Character::operator+(const blocks::BlockChar & blockChar) const
		{
			Character character;

			(*character.pImpl) = (*pImpl) + blockChar;

			return character;
		}

		Character & Character::operator+=(uint8_t ch)
		{
			(*this->pImpl) += ch;

			return (*this);
		}

		Character & Character::operator+=(const lines::LineChar & lineChar)
		{
			(*this->pImpl) = (*this->pImpl) + lineChar;

			return (*this);
		}

		Character & Character::operator+=(const blocks::BlockChar & blockChar)
		{
			(*this->pImpl) += blockChar;

			return (*this);
		}

		// ------------------------------------------------------------------------

		Character Character::operator-(uint8_t ch) const
		{
			Character character;

			(*character.pImpl) = (*pImpl) - ch;

			return character;
		}

		Character Character::operator-(const lines::LineChar & lineChar) const
		{
			Character character;

			(*character.pImpl) = (*pImpl) - lineChar;

			return character;
		}

		Character Character::operator-(const blocks::BlockChar & blockChar) const
		{
			Character character;

			(*character.pImpl) = (*pImpl) - blockChar;

			return character;
		}

		bool Character::operator==(const Character & rhs) const
		{
			return (*this->pImpl) == (*rhs.pImpl);
		}

		// << << << << << << << << << << << << << << << << << << << << << << << << 
		std::ostream & operator<<(std::ostream & os, const guten::core::Character & rhs)
		{
			os << *rhs.pImpl;

			return os;
		}
	} // namespace core
} // namespace guten

