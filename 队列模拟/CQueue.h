#ifndef _CQUEUE_
#define _CQUEUE_
#include <iostream>

template<class T> class CQueue;                     //前向声明

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
	SNode * pFront;                     //记录队列首元素
	SNode * pRear;                      //记录队列尾元素
	int iLength;                        //记录队列长度
	int iMaxLength;               //记录队列允许最大长度

	CQueue(const CQueue & t);
	CQueue & operator=(const CQueue & t);
public:
	//CQueue();                         //允许创建空队列
	CQueue(int iSize = iMax);             //允许创建一个有iSize长度的队列
	~CQueue();
	bool Pop(T & t);                    //弹出队列首元素
	bool Append(const T & t);           //在队尾增加一个元素
	int GetLength();                    //获取队列长度
	bool IsEmpty();                     //判定队列是否为空
	bool IsFull();                      //判定队列是否满
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
	delete pTemp;                    //清除堆上分配内存
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