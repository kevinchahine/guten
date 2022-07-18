#pragma once

#include "../GutenExports.h"

#include <iostream>

namespace guten
{
	namespace blocks {
		// Externs
		extern const unsigned char BLOCK_CHARS[];

		class GUTEN_API BlockChar
		{
		public:
			BlockChar() = default;
			BlockChar(uint8_t value) : m_value(value) {}
			BlockChar(const BlockChar &) = default;
			BlockChar(BlockChar &&) noexcept = default;
			virtual ~BlockChar() noexcept = default;
			BlockChar & operator=(const BlockChar &) = default;
			BlockChar & operator=(BlockChar &&) noexcept = default;

			bool operator==(const BlockChar & other) const {
				return m_value == other.m_value;
			}
			bool operator!=(const BlockChar & other) const {
				return m_value != other.m_value;
			}

			friend std::ostream & operator<<(std::ostream & os, const BlockChar & lhs) {
				os << lhs.getCh();

				return os;
			}

			bool isValid() const { return m_value >= 0 && m_value <= 5; }
			bool isInValid() const { return !isValid(); }

			//uint8_t & value() { return m_value; }
			const uint8_t & value() const { return m_value; }

			char getCh() const { return BLOCK_CHARS[m_value]; }

			template<typename T>
			T as() const {
				return static_cast<T>(m_value);
			}

		protected:

			// Limits:
			//	0 - Empty
			//	1 - Top
			//	2 - Bottom
			//	3 - Left
			//	4 - Right
			//	5 - Full
			uint8_t m_value;
		};

		// --- pre-defined constants ---
		extern GUTEN_API const BlockChar empty;
		extern GUTEN_API const BlockChar top;
		extern GUTEN_API const BlockChar bottom;
		extern GUTEN_API const BlockChar left;
		extern GUTEN_API const BlockChar right;
		extern GUTEN_API const BlockChar full;
	} // namespace blocks
} // namespace guten