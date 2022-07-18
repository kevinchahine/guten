#pragma once

#include "SpinnerBase.h"

namespace guten
{
	namespace spinners
	{
		class GUTEN_API LineSpinner : public SpinnerBase
		{
		public:

			GUTEN_API friend std::ostream & operator<<(std::ostream & os, LineSpinner & spinner);

		};
	} // namespace spinners
} // namespace guten
