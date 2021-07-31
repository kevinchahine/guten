#pragma once

#include "GutenExports.h"

#include "Matrix.h"
#include "Boarder.h"

#include <algorithm> // for min and max
#include <vector>

namespace guten
{
	namespace grids
	{
		// A View that combines multiple Matrix objects into one.
		// Grids can be sized based on grid rows and grid columns.
		// When Matrix objects are pushed to grid, they are added at the next grid.
		// Size of each pushed Matrix should be the same size.
		// If any Matrix is bigger or smaller than the 1st Matrix,
		// then they will be cropped to the size of the 1st matrix.
		class GUTEN_API GridView
		{
		public:
			// Append a Matrix to the next available grid space.
			void push(const core::Matrix & mat);
			// Append a Matrix to the next available grid space.
			void push(core::Matrix&& mat);

			void setGridRows(int gridRows) { m_gridRows = std::max(gridRows, 1); }
			int getGridRows() const { return m_gridRows; }

			void setGridCols(int gridCols) { m_gridCols = std::max(gridCols, 1); }
			int getGridCols() const { return m_gridCols; }

			core::Matrix toMatrix() const;

			const core::Matrix& front() const { return m_mats.front(); }
			core::Matrix& front() { return m_mats.front(); }

			const core::Matrix& back() const { return m_mats.back(); }
			core::Matrix& back() { return m_mats.back(); }

		protected:
			std::vector<core::Matrix> m_mats;

			int m_gridRows = 1;
			int m_gridCols = 1;

		};
	} // namespace grids
} // namespace guten

