#include <iostream>
#include <thread>
#include <chrono>

#include <Guten/Color.h>
#include <Guten/iocolor.h>

#include <Guten/ColoredChar.h>

using namespace std;

int main(int argc, char ** argv)
{
	guten::color::Color c = guten::color::red;

	cout << c << "This is red" << endl;

	guten::core::ColoredChar<uint8_t> cc{ guten::color::blue, 'x' };
	cout << cc << '\n';
	
	this_thread::sleep_for(chrono::seconds(1));
	//cin.get();
	return 0;
}