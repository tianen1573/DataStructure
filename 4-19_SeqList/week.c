#define _CRT_SECURE_NO_WARNINGS 1


/*A*/
//#include<stdio.h>
//
//int N, K;
//int gra[100001];
//char sta[100001];
//
//int main()
//{
//	scanf("%d %d", &N, &K);
//	for (int i = 1; i <= K; i++)
//		scanf("%d", &gra[i]);
//	for (int i = 0; i < N; i++)
//	{
//		long long sum = 0;
//		scanf("%s", sta);
//		for (int i = 1; i <= K; i++)
//			sum += (sta[i - 1] - '0') * gra[i];
//		printf("%lld\n", sum);
//	}
//
//	return 0;
//}

/*B*/
/*小数据可行*/
#include <stdio.h>
#include <math.h>

int T, val;

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int x = 0, y = 1;//x > 0,y > 0 恒成立 
		int sum = 0;
		scanf("%d", &val);

		while (3 * (int)pow(2, x) <= val)
			x++;

		int maxx = x, maxy = x + 2;
		int min = 999999;

		for (x = 0; x < maxx; x++)
		{
			for (y = maxx; y < maxy; y++)
			{
				if ((unsigned int)pow(2, x) + (unsigned int)pow(2, y) - val >= 0 && (unsigned int)pow(2, x) + (unsigned int)pow(2, y) - val < min)
					min = (unsigned int)pow(2, x) + (unsigned int)pow(2, y) - val;
				if (val - (unsigned int)pow(2, x) - (unsigned int)pow(2, y) >= 0 && val - (unsigned int)pow(2, x) - (unsigned int)pow(2, y) < min)
					min = val - (unsigned int)pow(2, x) - (unsigned int)pow(2, y);
				//printf("%d\t", min);
			}
		}
		if ((unsigned int)pow(2, maxx) + (unsigned int)pow(2, maxx + 1.0) - val < min)
			min = (unsigned int)pow(2, maxx) + (unsigned int)pow(2, maxy - 1.0) - val;
		printf("%d\n", min);
	}

	return 0;
}