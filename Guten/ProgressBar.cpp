#include "pch.h"
#include "ProgressBar.h"

#include <iostream>

using namespace std;

namespace guten
{
	namespace bars
	{
		void ProgressBar::print(std::ostream & os)
		{
			int width = static_cast<int>(percent / 10);
			for (int i = 0; i < width; i++) {
				os << '=';
			}

			os << '>' << endl;
		}
	} // namespace bars
} // namespace guten
