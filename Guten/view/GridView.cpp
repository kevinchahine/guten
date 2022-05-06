#include "../pch.h"
#include "GridView.h"

using namespace guten::core;

//#pragma error (disable: 2398)

namespace guten
{
	namespace grids	// TODO: Rename namespace grids with namespace view
	{
		void GridView::push(const Matrix & mat)
		{
			m_mats.push_back(mat);
		}

		void GridView::push(core::Matrix&& mat)
		{
			m_mats.push_back(std::move(mat));
		}

		Matrix GridView::toMatrix() const
		{
			if (m_mats.empty()) {
				return Matrix();	// return empty matrix
			}
			
			Size sizeOf1st = m_mats.front().size();

			const int ROWS_TO_SHOW = m_mats.size() / m_gridCols + (m_mats.size() % m_gridCols > 0);
			const int COLS_TO_SHOW = std::min(m_mats.size(), (size_t) m_gridCols);

			Matrix mat{ 
				ROWS_TO_SHOW * (sizeOf1st.rows() + 1), 
				COLS_TO_SHOW * (sizeOf1st.cols() + 1) 
			};

			for (int i = 0; i < m_mats.size(); i++) {
				int gridRow = i / m_gridCols;
				int gridCol = i % m_gridCols;

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

