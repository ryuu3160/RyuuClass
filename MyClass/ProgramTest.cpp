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
	int i;
	char szTest[10][50];
	char szCmp[50];
	/*int test[10] = { 0 };*/

	/*for (i = 0; i < 10; i++)
	{
		test[i] = i;
	}*/

	for (i = 0; i < 5; i++)
	{
		szCmp[0] = 'o' + i;
		szCmp[1] = '\0';
		szCmp[49] = '\0';
		strcpy(szTest[i], szCmp);
	}
	for (i = 5; i < 10; i++)
	{
		szCmp[0] = 'a' + i;
		szCmp[1] = '\0';
		szCmp[49] = '\0';
		strcpy(szTest[i], szCmp);
	}

	//初期値表示
	/*for (i = 0; i < 10; i++)
	{
		printf("%d,", test[i]);
	}*/
	for (i = 0; i < 10; i++)
	{
		printf("%s", szTest[i]);
	}
	printf("\n");

	//Sort.IntegerSort(test,sizeof(test),SORT::SORT_MODE::DESCENDING);

	Sort.SetStrArrayData(sizeof(szTest), sizeof(szTest[0]));
	Sort.StringSort(szTest[0],SORT::SORT_MODE::DESCENDING);

	//ソート後表示
	/*for (i = 0; i < 10; i++)
	{
		printf("%d,", test[i]);
	}*/
	for (i = 0; i < 10; i++)
	{
		printf("%s", szTest[i]);
	}
	
	rewind(stdin);
	getchar();
}