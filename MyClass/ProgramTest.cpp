//ProgramTest.cpp
#include "RyuuClass.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
#include <conio.h>
#include <iterator>

void SortTest(void);
void RandomTest(void);
void PosTest(void);

int main(void)
{
	//----- SORT -----
	//SortTest();
	//std::cout << std::endl << std::endl;
	//----- RANDOM -----
	RandomTest();
	std::cout << std::endl;
	//----- POS -----
	//PosTest();
	//std::cout << std::endl;

	rewind(stdin);
	static_cast<void>(getchar());
}

void SortTest(void)
{
	//----- SORT -----
	Sort Sort(10, 50);
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
		strcpy_s(szTest[i], szCmp);
	}
	for (i = 5; i < 10; i++)
	{
		szCmp[0] = 'a' + i;
		szCmp[1] = '\0';
		szCmp[49] = '\0';
		strcpy_s(szTest[i], szCmp);
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

	//Sort.IntegerSort(test,sizeof(test),Sort::SORT_MODE::DESCENDING);

	//Sort.SetStrArrayData(sizeof(szTest), sizeof(szTest[0]));
	Sort.StringSort(szTest[0], Sort::SORT_MODE::DESCENDING);

	//ソート後表示
	/*for (i = 0; i < 10; i++)
	{
		printf("%d,", test[i]);
	}*/
	for (i = 0; i < 10; i++)
	{
		printf("%s", szTest[i]);
	}
}

void RandomTest(void)
{
	Random Rand;
	Rand.enableMT();

	std::list<std::string> str;
	str.push_back("ryuu");
	str.push_back("三島");
	str.push_back("Tsukishiro");
	str.push_back("弟君");
	str.push_back("ギル");

	str = Rand.Sample(str, 5);

	for (auto itr = str.begin(); itr != str.end(); itr++)
	{
		printf("%s\n", itr->c_str());
	}
}

void PosTest(void)
{
	Pos<int> pos;
	Pos<int> pos2;
	Pos<int> pos3;
	int x = 0, y = 0,z = 0;

	pos.SetPos(10, 20,30);
	pos2.SetPos(50, 50, 50);
	pos3.SetPos(60, 70, 80);

	pos += pos2;

	pos.GetPos(z, "z");
	pos.GetPos(x, y, "xy");

	printf("x:%d\ny:%d\nz:%d\n", x, y,z);
	printf("n:%d\n", pos == pos3);
}