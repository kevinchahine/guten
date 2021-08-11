#pragma once

#include "GutenExports.h"
#include "Matrix.h"

namespace guten
{
	namespace bars
	{
		class GUTEN_API ProgressBar /*: public guten::core::Matrix*/ // TODO: I Don't think we need this inheritance
		{
		public:
			ProgressBar() = default;
			ProgressBar(const ProgressBar &) = default;
			ProgressBar(ProgressBar &&) noexcept = default;
			virtual ~ProgressBar() noexcept = default;
			ProgressBar & operator=(const ProgressBar &) = default;
			ProgressBar & operator=(ProgressBar &&) noexcept = default;

			//virtual void print(std::ostream & os = std::cout);

			// In units of percent.
			// Example: 40.2f means 40.2%
			void setPercent(float percent) { this->milliPercent = percent * 1000; }
			// In units of percent.
			// Example: 40.2f means 40.2%
			float getPercent() const { return static_cast<float>(this->milliPercent) / 1000.0f; }

			// In units of characters.
			void setBarWidth(uint16_t barWidth) { this->barWidth = barWidth; }
			// In units of characters.
			uint16_t getBarWidth() const { return this->barWidth; }

			friend std::ostream & operator<<(std::ostream & os, const ProgressBar & bar)
			{
				auto flags = os.flags();

				int width = (bar.milliPercent * bar.barWidth) / 100'000;

				os << std::right
					<< std::setfill('=') << std::setw(width) << '>'
					<< std::setfill(' ') << std::setw(bar.barWidth - width + 1) 
					<< std::setprecision(5) << bar.getPercent() << "%";

				os.flags(flags);

				return os;
			}

		protected:
			// 40% is stored as 40'000
			int milliPercent = 0;

			// Width of progress bar in units of characters
			uint16_t barWidth = 10;
		};
	} // namespace bars
} // namespace guten

