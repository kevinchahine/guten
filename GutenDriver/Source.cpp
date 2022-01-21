#include "examples.h"
#include "examples_checker_board.h"
#include "examples_draw_functions.h"
#include "examples_progress_bar.h"

#define NOMINMAX	// Prevents pollution of min/max macros from #include "windows.h"
#include "../Guten/termcolor/termcolor.hpp"

using namespace std;

int main()
{
	cout << termcolor::red << "Hello, "					// 16 colors
		<< termcolor::color<100> << "Colorful "			// 256 colors
		<< termcolor::color<211, 54, 130> << "world!"	// true colors
		<< endl;

	cout << termcolor::color<181, 137, 0> << "#b58900" << termcolor::reset << endl
		<< termcolor::bold << termcolor::red << "bold red message" << termcolor::reset << endl
		<< termcolor::dark << termcolor::blue << "dark blue message" << termcolor::reset << endl
		<< termcolor::italic << "italic message" << termcolor::reset << endl
		<< termcolor::underline << "underlined message" << termcolor::reset << endl
	    << termcolor::blink     << "blinked message"    << termcolor::reset << endl
	    << termcolor::reverse   << "reversed message"   << termcolor::reset << endl
	    << termcolor::concealed << "concealed message"  << termcolor::reset << endl
	    << termcolor::crossed   << "crossed message"    << termcolor::reset << endl
	    << "default message"    << endl;

	termcolor::Color<char> c(240,35, 64);
	termcolor::OnColor<char> bg(0, 255, 255);
	cout << termcolor::blink << c << bg << "--- This is where its at ---" << termcolor::reset << endl;
	
	//examples::checker_board::test();
	//examples::checker_board::printMini();
	//examples::Character::test();
	//examples::bars::progressBar();
	//examples::bars::blockBar();
	//examples::boards::checkerBoard();
	//examples::color::showAll();
	//examples::core::matrix();
	//examples::spinners::flatSpinner();
	//examples::spinners::lineSpinner();
	//examples::rectangle();
	//examples::draw::lines();

	//std::cout << termcolor::red << "Hello, ";                   // 16 colors
	//std::cout << termcolor::color<100> << "Colorful ";          // 256 colors
	//std::cout << termcolor::color<211, 54, 130> << "World!";    // true colors
	//std::cout << std::endl;

	//this_thread::sleep_for(chrono::seconds(1));
	//cin.get();
	return 0;
}