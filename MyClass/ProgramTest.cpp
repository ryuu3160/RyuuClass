//ProgramTest.cpp
#include "RyuuClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int main(void)
{
	//----- SORT -----
	SORT Sort;
	int test[10] = { 0 };
	int i;

	for (i = 0; i < 10; i++)
	{
		test[i] = i;
	}

	//‰Šú’l•\Ž¦
	for (i = 0; i < 10; i++)
	{
		printf("%d,", test[i]);
	}
	printf("\n");

	Sort.IntegerSort(test,sizeof(test),SORT::SORT_MODE::DESCENDING);

	for (i = 0; i < 10; i++)
	{
		printf("%d,", test[i]);
	}
	
	rewind(stdin);
	getchar();
}