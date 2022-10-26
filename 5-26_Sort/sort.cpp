#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; ++ i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int* arr, int n)
{

	//优质写法
	for (int i = 0; i < n - 1; ++i)
	{
		// [0,end]有序，把end+1位置的值插入，保持有序
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}


	//for (int i = 1; i < n; ++i)
	//{
	//	//int key = arr[i];
	//	for (int j = i - 1; j >= 0; --j)
	//	{
	//		if (arr[j + 1] < arr[j])
	//		{
	//			swap(arr[j], arr[j + 1]);
	//		}
	//	}
	//}
}

void ShellSort(int* arr, int n)
{
	int gap = n;

	//gap > 1, 预排序
	//直到gap为1，转为插入排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		////将数组分为gap组， 进行预排序
		//for (int j = 0; j < gap; ++j)
		//{
		//	for (int i = j; i < n - gap; i += gap)
		//	{
		//		int end = i;
		//		int tmp = arr[end + gap];
		//		while (end >= 0)
		//		{
		//			if (tmp < arr[end])
		//			{
		//				arr[end + gap] = arr[end];
		//				end -= gap;
		//			}
		//			else
		//			{
		//				break;
		//			}
		//		}
		//		arr[end + gap] = tmp;
		//	}
		//}

		//交替排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

// -----------------------------------------

// 选择排序
void SelectSort(int* a, int n)
{
	/*for (int i = 0; i < n; ++i)
	{
		int keyi = i;
		for (int j = i + 1; j < n; ++ j)
		{
			if (a[j] < a[keyi])
			{
				keyi = j;
			}
		}
		swap(a[i], a[keyi]);
	}*/

	// 双端选择排序

	int begin = 0, end = n - 1;//闭合区间
	while (begin < end)
	{
		int mini = begin, maxi = begin;

		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		//交换最小值
		swap(a[begin], a[mini]);
		//此时，begin可能为最大值， 若为最大值， 则最大值被替换到了mini， 更正一下
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(a[end], a[maxi]);

		++begin;
		--end;
	}
}
// 堆排序
void AdjustDwon(int* arr, int n, int parent)
{

	int child = parent * 2 + 1;

	//大堆
	while (child < n)
	{
		//找出最大孩子
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			++child;
		}

		//向下走
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) >> 1; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	
	//将堆顶元素移到最后， 重写从堆顶向下建堆
	for (int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDwon(a, i, 0);
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		bool flg = true;
		for (int j = 0; i < n - 1 - i; ++j)
		{
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flg = false;
			}
		}

		if (flg)
		{
			break;
		}
	}
}
//三数取中
int GetMinTree(int* a, int left, int right)
{
	//三数去中， 能够有效避免，因极小极大枢值， 产生单支树
	int mid = (left + right) >> 1;

	if (a[left] >= a[mid] && a[left] <= a[right])
	{
		return left;
	}
	else if (a[left] >= a[right] && a[left] <= a[mid])
	{
		return left;
	}
	else if (a[mid] >= a[left] && a[mid] <= a[right])
	{
		return mid;
	}
	else if (a[mid] >= a[right] && a[mid] <= a[left])
	{
		return mid;
	}
	else if (a[right] >= a[mid] && a[right] <= a[left])
	{
		return right;
	}
	else if (a[right] >= a[left] && a[right] <= a[mid])
	{
		return right;
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{

	int keyi = left;
	swap(a[keyi], a[GetMinTree(a, left, right)]);//三数取中

	while (left < right)
	{

		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		
		swap(a[left], a[right]);//交换

	}

	swap(a[left], a[keyi]);//将枢值移到中间
	keyi = left;//返回枢值的下标

	return keyi;


}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int piti = left;//令最左边为第一个为坑
	swap(a[piti], a[GetMinTree(a, left, right)]);//三数取中
	int key = a[piti];

	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//填坑， 换坑
		a[piti] = a[right];
		piti = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//填坑， 换坑
		a[piti] = a[left];
		piti = left;
	}

	a[piti] = key;
	return piti;

}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int pre = left, cur = left + 1;
	int keyi = left; //从左或右开始
	swap(a[keyi], a[GetMinTree(a, left, right)]);//三数取中

	//cur 走的比 pre 快， [left, pre]区间的值 全 小于等于枢值，若 a[cur] < a[keyi]
	// 当 ++pre == cur 时， 代表cur遇到一直都是小值， 不需要更换
	// 当 ++pre < cur 时， 则 pre指向的值 肯定是个大值， 交换
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++pre != cur)
		{
			swap(a[pre], a[cur]);
		}

		++cur;
	}

	swap(a[keyi], a[pre]);
	keyi = pre;

	return keyi;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	if (right - left > 10)//大区间快排
	{
		//int keyi = PartSort1(a, left, right);
		//int keyi = PartSort2(a, left, right);
		int keyi = PartSort3(a, left, right);


		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
	else//小而接近有序，插入排序
	{
		InsertSort(a + left, right - left + 1);
	}

}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	queue<pair<int, int>> que;
	que.push({ left, right });

	while (!que.empty())
	{
		int begin = que.front().first;
		int end = que.front().second;
		que.pop();

		//防止错误区间
		if (begin >= end)
		{
			continue;
		}

		if (end - begin > 10)//大区间快排
		{
			//int keyi = PartSort1(a, left, right);
			//int keyi = PartSort2(a, left, right);
			int keyi = PartSort1(a, begin, end);

			//防止单支树
			que.push({ begin, keyi - 1 });
			que.push({ keyi + 1, end });
			
		}
		else//小而接近有序，插入排序
		{
			InsertSort(a + begin, end - begin + 1);
		}
		
	}
	
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//合法区间
	if (left >= right)
	{
		return;
	}

	//分治
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//合并
	int begin1 = left, begin2 = mid + 1;
	int end1 = mid, end2 = right;
	int k = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[k++] = a[begin1++];
		}
		else
		{
			tmp[k++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[k++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[k++] = a[begin2++];
	}


	//拷贝
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}

}
// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * (n));

	if (tmp == nullptr)
	{
		perror("malloc err");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//不需要分治， 直接从最后一层归并
	int gap = 1;//最后一层， 区间为1
	while (gap < n)
	{

		for (int i = 0; i < n; i += 2 * gap)//两两归并
		{
			// [i,i+gap-1][i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// end1越界或者begin2越界，只有一个子区间，则可以不归并了
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			//修正第二个子区间的右边界
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			//归并
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			//拷贝
			for (int left = i; left <= end2; ++left)//[i, end2]
			{
				a[left] = tmp[left];
			}
		}

		gap *= 2;
	}

	free(tmp);
}

// 计数排序
void CountSort(int* a, int n)
{
	int _min = a[0], _max = a[0];

	for (int i = 0; i < n; ++i)
	{
		_min = min(_min, a[i]);
		_max = max(_max, a[i]);
	}
	//cout << _min << " " << _max << endl;

	int _size = _max - _min + 1;

	int* tmp = (int*)calloc(_size, sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		tmp[a[i] - _min]++;
	}

	for (int i = 0, j = 0; j < _size; ++ j)
	{
		while (tmp[j])
		{
			a[i++] = j + _min;
			--tmp[j];
		}
		
	}

}