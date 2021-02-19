#include <iostream>

#include <Guten/guten.hpp>

using namespace std;

int main()
{
	// Change terminal's forground color, then print some text
	//cout << guten::color::red << "=============" << endl	// print in red
	//	<< guten::color::green << "=== Guten ===" << endl	// print in green
	//	<< guten::color::blue << "=============" << endl	// print in blue
	//	<< endl;
	//
	//cout << guten::color::red << 'C'			// Set foreground color to red
	//	<< guten::color::lightred << 'o'		// Set foreground color to lightred
	//	<< guten::color::yellow << 'l'			// Set foreground color to yellow
	//	<< guten::color::brown << 'o'			// Set foreground color to brown
	//	<< guten::color::green << 'r'			// Set foreground color to green
	//	<< ' '
	//	<< guten::color::lightgreen << 'M'		// Set foreground color to lightgreen
	//	<< guten::color::cyan << 'e'			// Set foreground color to cyan
	//	<< ' '
	//	<< guten::color::lightcyan << 'w'		// Set foreground color to lightcyan
	//	<< guten::color::blue << 'i'			// Set foreground color to blue
	//	<< guten::color::lightblue << 't'		// Set foreground color to lightblue
	//	<< guten::color::magenta << 'h'			// Set foreground color to magenta
	//	<< ' ';
	//
	//// Create a Color object. When streamed, it will change the terminals color.
	//guten::color::Color c;
	//c.setfg(guten::color::white);				// Set objects foreground color to white
	//
	//c.setbg(guten::color::red);					// Set objects background color to red
	//cout << c << 'G';							// Stream color and 'G'
	//											 
	//c.setbg(guten::color::yellow);				// Set objects background color to yellow
	//cout << c << 'u';							// Stream color and 'u'
	//											 
	//c.setbg(guten::color::green);				// Set objects background color to green
	//cout << c << 't';							// You get the idea
	//											 
	//c.setbg(guten::color::cyan);				// Set objects background color to cyan
	//cout << c << 'e';							
	//											 
	//c.setbg(guten::color::blue);				// Set objects background color to blue
	//cout << c << 'n';							 
	//
	//cout << guten::color::white << "!!!" << endl; // Set terminal color back to white on black
	
	//guten::color::printAllColors();

	//guten::color::Color c = guten::color::red;
	//
	////guten::color::printAllColors();
	//
	//cout << guten::color::setfg(guten::color::green) << "tHIS IS green" << endl;
	//cout << c << "This is red" << endl;
	//
	//guten::core::ColoredChar<uint8_t> cc{ guten::color::blue, 'x' };
	//cout << cc << '\n';
	//
	//guten::boards::CheckerBoard board;
	//board.drawBackground();
	//// --- Dark Pieces ---
	//board.placePiece('R', guten::Point{ 0, 0 }, false);
	//board.placePiece('N', guten::Point{ 0, 1 }, false);
	//board.placePiece('B', guten::Point{ 0, 2 }, false);
	//board.placePiece('K', guten::Point{ 0, 3 }, false);
	//board.placePiece('Q', guten::Point{ 0, 4 }, false);
	//board.placePiece('B', guten::Point{ 0, 5 }, false);
	//board.placePiece('N', guten::Point{ 0, 6 }, false);
	//board.placePiece('R', guten::Point{ 0, 7 }, false);
	//board.placePiece('p', guten::Point{ 1, 0 }, false);
	//board.placePiece('p', guten::Point{ 1, 1 }, false);
	//board.placePiece('p', guten::Point{ 1, 2 }, false);
	//board.placePiece('p', guten::Point{ 1, 3 }, false);
	//board.placePiece('p', guten::Point{ 1, 4 }, false);
	//board.placePiece('p', guten::Point{ 1, 5 }, false);
	//board.placePiece('p', guten::Point{ 1, 6 }, false);
	//board.placePiece('p', guten::Point{ 1, 7 }, false);
	//
	//// --- Light Pieces ---
	//board.placePiece('R', guten::Point{ 7, 0 }, true);
	//board.placePiece('N', guten::Point{ 7, 1 }, true);
	//board.placePiece('B', guten::Point{ 7, 2 }, true);
	//board.placePiece('K', guten::Point{ 7, 3 }, true);
	//board.placePiece('Q', guten::Point{ 7, 4 }, true);
	//board.placePiece('B', guten::Point{ 7, 5 }, true);
	//board.placePiece('N', guten::Point{ 7, 6 }, true);
	//board.placePiece('R', guten::Point{ 7, 7 }, true);
	//board.placePiece('p', guten::Point{ 6, 0 }, true);
	//board.placePiece('p', guten::Point{ 6, 1 }, true);
	//board.placePiece('p', guten::Point{ 6, 2 }, true);
	//board.placePiece('p', guten::Point{ 6, 3 }, true);
	//board.placePiece('p', guten::Point{ 6, 4 }, true);
	//board.placePiece('p', guten::Point{ 6, 5 }, true);
	//board.placePiece('p', guten::Point{ 6, 6 }, true);
	//board.placePiece('p', guten::Point{ 6, 7 }, true);
	//board.print(5);
	//
	//this_thread::sleep_for(chrono::seconds(5));
	cin.get();
	return 0;
}