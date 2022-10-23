#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

bool cmp(typeE a, typeE b)
{
	return a > b;
}
void mySwap(typeE* a, typeE* b)
{
	typeE tmp = *a;
	*a = *b;
	*b = tmp;
}

//void HeapInit(myHeap* php)
//{
//	assert(php);
//	php->_arr = NULL;
//	php->_capa = php->_size = 0;
//}
void HeapInit(myHeap* php, int TopK)
{
	assert(php);

	typeE* tmp = (typeE*)malloc(sizeof(typeE) * TopK);
	if (tmp == NULL)
	{
		perror("malloc err");
		exit(1);
	}

	php->_arr = tmp;
	php->_capa = TopK;
	php->_size = 0;

}
void HeapDestroy(myHeap* php)
{
	assert(php);

	free(php->_arr);
	php->_arr = NULL;
	php->_capa = php->_size = 0;

}
void AdjustUp(myHeap* php, int child)
{
	int parent = (child - 1) >> 1;

	while (child > 0)
	{
		//建大堆
		if (cmp(php->_arr[parent], php->_arr[child]))
		{
			mySwap(php->_arr + parent, php->_arr + child);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(myHeap* php, typeE x)
{
	assert(php);

	if (php->_size == php->_capa)//判满
	{
		int newCapa = php->_capa ? 2 * php->_capa : 4;

		typeE* newArr = (typeE*)realloc(php->_arr, sizeof(typeE) * newCapa);

		if (newArr == NULL)
		{
			perror("realloc\n");
			exit(1);
		}
		
		php->_arr = newArr;
		php->_capa = newCapa;
	}

	php->_arr[php->_size++] = x;

	AdjustUp(php, php->_size - 1);

}
void AdjustDw(myHeap* php, int parent)
{
	assert(php);

	int child = parent * 2 + 1;

	//大堆
	while (child < php->_size)
	{
		//找出最大孩子
		if (child + 1 < php->_size && cmp(php->_arr[child], php->_arr[child + 1]))
		{
			++child;
		}

		//向下走
		if (cmp(php->_arr[parent], php->_arr[child]))
		{
			mySwap(php->_arr + parent, php->_arr + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(myHeap* php)
{
	assert(php);
	php->_arr[0] = php->_arr[--php->_size];
	AdjustDw(php, 0);

}
typeE HeapTop(myHeap* php)
{
	assert(php && php->_size);

	return php->_arr[0];
}
bool HeapEmpty(myHeap* php)
{
	assert(php);

	return php->_size == 0;
}
int HeapSize(myHeap* php)
{
	assert(php);

	return php->_size;
}


void HeapSort(int arr[], int n)
{
	assert(arr);

	for (int i = (n - 1 - 1) >> 1; i >= 0; --i)
	{
		int parent = i;
		int child = parent * 2 + 1;

		//大堆
		while (child < n)
		{
			//找出最大孩子
			if (child + 1 < n && cmp(arr[child], arr[child + 1]))
			{
				++child;
			}

			//向下走
			if (cmp(arr[parent], arr[child]))
			{
				mySwap(arr + parent, arr + child);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
}