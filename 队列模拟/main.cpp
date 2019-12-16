#include "CQueue.h"
#include <iostream>
#include"CCustomer.h"

bool IsAddQueue(double x);

int main()
{
	const int iTotalTime = 600;
	const int iInterval = 5;              //平均间隔为6分钟
	using namespace std;
	//CQueue<int> queue(10);
	//queue.Append(5);
	//queue.Append(10);
	//queue.Append(20);
	//queue.Append(101);
	//queue.Append(86);
	//cout << queue.IsFull() << endl;
	//cout << "原始数据为：" << endl;
	//cout << queue << endl;
	//cout << "如果弹出一个数据后：" << endl;
	//int iRet;
	//queue.Pop(iRet);
	//cout << "弹出的数据为：" << iRet << endl;
	//cout << "链表中剩下的数据为：" << queue << endl;
	//queue.Pop(iRet);
	//cout << "再次弹出一个数据：" << iRet << endl;
	//cout << "链表中剩下的数据为: " << queue << endl;

	CQueue<CCustomer> queue(20);                 //假设队列一共能够排20人
	CCustomer cCustomer;

	int iTotalNum=0;
	double iTotalWaitTime=0;
	//开始循环，看看队伍到底用了多长时间
	int iProcess = 0;
	for (int i = 0; i < iTotalTime; i++)
	{
		if (IsAddQueue(iInterval) && !queue.IsFull())
		{
			cCustomer.SetArrival(i);
			queue.Append(cCustomer);
		}

		//上一用户是否完成
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

	cout << "来看看  " << iTotalTime << "分钟的模拟结果：" << endl;
	cout << "模拟总长\t" << "处理总人数\t" << "平均等待时间" << endl;
	cout <<  iTotalWaitTime << "\t\t" << iTotalNum << "\t\t\t" << (iTotalWaitTime / iTotalNum) << endl;

	return 0;
}

bool IsAddQueue(double x)
{
	return (rand()*x / RAND_MAX < 1);
}