// https://stackoverflow.com/questions/1799063/how-can-i-display-unicode-characters-in-a-linux-terminal-using-c
// Unicode symbols https://www.unicode.org/charts/
// For unicode support https://stackoverflow.com/questions/745536/small-open-source-unicode-library-for-c-c

// Alternative Terminal Libraries
// FTXUI:			https://github.com/ArthurSonzogni/FTXUI
// Turbo Vision: 	https://github.com/magiblot/tvision

#include "examples.h"
#include "examples_checker_board.h"
#include "examples_draw_functions.h"
#include "examples_progress_bar.h"
#include "../Guten/color/Color.h"

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

	termcolor::Color color = guten::color::green;
	cout << color << " This color is green " << endl;

	termcolor::ColorFG c(240,35, 64);
	termcolor::ColorBG bg(0, 255, 255);
	cout << termcolor::blink << c << bg << "--- This is where its at ---" << termcolor::reset << endl;

	//examples::checker_board::test();
	//examples::checker_board::printMini();
	//examples::Character::test();
	//examples::bars::progressBar();
	//examples::bars::blockBar();
	examples::boards::checkerBoard();
	//examples::color::showAll();
	//examples::core::matrix();
	//examples::spinners::flatSpinner();
	//examples::spinners::lineSpinner();
	//examples::rectangle();
	//examples::draw::lines();

	std::cout << termcolor::red << "Hello, ";                   // 16 colors
	std::cout << termcolor::color<100> << termcolor::blue << "Colorful ";          // 256 colors
	std::cout << termcolor::color<11, 54, 130> << termcolor::yellow << "World!";    // true colors
	std::cout << std::endl;

	string str = "\u265E";
	cout << str << endl;

	setlocale(LC_ALL, "en_US.UTF-8");
	//uint16_t codepoint = 0x265E;
	//wcout << codepoint << endl;
	
	//wcout << "\xe2\x99\x94" << endl;
	str = "\u265A";
	cout << str << endl;
	//this_thread::sleep_for(chrono::seconds(1));
	//cin.get();
	return 0;
}