#include "pch.h"
#include "HorizontalView.h"

using namespace std;

namespace guten
{
	namespace view
	{
		shared_ptr<View> HorizontalView::clone() const
		{
			return make_shared<HorizontalView>(*this);
		}

		void HorizontalView::add(shared_ptr<View> view)
		{
			
		}
	} // namespace view
} // namespace guten

