#ifndef _CQUEUE_
#define _CQUEUE_
#include <iostream>

template<class T> class CQueue;                     //ǰ������

template<class T>
std::ostream & operator<<(std::ostream & os, CQueue<T> & queue);

template<class T>
class CQueue
{
private:
	enum { iMax=10	};
	struct SNode
	{
		T element;
		SNode* pNext;
	};
	SNode * pFront;                     //��¼������Ԫ��
	SNode * pRear;                      //��¼����βԪ��
	int iLength;                        //��¼���г���
	int iMaxLength;               //��¼����������󳤶�

	CQueue(const CQueue & t);
	CQueue & operator=(const CQueue & t);
public:
	//CQueue();                         //�������ն���
	CQueue(int iSize = iMax);             //������һ����iSize���ȵĶ���
	~CQueue();
	bool Pop(T & t);                    //����������Ԫ��
	bool Append(const T & t);           //�ڶ�β����һ��Ԫ��
	int GetLength();                    //��ȡ���г���
	bool IsEmpty();                     //�ж������Ƿ�Ϊ��
	bool IsFull();                      //�ж������Ƿ���
	friend std::ostream & operator<< <T>(std::ostream & os, CQueue<T> & queue);
};

template<class T>
CQueue<T>::CQueue(int iSize /*= 10*/)
	:iMaxLength(iSize)
{
	pFront = pRear = nullptr;
}

template<class T>
inline CQueue<T>::~CQueue()
{
	while (pFront != nullptr)
	{
		SNode * pTemp = pFront;
		pFront = pFront->pNext;
		delete pTemp;
	}
}

template<class T>
bool CQueue<T>::Pop(T & t)
{
	if (IsEmpty())
		return false;
	SNode * pTemp = pFront;
	pFront = pFront->pNext;
	t = pTemp->element;
	delete pTemp;                    //������Ϸ����ڴ�
	iLength--;

	if (iLength == 0)
		pRear = NULL;
	return true;
}

template<class T>
bool CQueue<T>::Append(const T & t)
{
	if (IsFull())
		return false;
	SNode * pNode = new SNode;
	pNode->element = t;
	pNode->pNext = nullptr;

	if (iLength == 0)
	{
		pFront = pRear = pNode;
	}
	else
	{
		pRear->pNext = pNode;
		pRear = pNode;
	}

	iLength++;
	return true;
}

template<class T>
int CQueue<T>::GetLength()
{
	return iLength;
}

template<class T>
bool CQueue<T>::IsEmpty()
{
	return (iLength <= 0) ? true : false;
}

template<class T>
bool CQueue<T>::IsFull()
{
	return (iLength >= iMaxLength) ? true : false;
}

template<class T>
std::ostream & operator<<(std::ostream & os, CQueue<T> & queue)
{
	CQueue<T>::SNode *pRead;
	pRead = queue.pFront;
	while (pRead != nullptr)
	{
		std::cout << pRead->element << " ";
		pRead = pRead->pNext;
	}
	return os;
}

#endif