#include <stdlib.h>
#include <time.h>
#ifndef _CCUSTOMER_
#define _CCUSTOMER_

class CCustomer
{
private:
	long m_lArrivalTime;
	long m_lLeaveTime;
	int m_iProcessTime;
public:
	CCustomer();
	void SetArrival(long lArrival);
	void SetProTime();
	int getProTime();
	long GetArrivalTime();
};

inline CCustomer::CCustomer()
{
	m_lArrivalTime = m_lLeaveTime =0;
	SetProTime();
}

inline void CCustomer::SetArrival(long lArrival)
{
	m_lArrivalTime = lArrival;
}

inline void CCustomer::SetProTime()
{
	//平均每个人用时三分钟，可能的区间在1~3分钟之间。这个地方还有点糊涂
	srand((int)time(NULL));
	m_iProcessTime = rand() % 6+1;
}

inline int CCustomer::getProTime()
{
	return m_iProcessTime;
}

inline long CCustomer::GetArrivalTime()
{
	return m_lArrivalTime;
}
#endif
