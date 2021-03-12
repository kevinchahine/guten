#include <iostream>
#include <thread>
#include <chrono>

#include <Guten/guten.hpp>

#include <Guten/Matrix2.h>

using namespace std;

int main()
{
	//guten::core::Matrix mat(9, 21);
	//
	//guten::draw::rectangle(mat, guten::Point{ 0, 0 }, mat.size(), guten::color::lightred, true);
	//guten::draw::rectangle(mat, guten::Point{ 1, 1 }, mat.size() - 2, guten::color::lightmagenta, true);
	//guten::draw::rectangle(mat, guten::Point{ 2, 2 }, mat.size() - 4, guten::color::lightgreen, true);
	//guten::draw::rectangle(mat, guten::Point{ 3, 3 }, mat.size() - 6, guten::color::cyan, true);
	//guten::draw::putText(mat, "Guten", guten::Point{ 4, 8 }, guten::color::green);
	//
	//mat.print();

	guten::core::Matrix2 m;
	guten::core::Matrix2 m2(4, 5);
	guten::core::Matrix2 m3(m);
	guten::core::Matrix2 m4 = m3;
	guten::core::Matrix2 m5(move(m4));
	guten::core::Matrix2 m6 = m5;
	guten::core::Matrix2 m7 = move(m6);

	for (int r = 0; r < m2.nRows(); r++) {
		for (int c = 0; c < m2.nCols(); c++) {
			m2.at(r, c) = guten::core::ColoredChar<guten::core::Character>(guten::color::lightblue, '5');
		}
	}

	m2.print();

	this_thread::sleep_for(chrono::seconds(1));
	//cin.get();
	return 0;
}