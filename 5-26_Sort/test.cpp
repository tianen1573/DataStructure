#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

void InsertSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	PrintArr(arr, sizeof(arr) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 9, 1,9,3,8, 2, 5, 7, 4, 8, 6, 3, 5, 4,2,3,6,8,2,1,2,2};
	//int a[] = { 9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestBulleSort()
{
	//int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	//int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5, 1, 24, 35, 5, 8 };
	int* a = (int*)malloc(sizeof(int) * 100000);
	for (int i = 0; i < 100000; ++i)
	{
		a[i] = 100000 - i;
	}
	//QuickSort(a, 0, 10000 - 1);
	//QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	QuickSortNonR(a, 0,100000 - 1);

	PrintArr(a, 100000);
}

void TestMergeSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5, 1, 24, 35, 5, 8 };

	//MergeSort(a, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestCountSort()
{
	int a[] = { 10,15,19,10,15,14,18,10,-5,-5,-8,-8 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

int main()
{
	//InsertSortTest();
	//TestShellSort();
	//TestSelectSort();

	//TestHeapSort();


	//TestBulleSort();

	//TestQuickSort();

	//TestMergeSort();

	TestCountSort();


	return 0;
}