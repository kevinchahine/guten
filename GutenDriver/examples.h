#pragma once

#include <iostream>
#include <thread>
#include <chrono>

#include <Guten/guten.hpp>

namespace examples
{
	namespace bars
	{
		void progressBar();
	} // namespace bars

	namespace spinners
	{
		void flatSpinner();
		void lineSpinner();
	} // namespace spinners

	void rectangle();
}