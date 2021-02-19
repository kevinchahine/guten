#include <iostream>

#include <Guten/guten.hpp>

using namespace std;

int main()
{
	cout << guten::color::red << "=============" << endl
		<< guten::color::green << "=== Guten ===" << endl
		<< guten::color::blue << "=============" << endl
		<< endl;

	cout << guten::color::red << 'C'
		<< guten::color::lightred << 'o'
		<< guten::color::yellow << 'l'
		<< guten::color::brown << 'o'
		<< guten::color::green << 'r'
		<< ' '
		<< guten::color::lightgreen << 'M'
		<< guten::color::cyan << 'e'
		<< ' '
		<< guten::color::lightcyan << 'w'
		<< guten::color::blue << 'i'
		<< guten::color::lightblue << 't'
		<< guten::color::magenta << 'h'
		<< ' ';

	guten::color::Color c;
	c.setfg(guten::color::white);

	c.setbg(guten::color::red);
	cout << c << 'G';

	c.setbg(guten::color::yellow);
	cout << c << 'u';

	c.setbg(guten::color::green);
	cout << c << 't';

	c.setbg(guten::color::cyan);
	cout << c << 'e';

	c.setbg(guten::color::blue);
	cout << c << 'n';

	cout << guten::color::white << "!!!" << endl;

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