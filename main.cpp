#define OAA_TIMER_IMPL
#include "oaa_Timer.h"
#include <iostream>
#include <unistd.h>
int main (int argc, char *argv[])
{
	OAA::Timer t;

	std::cout << t.GetTime() << std::endl;
	sleep(5);

	std::cout << t.GetTime() << std::endl;

	return 0;
}
