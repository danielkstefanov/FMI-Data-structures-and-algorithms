//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void insertNumberInVector(std::vector<unsigned>& v, unsigned current)
//{
//	if (v.size() == 0)
//	{
//		v.push_back(current);
//		return;
//	}
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (current <= v[i])
//		{
//			v.insert(v.begin() + i, current);
//			return;
//		}
//	}
//
//	v.push_back(current);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<unsigned> v;
//
//	for (size_t i = 0; i < n; i++)
//	{
//		unsigned current;
//		cin >> current;
//
//		insertNumberInVector(v, current);
//
//		if (v.size() % 2 == 1)
//		{
//			cout << v[v.size() / 2] << endl;
//		}
//		else
//		{
//			cout << (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2.0 << endl;
//		}
//	}
//
//	return 0;
//}
