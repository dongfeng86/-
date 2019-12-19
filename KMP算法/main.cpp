#include <string.h>
#include <iostream>
/*
Ϊ����� ��ģʽƥ���Ч�ʣ�������ʱ�临�Ӷȣ�����KMP�㷨��ʵ�֡�
*/

int* BuildNext(const char arS[]);


int Search(const char arT[], const char arS[])
{
	int * pNext = BuildNext(arS);
	//�����ַ����ĳ���
	long lLenT = (long )strlen(arT);           //ԭ��д���� for (n = 0; arT[n] != '\0'; n++)	continue; ��Ȼ����strlen��ʵ����̫��Ц��
	long lLenS = (long)strlen(arS);           //ԭ��д����	for (n = 0; arS[n] != '\0'; n++)  continue; ��������strlen

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
			//����j��ֵ
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
	std::cout << "�ڵ�" << n << "��λ���ҵ��ˡ�";
	return 0;

}