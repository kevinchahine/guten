#pragma once

#include "GutenExports.h"

#include "Matrix.h"

#include <algorithm> // for min and max
#include <vector>

namespace guten
{
	namespace grids
	{
		// Size of each pushed Matrix should be the same size.
		// If any Matrix is bigger or smaller than the first Matrix,
		// then they will be cropped to the first Matricies size.
		class GUTEN_API GridView
		{
		public:
			void push(const core::Matrix & mat);

			void setGridRows(int gridRows) { m_gridRows = max(gridRows, 1); }
			int getGridRows() const { return m_gridRows; }

			void setGridCols(int gridCols) { m_gridCols = max(gridCols, 1); }
			int getGridCols() const { return m_gridCols; }

			core::Matrix toMatrix() const;

		protected:
			std::vector<core::Matrix> m_mats;

			int m_gridRows = 1;
			int m_gridCols = 1;

		};
	} // namespace grids
} // namespace guten

