#include "examples.h"
#include "examples_checker_board.h"

#include <termcolor/termcolor.hpp>

using namespace std;

int main()
{
	examples::checker_board::test();
	examples::checker_board::printMini();
	//examples::Character::test();
	//examples::bars::progressBar();
	//examples::boards::checkerBoard();
	//examples::color::showAll();
	//examples::core::matrix();
	//examples::spinners::flatSpinner();
	//examples::spinners::lineSpinner();
	//examples::rectangle();
	//std::cout << termcolor::red << "Hello, ";                   // 16 colors
	//std::cout << termcolor::color<100> << "Colorful ";          // 256 colors
	//std::cout << termcolor::color<211, 54, 130> << "World!";    // true colors
	//std::cout << std::endl;

	//this_thread::sleep_for(chrono::seconds(1));
	cin.get();
	return 0;
}