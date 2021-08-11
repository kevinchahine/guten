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

	namespace boards
	{
		void checkerBoard();
	} // namespace boards

	namespace color
	{
		void showAll();
	} // namespace color

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