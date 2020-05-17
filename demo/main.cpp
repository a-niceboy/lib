#include <iostream>
#include "progress_bar.h"

using namespace std;

int main()
{
	int i = 1;

	cout << "demo ..." << endl;
	ProgressBar pb(77, 1);
	while (i < 77)
	{
		pb.run(i);
		i++;
#ifdef _WIN32
		Sleep(100);
#else
		usleep(200000);
#endif
	}

	return 0;
}
