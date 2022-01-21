#include "examples_progress_bar.h"

#include "../Guten/bars/BlockBar.h"

#include <thread>
#include <chrono>

using namespace std;

namespace examples
{
	namespace bars
	{
		void progressBar()
		{
//////////			guten::bars::ProgressBar pb;
//////////			pb.setBarWidth(20);
//////////
//////////			for (float f = 0.0f; f < 100.0f; f += 1.0f) {
//////////				guten::core::eraseLine(cout);
//////////
//////////				pb.setPercent(f);
//////////				cout << pb;
//////////
//////////				this_thread::sleep_for(chrono::milliseconds(25));
//////////			}
//////////
//////////			cout << endl;
		}
		
		void blockBar()
		{
//////////			guten::bars::BlockBar bb;
//////////			bb.setBarWidth(40);
//////////
//////////			for (float f = 0.0f; f < 100.0f; f += 1.0f) {
//////////				bb.setPercent(f);
//////////			
//////////				guten::core::eraseLine(cout);
//////////				bb.print();
//////////				
//////////				this_thread::sleep_for(chrono::milliseconds(25));
//////////			}
//////////
//////////			cout << endl;
		}
	} // namespace checker_board
} // namespace examples