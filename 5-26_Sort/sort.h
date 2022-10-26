#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

void PrintArr(int* arr, int n);

// ��������
void InsertSort(int* arr, int n);
// ������
void ShellSort(int* arr, int n);

// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);


// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);
