#ifndef SEQUENTLIST_H_
#define SEQUENTLIST_H_

#include<exception>
#include<iostream>


//该类实现了顺序结构的线性表
template<class T,int n>
class CSeqentList
{
private:
	T* m_ar;
	int m_iCount;
public:
	CSeqentList();
	CSeqentList(const CSeqentList & temp);
	CSeqentList & operator=(const CSeqentList & temp);
	~CSeqentList();

	const T & operator[](int i) const;
	T & operator[](int i);
	int FindAt(T & element);
	bool InsertAt(T data, int iIndex);
	bool EraseAt(int i);
	int GetCount() const;
	template<class T,int n>
	friend std::ostream & operator<<(std::ostream & os, const CSeqentList & temp);
};

template<class T, int n>
inline CSeqentList<T, n>::CSeqentList()
{
	m_ar = new T[n];
	m_iCount = n;
	for (int i = 0; i < n; i++)
		m_ar[i] = 0;
}

template<class T, int n>
inline CSeqentList<T, n>::CSeqentList(const CSeqentList & temp)
{
	m_ar = new T[n];
	for (int i = 0; i < n; i++)
		m_ar[i] = temp[i];
}

template<class T, int n>
inline CSeqentList<T, n> & CSeqentList<T, n>::operator=(const CSeqentList<T, n> & temp)
{
	for (int i = 0; i < n; i++)
		m_ar[i] = temp[i];
}

template<class T, int n>
inline CSeqentList<T, n>::~CSeqentList()
{
	if (m_ar != nullptr)
		delete[] m_ar;
}

template<class T, int n>
inline const T & CSeqentList<T, n>::operator[](int i) const
{
	if (i < 0 || i >= m_iCount)
		throw std::exception("数组范围出错.");
	return m_ar[i];
}

template<class T, int n>
inline T & CSeqentList<T, n>::operator[](int i)
{
	if (i < 0 || i >= m_iCount)
		throw std::exception("数组范围出错.");
	return m_ar[i];
}

template<class T, int n>
inline int CSeqentList<T, n>::FindAt(T & element)
{
	for (int i = 0; i < m_iCount; i++)
	{
		if (element == m_ar[i])
			return i;
	}
	return -1;
}

template<class T, int n>
inline bool CSeqentList<T, n>::InsertAt(T data, int iIndex)
{
	if (iIndex < 0 || iIndex >= m_iCount)
		return false;

	m_iCount += 1;
	T * pTemp = new T[m_iCount];
	for (int i = 0; i < iIndex; i++)
	{
		pTemp[i] = m_ar[i];
	}
	pTemp[iIndex] = data;
	for (int i = iIndex + 1; i < m_iCount; i++)
		pTemp[i] = m_ar[i - 1];

	delete m_ar;
	m_ar = pTemp;

	return true;
}

template<class T, int n>
inline bool CSeqentList<T, n>::EraseAt(int iIndex)
{
	if (iIndex < 0 || iIndex >= m_iCount)
		return false;
	T * pTemp = new T[m_iCount - 1];
	for (int i = 0; i < iIndex; i++)
	{
		pTemp[i] = m_ar[i];
	}
	for (int i = iIndex; i < m_iCount - 1; i++)
	{
		pTemp[i] = m_ar[i + 1];
	}

	m_iCount--;
	delete m_ar;
	m_ar = pTemp;

	return true;
}

template<class T, int n>
inline int CSeqentList<T, n>::GetCount() const
{
	return m_iCount;
}

template<class T,int n>
std::ostream & operator<<(std::ostream & os, const CSeqentList<T,n> & temp)
{
	for (int i = 0; i < temp.GetCount(); i++)
		os << temp[i] << " ";
	return os;
}

#endif // !SEQUENTLIST_H_

