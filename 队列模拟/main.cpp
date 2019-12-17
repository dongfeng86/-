#include "CQueue.h"
#include <iostream>
#include"CCustomer.h"
const int MIN_PER_HR = 60;

bool IsAddQueue(double x);

int main()
{
	const int iTotalTime = 600;
	const int iInterval = 6;              //平均间隔为6分钟
	using namespace std;

	/*The srand function sets the starting point for generating a series of pseudorandom integers in the current thread.
	srand 函数设置在当前线程中生成一系列伪随机整数的起点。这里一定注意是当前线程。
	不管程序中出现多少个rand()函数，只要设定一次种子就可以了*/
	srand((int)time(NULL));               

	cout << "Case Study:Bank of Heather Automatic Teller\n";
	cout << "Enter maimum size of queue:";
	int qs;
	cin >> qs;
	
	CQueue<CCustomer> queue(qs);                 //假设队列一共能够排qs人

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

		//上一用户是否完成
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