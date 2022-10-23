#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"


//int main()
//{
//	myHeap hp;
//	HeapInit(&hp);
//	int a[] = { 27, 15, 19, 11, 28, 34, 65, 49, 25, 37 };
//	
//	for (int i = 0; i < 10; ++ i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//
//		HeapPop(&hp);
//	}
//
//	return 0;
//}


//int main()
//{
//	int TopK = 10;
//
//	int arr[] = { 10, 20, 30, 40, 50, 24, 24, 22, 22, 14, 24, 5, 37, 46 };
//
//	myHeap TopHp;
//	HeapInit(&TopHp, TopK);
//
//	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
//	{
//		if (TopHp._size < TopHp._capa)
//		{
//			HeapPush(&TopHp, arr[i]);
//		}
//		else
//		{
//			if (cmp(arr[i], HeapTop(&TopHp)))
//			{
//				TopHp._arr[0] = arr[i];
//				AdjustDw(&TopHp, 0);
//			}
//		}
//	}
//
//	while (!HeapEmpty(&TopHp))
//	{
//		printf("%d ", HeapTop(&TopHp));
//
//		HeapPop(&TopHp);
//	}
//
//
//	return 0;
//}

int main()
{
	int arr[] = { 1, 3, 5, 2 ,3 ,9 ,5 ,6 ,7 ,8, 3, 45, 23, 2 };
	//int arr[] = { 1, 3, 2, 5, 4 };

	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i)
	{
		HeapSort(arr, n - i);
		mySwap(arr, arr + n - 1 - i);
	}
	

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
