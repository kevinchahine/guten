#pragma once

#include "SpinnerBase.h"

namespace guten
{
	namespace spinners
	{
		class GUTEN_API FlatSpinner : public SpinnerBase
		{
		public:

			GUTEN_API friend std::ostream & operator<<(std::ostream & os, FlatSpinner & spinner);

		private:
			static const char chars[];
		};
	}
}