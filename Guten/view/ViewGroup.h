#pragma once

#include "../pch.h"
#include "../GutenExports.h"
#include "View.h"

#include <tuple>
#include <list>
#include <memory>

namespace guten
{
	namespace view
	{	
		class GUTEN_API ViewGroup : public View
		{
		public:
			std::unique_ptr<ViewGroup> m_child;
			//std::list<ViewGroup *> m_children;
			std::list<std::unique_ptr<ViewGroup>> m_children;
			//std::list<std::pair<Point, std::unique_ptr<ViewGroup>>> m_subViewGroups;
		};
	} // namespace view
} // namespace guten