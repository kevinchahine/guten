#include "../pch.h"
#include "BlockBar.h"
#include "../blocks/BlockChar.h"

using namespace std;

namespace guten
{
	namespace bars
	{
		void BlockBar::print(std::ostream& os)
		{
			auto flags = os.flags();

			int width = (milliPercent * barWidth) / 100'000;

			os << std::right
				<< std::setfill(blocks::full.getCh()) << std::setw(width) << '\0'
				<< std::setfill(blocks::empty.getCh()) << std::setw(barWidth - width + 1) << '\0'
				<< std::setprecision(6) << getPercent() << "%";
			
			os.flags(flags);
		}
	} // bars
} // guten