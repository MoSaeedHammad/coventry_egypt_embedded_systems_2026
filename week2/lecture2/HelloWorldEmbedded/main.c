#include <stdio.h>
#include <Windows.h>

int main()
{
	while (1)
	{
		printf("\b1");
		fflush(stdout);
		Sleep(1000);
		printf("\b0");
		fflush(stdout);
		Sleep(1000);
	}
	
	
	return 0;
}
