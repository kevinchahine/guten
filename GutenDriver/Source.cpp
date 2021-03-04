#include <iostream>
#include <thread>
#include <chrono>

#include <Guten/guten.hpp>

using namespace std;

int main()
{
	guten::core::Matrix mat(9, 21);

	guten::draw::rectangle(mat, guten::Point{ 0, 0 }, mat.size(), guten::color::lightred, true);
	guten::draw::rectangle(mat, guten::Point{ 1, 1 }, mat.size() - 2, guten::color::lightmagenta, true);
	guten::draw::rectangle(mat, guten::Point{ 2, 2 }, mat.size() - 4, guten::color::lightgreen, true);
	guten::draw::rectangle(mat, guten::Point{ 3, 3 }, mat.size() - 6, guten::color::cyan, true);
	guten::draw::putText(mat, "Guten", guten::Point{ 4, 8 }, guten::color::green);

	mat.print();
	
	this_thread::sleep_for(chrono::seconds(1));
	//cin.get();
	return 0;
}