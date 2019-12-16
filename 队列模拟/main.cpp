#include "CQueue.h"
#include <iostream>
#include"CCustomer.h"

bool IsAddQueue(double x);

int main()
{
	const int iTotalTime = 600;
	const int iInterval = 5;              //ƽ�����Ϊ6����
	using namespace std;
	//CQueue<int> queue(10);
	//queue.Append(5);
	//queue.Append(10);
	//queue.Append(20);
	//queue.Append(101);
	//queue.Append(86);
	//cout << queue.IsFull() << endl;
	//cout << "ԭʼ����Ϊ��" << endl;
	//cout << queue << endl;
	//cout << "�������һ�����ݺ�" << endl;
	//int iRet;
	//queue.Pop(iRet);
	//cout << "����������Ϊ��" << iRet << endl;
	//cout << "������ʣ�µ�����Ϊ��" << queue << endl;
	//queue.Pop(iRet);
	//cout << "�ٴε���һ�����ݣ�" << iRet << endl;
	//cout << "������ʣ�µ�����Ϊ: " << queue << endl;

	CQueue<CCustomer> queue(20);                 //�������һ���ܹ���20��
	CCustomer cCustomer;

	int iTotalNum=0;
	double iTotalWaitTime=0;
	//��ʼѭ�����������鵽�����˶೤ʱ��
	int iProcess = 0;
	for (int i = 0; i < iTotalTime; i++)
	{
		if (IsAddQueue(iInterval) && !queue.IsFull())
		{
			cCustomer.SetArrival(i);
			queue.Append(cCustomer);
		}

		//��һ�û��Ƿ����
		if (0 == iProcess)
		{
			if (!queue.IsEmpty())
			{
				queue.Pop(cCustomer);
				iProcess = cCustomer.getProTime();
				iTotalWaitTime += (i - cCustomer.GetArrivalTime() + cCustomer.getProTime());
				iTotalNum++;
			}
		}
		else
		{
			iProcess--;
		}

	}

	cout << "������  " << iTotalTime << "���ӵ�ģ������" << endl;
	cout << "ģ���ܳ�\t" << "����������\t" << "ƽ���ȴ�ʱ��" << endl;
	cout <<  iTotalWaitTime << "\t\t" << iTotalNum << "\t\t\t" << (iTotalWaitTime / iTotalNum) << endl;

	return 0;
}

bool IsAddQueue(double x)
{
	return (rand()*x / RAND_MAX < 1);
}