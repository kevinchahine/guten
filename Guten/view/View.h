#pragma once

#include "../pch.h"
#include "../GutenExports.h"
#include "../core/Matrix.h"
#include "AlignedView.h"

#include <list>
#include <memory>

namespace guten
{
	namespace view
	{
		// Base class for all Views
		// A rectangular display that can contain other Views or be
		// displayed by itself. 
		// Can optionally have a boarder.
		class GUTEN_API View : public core::Matrix
		{
		public:

			virtual std::shared_ptr<View> clone() const;

		protected:
			
		};
	} // namespace view
} // namespace guten

