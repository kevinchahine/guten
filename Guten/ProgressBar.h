#pragma once

#include "GutenExports.h"
#include "Matrix.h"

namespace guten
{
	namespace bars
	{
		class ProgressBar : public guten::core::Matrix
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

		private:
			float percent = 0.0f;
		};
	} // namespace bars
} // namespace guten

