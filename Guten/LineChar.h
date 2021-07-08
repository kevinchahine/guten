#pragma once

#include "pch.h"
#include "GutenExports.h"

#include <iostream>
#include <bitset>
#include <iterator>

namespace guten
{
	namespace lines {
		// Externs
		GUTEN_API extern const unsigned char LINES[];

		class GUTEN_API LineChar
		{
		public:
			LineChar() = default;
			LineChar(uint8_t value) : m_value(value) {}
			LineChar(const LineChar &) = default;
			LineChar(LineChar &&) noexcept = default;
			virtual ~LineChar() noexcept = default;
			LineChar & operator=(const LineChar &) = default;
			LineChar & operator=(LineChar &&) noexcept = default;

			// Adds a line component to the character
			// ex: 
			// using namespace guten;
			// LineChar l;
			// l = lines::right + lines::left;
			// cout << l;		// prints horizontal line
			LineChar operator+(const LineChar & other) const {
				// get overlapping bits. We only care about 4 LSBs
				///uint8_t overlap = this->m_value & other.m_value;	
				///overlap = (overlap << 4);	// shift them to 4 MSBs
				return this->m_value | other.m_value;/// | overlap;
			}

			// Adds a line component to the character
			// ex: 
			// using namespace guten;
			// LineChar l = lines::right;
			// l += lines::left;
			// cout << l;		// prints horizontal line
			LineChar operator+=(const LineChar & other) {
				/// get overlapping bits. We only care about 4 LSBs
				///uint8_t overlap = this->m_value & other.m_value;
				///overlap = (overlap << 4);	// shift them to 4 MSBs
				this->m_value = this->m_value | other.m_value;/// | overlap;
				return this->m_value;
			}

			// Removes a line component from the character
			// ex: 
			// using namespace guten;
			// LineChar l = lines::cross - lines::up;
			// cout << l;		// prints T-shaped line
			LineChar operator-(const LineChar & other) const {
				///uint8_t overlap = this->m_value & other.m_value;
				///overlap = overlap & 0b1111'0000;

				uint8_t temp = this->m_value & ~other.m_value;/// &~overlap;

				return temp;
			}

			// Removes a line component from the character
			// ex: 
			// using namespace guten;
			// LineChar l = lines::cross;
			// l -= lines::up;
			// cout << l;		// prints T-shaped line
			LineChar operator-=(const LineChar & other) {
				this->m_value = this->m_value & ~other.m_value;
				return this->m_value;
			}

			bool operator==(const LineChar & other) const {
				return m_value == other.m_value;
			}

			bool operator!=(const LineChar & other) const {
				return m_value != other.m_value;
			}

			friend std::ostream & operator<<(std::ostream & os, const LineChar & lhs) {
				os << LINES[lhs.m_value];

				return os;
			}

			bool isValid() const { return LINES[m_value] != '#'; }
			bool isInValid() const { return !isValid(); }

			// Returns bitwise value of LineChar. 
			// Not the displayable character itself.
			uint8_t & value() { return m_value; }
			const uint8_t & value() const { return m_value; }

			template<typename T>
			T as() const {
				return static_cast<T>(m_value);
			}

			template<>
			unsigned char as<unsigned char>() const {
				return LINES[m_value];
			}
			
			template<>
				char as<char>() const {
				return LINES[m_value];
			}

		protected:
			// Bitwise value indicating direction of each line
			// To be used as index to LINES[] array to get cooresponding unicode line character
			// 
			// Does not equal value of the cooresponding character
			// 
			// Ex: 
			//	uint8_t m_value = 0b0000'0011;		// 3 - left, right (horizontal line)
			//	cout << m_value;					// No - does not print horizontal line
			//	cout << guten::LINES[m_value];		// Yes - prints horizontal line char
			// 
			// 0 (LSB)	RIGHT
			// 1		LEFT
			// 2		DOWN
			// 3		UP
			// 4		ANOTHER RIGHT
			// 5		ANOTHER LEFT
			// 6		ANOTHER DOWN
			// 7 (MSB)	ANOTHER UP
			uint8_t m_value = 0b0000'0000;
		};

		// --- pre-defined constants ---
		const LineChar up(0b0000'1000);
		const LineChar double_up(0b1000'1000);
		const LineChar down(0b0000'0100);
		const LineChar double_down(0b0100'0100);
		const LineChar left(0b0000'0010);
		const LineChar double_left(0b0010'0010);
		const LineChar right(0b0000'0001);
		const LineChar double_right(0b0001'0001);
		const LineChar horizontal(0b0000'0011);
		const LineChar double_horizontal(0b0011'0011);
		const LineChar vertical(0b0000'1100);
		const LineChar double_vertical(0b1100'1100);
		const LineChar cross(0b0000'1111);
		const LineChar double_cross(0b1111'1111);
	} // namespace lines
} // namespace guten

