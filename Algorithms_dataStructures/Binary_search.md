######  **JZ53** **数字在升序数组中出现的次数**

 [数字在升序数组中出现的次数_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=23274&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) 

```
#define _CRT_SECURE_NO_WARNINGS 1

//给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数
//数据范围：0 \le n \le 1000, 0 \le k \le 1000≤n≤1000, 0≤k≤100，数组中每个元素的值满足 0 \le val \le 1000≤val≤100
//要求：空间复杂度 O(1)O(1)，时间复杂度 O(logn)O(logn)
// 
////暴力法
//#include<stdio.h>
//int GetNumberOfK(int* data, int dataLen, int k) {
//    int i = 0;
//    int k_count = 0;
//    for (i = 0; i < dataLen; i++)
//    {
//        if (data[i] == k)
//        {
//            k_count++;
//        }
//        if (data[i] > k)
//            break;
//    }
//    return k_count;
//}
//二分法：找val的左边界，则val+1的左边界为val的右边界+1，right-left即val_count。
// 1.
// 若val存在：left为正常值，
// 若val+1存在，则right为正常值；
// 若val+1不存在，则right为数组中第一个大于val的元素的下标。
// 2.
// 若val不存在：left为第一个大于val的元素的下标，
// 若val+1存在，则right为正常值，此时left == right；
// 若val+1不存在，则right为数组中第一个大于val的元素的下标，此时left == right。
//
#include<stdio.h>
int Binary_search(int* data, int dataLen, int val)
{
	int low = 0;
	//将high = dataLen，Len==1时，方可进入循环
	int high = dataLen;

	int mid = low + (high - low) / 2;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		//找左边界，注意：data[mid] >= val，不是 >
		// >=，可使high和low向left靠近，则high = mid，若high = mid - 1，会使mid跳出val                                 
		if (data[mid] >= val)
		{
			high = mid;

		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}
int GetNumberOfK(int* data, int dataLen, int k)
{
	int high = 0;
	int low = 0;
	low = Binary_search(data, dataLen, k);
	high = Binary_search(data, dataLen, k + 1);
	return high - low;
}
```

