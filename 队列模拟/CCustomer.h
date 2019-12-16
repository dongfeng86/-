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
	//ƽ��ÿ������ʱ�����ӣ����ܵ�������1~3����֮�䡣����ط����е��Ϳ
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
