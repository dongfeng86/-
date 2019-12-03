#include "SeqentList.h"
#include <iostream>

int main()
{
	CSeqentList<int,5> cList;
	cList[0] = 7;
	cList[1] = 9;
	cList[2] = 10;
	cList[3] = 2;
	cList[4] = 23;
	std::cout << cList;
	return 0;
}