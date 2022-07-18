#pragma once

#include "../pch.h"
#include "../GutenExports.h"
#include "View.h"

namespace guten
{
	namespace view
	{
		// Base class for all Views
		class GUTEN_API HorizontalView : public View
		{
		public:

			std::shared_ptr<View> clone() const override;

			// Adds a View to the right of any existing views.
			// Recalculates coordinates if necessary.
			// The View passed into 
			void add(std::shared_ptr<View> view);
		};
	} // namespace view
} // namespace guten

