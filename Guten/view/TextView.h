#pragma once

#include "../pch.h"
#include "../GutenExports.h"
#include "View.h"

#include <string>

namespace guten
{
	namespace view
	{
		// Displays text inside a Box. 
		// Has a fixed size. If text is too long to fit, it will only display 
		// the part that fits.
		class GUTEN_API TextView : public View
		{
		public:

		protected:
			std::string m_text = "";
		};
	} // namespace view
} // namespace guten