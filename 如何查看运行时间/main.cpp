#include<iostream>
#include <vector>
#include <windows.h>

int main()
{
	using std::endl;
	using std::cout;
	using std::cin;

	std::vector<int> ar;
	DWORD start_time = GetTickCount();
	for (int i = 0; i < 1000000; i++)
	{
		ar.push_back(i);
	}
	DWORD end_time = GetTickCount();
	cout << "压入1000000条数据用的时间为：" << (end_time - start_time) *1.0 / 1000 << "s!" << endl;

	double iCount = 10000;
	for (iCount = 10000; iCount < 1000000; iCount += 50000)
	{
		start_time = GetTickCount();
		int i;
		for (i = 0; i < ar.size(); i++)
		{
			if (iCount == ar[i])
			{
				break;
			}
		}
		end_time = GetTickCount();
		cout << "\n现在找到了，数组包含有200000个数字，在第" << i << "项；" 
			<<"找到数字" <<i<<"用时为："<< (end_time - start_time)*1.0 / 1000 << "s!" << endl;
	}
	return 0;
}