#include "pch.h"
#include "GridView.h"

using namespace guten::core;

#pragma error (disable: 2398)

namespace guten
{
	namespace grids
	{
		void GridView::push(const Matrix & mat)
		{
			m_mats.push_back(mat);
		}

		Matrix GridView::toMatrix() const
		{
			if (m_mats.empty()) {
				return Matrix();	// return empty matrix
			}
			
			Size sizeOf1st = m_mats.front().size();

			const int ROWS_TO_SHOW = m_mats.size() / m_gridCols + (m_mats.size() % m_gridCols > 0);
			const int COLS_TO_SHOW = min(m_mats.size(), m_gridCols);

			Matrix mat{ 
				static_cast<size_t>(ROWS_TO_SHOW * (sizeOf1st.rows() + 1)), 
				static_cast<size_t>(COLS_TO_SHOW * (sizeOf1st.cols() + 1)) };

			for (int i = 0; i < m_mats.size(); i++) {
				register int gridRow = i / m_gridCols;
				register int gridCol = i % m_gridCols;

				m_mats.at(i).copyTo(
					mat, 
					Point{ 
						gridRow * (sizeOf1st.rows() + 1), 
						gridCol * (sizeOf1st.cols() + 1) 
					}
				);
			}

			return mat;
		}
	} // namespace grids
} // namespace guten

