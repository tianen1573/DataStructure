#define _CRT_SECURE_NO_WARNINGS 1

/*A*/
//int T, M, N;
//
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//
//unsigned int FactorMax(unsigned int p, unsigned int q)
//{
//	if (q % p == 0)
//		return p;
//	else
//	{
//		return FactorMax(q % p, p);
//	}
//}
//void Simplification(unsigned int* p, unsigned int* q)
//{
//	if (*p == 0)
//	{
//		*q = 1;
//		return;
//	}
//	unsigned MaxF = FactorMax(*p, *q);
//	*p /= MaxF;
//	*q /= MaxF;
//}
//int main()
//{
//	cin >> T;
//	while (T--)
//	{
//		cin >> N >> M;
//		if ((N * M) % 2 == 0)
//		{
//			cout <<"1/2" << endl;
//		}
//		else
//		{
//			unsigned int p = M * (N / 2) + (M / 2);
//			unsigned int q = N * M;
//			Simplification(&p, &q);
//			cout << p << '/' << q << endl;
//		}
//	}
//
//	return 0;
//}

/*B*/
//#include<stdlib.h>
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		string num;
//		cin >> num;
//		int i = 1;
//		char tmp;
//		//�ҵ�һ���¹յ�
//		for (i = 1; i < num.size(); i++)
//		{
//			if (num[i] < num[i - 1])
//				break;
//		}
//		//��֮���һ���Ϲյ㣬������յ�Ԫ��
//		for (i += 1; i < num.size(); i++)
//		{
//			if (num[i] > num[i - 1])
//			{
//				tmp = num[i - 1];
//				break;
//			}
//		}
//		//��֮���Ԫ�ض���ֵΪ�յ�Ԫ�أ�����Ϊֱ��
//		for (; i < num.size(); i++)
//		{
//			num[i] = tmp;
//		}
//		cout << num << endl;
//	}
//
//}

/*C*/
#include<stdlib.h>
#include<iostream>
using namespace std;
