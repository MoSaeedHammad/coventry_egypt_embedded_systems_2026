#include <stdio.h>
#ifdef WINDOWS
#include <Windows.h>
#else
#include<stdlib.h>
#include<unistd.h>
#endif

int main()
{
	while (1)
	{
		printf("\b1");
		fflush(stdout);
		#ifdef WINDOWS
		Sleep(1000);
		#else
		sleep(1);
		#endif
		printf("\b0");
		fflush(stdout);
		#ifdef WINDOWS
		Sleep(1000);
		#else
		sleep(1);
		#endif
	}
	
	return 0;
}
