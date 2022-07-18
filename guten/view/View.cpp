#include "../pch.h"
#include "View.h"

using namespace std;

namespace guten
{
	namespace view
	{
		std::shared_ptr<View> View::clone() const
		{
			return std::make_shared<View>(*this);
		}
	} // namespace view
} // namespace guten
