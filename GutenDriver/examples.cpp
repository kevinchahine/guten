#include "examples.h"

using namespace std;

namespace examples
{
	namespace bars
	{
		void progressBar()
		{
			guten::bars::ProgressBar pb;

			for (float f = 0.0f; f < 100.0f; f += 5.0f) {
				pb.setPercent(f);
				cout << pb;

				this_thread::sleep_for(chrono::milliseconds(200));
				guten::eraseLine(cout);
			}
		}
	} // namespace bars

	namespace spinners
	{
		void flatSpinner()
		{
			guten::spinners::FlatSpinner s;

			int i = 0;
			while (i++ < 8) {
				cout << s;
				this_thread::sleep_for(chrono::milliseconds(500));
				cout << '\b';
			}
		}

		void lineSpinner()
		{
			guten::spinners::LineSpinner s;

			for (int i = 0; i < 8; i++) {
				cout << s;
				this_thread::sleep_for(chrono::milliseconds(500));
				cout << '\b';
			}
		}
	} // namespace spinners

	void rectangle()
	{
		guten::core::Matrix mat(9, 21);

		guten::draw::rectangle(mat, guten::Point{ 0, 0 }, mat.size(), guten::color::lightred, true);
		guten::draw::rectangle(mat, guten::Point{ 1, 1 }, mat.size() - 2, guten::color::lightmagenta, true);
		guten::draw::rectangle(mat, guten::Point{ 2, 2 }, mat.size() - 4, guten::color::lightgreen, true);
		guten::draw::rectangle(mat, guten::Point{ 3, 3 }, mat.size() - 6, guten::color::cyan, true);
		guten::draw::putText(mat, "Guten", guten::Point{ 4, 8 }, guten::color::green);

		mat.print();
	}
}