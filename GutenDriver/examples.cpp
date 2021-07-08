#include "examples.h"

using namespace std;

namespace examples
{
	namespace Character
	{
		void test()
		{
			using guten::core::Character;

			cout << Character() << '\n'
				<< Character(uint8_t('a')) << '\n'
				<< Character(guten::lines::up + guten::lines::left) << '\n'
				<< Character(guten::blocks::top) << '\n';
			
			Character c{ guten::lines::double_cross };
			Character d{ c };

			c = guten::lines::vertical;

			cout << c << " should not equal " << d << '\n';

			Character e(std::move(d));
			cout << e << '\n';

			d = e;

			cout << d << '\n';

			e = guten::blocks::left;
			c = std::move(e);

			cout << c << '\n';

			d = guten::lines::horizontal;
			cout << d + guten::lines::vertical << '\n';

			cout << d + guten::blocks::bottom << '\n';

			d = 'a';
			cout << d + uint8_t(1) << '\n';


		}
	}

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

	namespace boards
	{
		void checkerBoard()
		{
			guten::boards::CheckerBoard cb;
			cb.placePiece('K', 3, 4, true);
			cb.placePiece('Q', 3, 5, false);

			cb.print();

			guten::boards::CheckerBoard cb2;

			cb2 = cb;

			cb2.print();
		}
	} // namespace boards

	namespace color
	{
		void showAll()
		{
			guten::color::printAllColors();
		}
	} // namespace color

	namespace core
	{
		void matrix()
		{
			guten::core::Matrix img;

			img.resize(10, 20);

			guten::draw::rectangle(img, guten::Point{ 2, 2 }, guten::Size{ 5, 9 }, guten::color::blue, true);
			guten::draw::rectangle(img, guten::Point{ 4, 4 }, guten::Size{ 5, 9 }, guten::color::yellow, true);
			guten::draw::rectangle(img, guten::Point{ 0, 0 }, img.size(), guten::color::green);

			img.print();

			guten::core::Matrix img2;
			
			img2.resize(5, 32);

			img2 = img;

			img2.print(10);
		}
	} // namespace core

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
