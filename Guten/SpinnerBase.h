#pragma once

#include "GutenExports.h"
#include <iostream>

namespace guten
{
	namespace spinners
	{
		class GUTEN_API SpinnerBase
		{
		public:
			
			///friend std::ostream & operator<<(std::ostream & os, const SpinnerBase & spinner);

		protected:

			// Range 0 - 8
			uint8_t state = 0;
		};
	}
}

