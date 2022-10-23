#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int typeE;
typedef struct _heap
{
	typeE* _arr;
	int _size;
	int _capa;
}myHeap;

void HeapInit(myHeap* php);
void HeapInit(myHeap* php, int TopK);
void HeapDestroy(myHeap* php);
void HeapPush(myHeap* php, typeE x);
void HeapPop(myHeap* php);
typeE HeapTop(myHeap* php);
bool HeapEmpty(myHeap* php);
int HeapSize(myHeap* php);

bool cmp(typeE a, typeE b);
void AdjustUp(myHeap* php, int child);
void AdjustDw(myHeap* php, int child);
void mySwap(typeE* a, typeE* b);



void HeapSort(int arr[], int n);

