#include <string.h>
#include <iostream>
/*
为了提高 串模式匹配的效率，降低其时间复杂度，采用KMP算法来实现。
*/

int* BuildNext(const char arS[]);


int Search(const char arT[], const char arS[])
{
	int * pNext = BuildNext(arS);
	//计算字符串的长度
	long lLenT = (long )strlen(arT);           //原来写成了 for (n = 0; arT[n] != '\0'; n++)	continue; 竟然忘了strlen，实在是太可笑了
	long lLenS = (long)strlen(arS);           //原来写成了	for (n = 0; arS[n] != '\0'; n++)  continue; 哎，忘了strlen

	long i , j ;
	for (i = 0,j=0; j < lLenS && i < lLenT;)
	{
		if (j<0 || arT[i] == arS[j])
		{
			i++;
			j++;
		}
		else
		{
			//更新j的值
			j = pNext[j];
		}
	}

	delete[] pNext;

	if (lLenT - (i-j) < lLenS)
		return -1;
	else
		return i-j;
}

int* BuildNext(const char arS[])
{
	int n = strlen(arS);
	int * Next = new int[n];
	Next[0] = -1;
	Next[1] = 0;
	for (int i = 0, j = 1; j < n-1;)
	{
		if (i == -1 || arS[i] == arS[j])
		{
			i++;
			j++;
			Next[j] = i;
		}
		else
			i = Next[i];
	}

	return Next;
}


int main()
{

	const char * s = "abcdefgabce";
	const char * p = "ced";

	int n = Search(s, p);
	std::cout << "在第" << n << "个位置找到了。";
	return 0;

}