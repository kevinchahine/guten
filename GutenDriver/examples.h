#pragma once

#include <iostream>
#include <thread>
#include <chrono>

#include <Guten/guten.hpp>

namespace examples
{
	namespace Character
	{
		void test();
	}

	namespace bars
	{
		void progressBar();
	} // namespace bars

	namespace boards
	{
		void checkerBoard();
	} // namespace boards

	namespace core
	{
		void matrix();
	} // namespace core

	namespace spinners
	{
		void flatSpinner();
		void lineSpinner();
	} // namespace spinners

	void rectangle();
}