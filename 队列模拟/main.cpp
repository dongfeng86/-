#include "CQueue.h"
#include <iostream>
#include"CCustomer.h"
const int MIN_PER_HR = 60;

bool IsAddQueue(double x);

int main()
{
	const int iTotalTime = 600;
	const int iInterval = 6;              //ƽ�����Ϊ6����
	using namespace std;

	/*The srand function sets the starting point for generating a series of pseudorandom integers in the current thread.
	srand ���������ڵ�ǰ�߳�������һϵ��α�����������㡣����һ��ע���ǵ�ǰ�̡߳�
	���ܳ����г��ֶ��ٸ�rand()������ֻҪ�趨һ�����ӾͿ�����*/
	srand((int)time(NULL));               

	cout << "Case Study:Bank of Heather Automatic Teller\n";
	cout << "Enter maimum size of queue:";
	int qs;
	cin >> qs;
	
	CQueue<CCustomer> queue(qs);                 //�������һ���ܹ���qs��

	cout << "Enter the number of simulation hours:";
	int hours;
	cin >> hours;
	long lCycleLimit = MIN_PER_HR*hours;

	cout << "Enter the arverage number of customers per hour:";
	double dPerHour;
	cin >> dPerHour;
	double min_per_cust = MIN_PER_HR / dPerHour;

	CCustomer cCustomer;
	long lTurnaways = 0;
	long lCustomers = 0;
	long lServed = 0;
	long lSumLine = 0;
	int iWaitTime = 0;
	long lLineWait = 0;

	for (int cycle = 0; cycle < lCycleLimit; cycle++)
	{
		if (IsAddQueue(min_per_cust))
		{
			if (queue.IsFull())
			{
				lTurnaways++;
			}
			else
			{
				cCustomer.SetArrival(cycle);
				queue.Append(cCustomer);
				lCustomers++;
			}

		}

		//��һ�û��Ƿ����
		if (0 == iWaitTime && !queue.IsEmpty())
		{
			queue.Pop(cCustomer);
			iWaitTime = cCustomer.getProTime();
			lLineWait += cycle - cCustomer.GetArrivalTime()/* + cCustomer.getProTime()*/;
			lServed++;
		}
		
		if (iWaitTime > 0)
		{
			iWaitTime--;
		}

		lSumLine += queue.GetLength();
	}

	if (lCustomers > 0)
	{
		cout << "customers accepted:" << lCustomers << endl;
		cout << "  customers served:" << lServed << endl;
		cout << "         turnaways:" << lTurnaways << endl;
		cout << "average queue size:";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)lSumLine / lCycleLimit << endl;
		cout << "average wait time:" << (double)lLineWait / lServed << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	return 0;
}

bool IsAddQueue(double x)
{
	return (rand()*x / RAND_MAX < 1);
}