#pragma once
#include "ProgressBar.h"

namespace guten
{
	namespace bars
	{
		class GUTEN_API BlockBar : public ProgressBar
		{
		public:
			virtual void print(std::ostream& os = std::cout);

		};
	} // bars
} // guten