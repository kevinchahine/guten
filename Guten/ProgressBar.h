#pragma once

#include "GutenExports.h"
#include "Matrix.h"

namespace guten
{
	namespace bars
	{
		class GUTEN_API ProgressBar : public guten::core::Matrix
		{
		public:
			ProgressBar() = default;
			ProgressBar(const ProgressBar &) = default;
			ProgressBar(ProgressBar &&) noexcept = default;
			virtual ~ProgressBar() noexcept = default;
			ProgressBar & operator=(const ProgressBar &) = default;
			ProgressBar & operator=(ProgressBar &&) noexcept = default;

			void print(std::ostream & os = std::cout);

			void setPercent(float percent) { this->percent = percent; }
			float getPercent() const { return this->percent; }

			friend std::ostream & operator<<(std::ostream & os, const ProgressBar & bar)
			{
				int width = static_cast<int>(bar.percent / 10);

				auto flags = os.flags();

				os << std::setprecision(4) << bar.percent << "% ";

				for (int i = 0; i < width; i++) {
					os << '=';
				}

				os << '>';
				return os;
			}

		private:
			float percent = 0.0f;
		};
	} // namespace bars
} // namespace guten

