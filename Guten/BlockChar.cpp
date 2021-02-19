#include "pch.h"
#include "BlockChar.h"

namespace guten
{
	namespace blocks
	{
		const uint8_t BLOCK_CHARS[] = {
			32,			// space (empty block)
			223,		// upper half block
			220,		// lower half block
			221,		// left half block
			222,		// right half block
			219			// full block
		};

		// --- Pre-defined Constants (Globals) ---
		GUTEN_API const BlockChar empty(0);
		GUTEN_API const BlockChar top(1);
		GUTEN_API const BlockChar bottom(2);
		GUTEN_API const BlockChar left(3);
		GUTEN_API const BlockChar right(4);
		GUTEN_API const BlockChar full(5);
	} // namespace blocks
} // namespace guten