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

	//����д��
	for (int i = 0; i < n - 1; ++i)
	{
		// [0,end]���򣬰�end+1λ�õ�ֵ���룬��������
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

	//gap > 1, Ԥ����
	//ֱ��gapΪ1��תΪ��������
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		////�������Ϊgap�飬 ����Ԥ����
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

		//��������
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

// ѡ������
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

	// ˫��ѡ������

	int begin = 0, end = n - 1;//�պ�����
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
		//������Сֵ
		swap(a[begin], a[mini]);
		//��ʱ��begin����Ϊ���ֵ�� ��Ϊ���ֵ�� �����ֵ���滻����mini�� ����һ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(a[end], a[maxi]);

		++begin;
		--end;
	}
}
// ������
void AdjustDwon(int* arr, int n, int parent)
{

	int child = parent * 2 + 1;

	//���
	while (child < n)
	{
		//�ҳ������
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			++child;
		}

		//������
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
	//����
	for (int i = (n - 1 - 1) >> 1; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	
	//���Ѷ�Ԫ���Ƶ���� ��д�ӶѶ����½���
	for (int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDwon(a, i, 0);
	}
}

// ð������
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
//����ȡ��
int GetMinTree(int* a, int left, int right)
{
	//����ȥ�У� �ܹ���Ч���⣬��С������ֵ�� ������֧��
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

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{

	int keyi = left;
	swap(a[keyi], a[GetMinTree(a, left, right)]);//����ȡ��

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
		
		swap(a[left], a[right]);//����

	}

	swap(a[left], a[keyi]);//����ֵ�Ƶ��м�
	keyi = left;//������ֵ���±�

	return keyi;


}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int piti = left;//�������Ϊ��һ��Ϊ��
	swap(a[piti], a[GetMinTree(a, left, right)]);//����ȡ��
	int key = a[piti];

	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//��ӣ� ����
		a[piti] = a[right];
		piti = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//��ӣ� ����
		a[piti] = a[left];
		piti = left;
	}

	a[piti] = key;
	return piti;

}
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int pre = left, cur = left + 1;
	int keyi = left; //������ҿ�ʼ
	swap(a[keyi], a[GetMinTree(a, left, right)]);//����ȡ��

	//cur �ߵı� pre �죬 [left, pre]�����ֵ ȫ С�ڵ�����ֵ���� a[cur] < a[keyi]
	// �� ++pre == cur ʱ�� ����cur����һֱ����Сֵ�� ����Ҫ����
	// �� ++pre < cur ʱ�� �� preָ���ֵ �϶��Ǹ���ֵ�� ����
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

	if (right - left > 10)//���������
	{
		//int keyi = PartSort1(a, left, right);
		//int keyi = PartSort2(a, left, right);
		int keyi = PartSort3(a, left, right);


		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
	else//С���ӽ����򣬲�������
	{
		InsertSort(a + left, right - left + 1);
	}

}
// �������� �ǵݹ�ʵ��
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

		//��ֹ��������
		if (begin >= end)
		{
			continue;
		}

		if (end - begin > 10)//���������
		{
			//int keyi = PartSort1(a, left, right);
			//int keyi = PartSort2(a, left, right);
			int keyi = PartSort1(a, begin, end);

			//��ֹ��֧��
			que.push({ begin, keyi - 1 });
			que.push({ keyi + 1, end });
			
		}
		else//С���ӽ����򣬲�������
		{
			InsertSort(a + begin, end - begin + 1);
		}
		
	}
	
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//�Ϸ�����
	if (left >= right)
	{
		return;
	}

	//����
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//�ϲ�
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


	//����
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}

}
// �鲢����ݹ�ʵ��
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
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//����Ҫ���Σ� ֱ�Ӵ����һ��鲢
	int gap = 1;//���һ�㣬 ����Ϊ1
	while (gap < n)
	{

		for (int i = 0; i < n; i += 2 * gap)//�����鲢
		{
			// [i,i+gap-1][i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// end1Խ�����begin2Խ�磬ֻ��һ�������䣬����Բ��鲢��
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			//�����ڶ�����������ұ߽�
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			//�鲢
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

			//����
			for (int left = i; left <= end2; ++left)//[i, end2]
			{
				a[left] = tmp[left];
			}
		}

		gap *= 2;
	}

	free(tmp);
}

// ��������
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