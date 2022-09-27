#define _CRT_SECURE_NO_WARNINGS 1

/*移除元素*/
/* https://leetcode-cn.com/problems/remove-element/submissions/ */
//int removeElement(int* nums, int numsSize, int val) {
//    int L = numsSize;//L新数组长度
//    for (int i = 0; i < L; i++)//从左开始遍历找val，L值在改变
//    {
//        if (nums[i] == val)//值为val时，从右开始找非val值替换
//        {
//            while (i < L)
//            {
//                if (nums[L - 1] != val)
//                {
//                    nums[i] = nums[L - 1];
//                    --L;
//                    break;//找到时，退出 while 循环
//                }
//                L--;
//            }
//            //nums[i] = nums[L-1];//从右替换，不管是不是val值
//            //--L;
//            //--i;
//        }
//    }
//    return L;
//}
//左右开弓改变顺序
/*
int removeElement(int* nums, int numsSize, int val)
{
    int j = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
//原顺序，交换数据
*/

/*合并有序数组*/
/* https://leetcode-cn.com/problems/merge-sorted-array/submissions/ */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //保存长度
    nums1Size = m + n;
    //合并数组待插入下标，nums1，nums2末尾元素下标
    int Len = m-- + n-- - 1;
    //从后比较插入
    while (m >= 0 && n >= 0)
    {
        //nums1大，保存nums1至nums1末尾
        if (nums1[m] > nums2[n])
        {
            nums1[Len] = nums1[m];
            m--;
            Len--;
        }
        //否则保存nums2
        else
        {
            nums1[Len] = nums2[n];
            n--;
            Len--;
        }
    }
    //保存剩余元素
    while (m >= 0)
    {
        nums1[Len--] = nums1[m--];
    }
    while (n >= 0)
    {
        nums1[Len--] = nums2[n--];
    }

}

/*轮转数组*/
/* https://leetcode-cn.com/problems/rotate-array/ */
void reverse(int* nums, int left, int rig)
{
    while (left < rig)
    {
        int tmp = nums[left];
        nums[left++] = nums[rig];
        nums[rig--] = tmp;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    //k 可能大于 数组长度
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);

}

/*删除有序数组中的重复项*/
/* https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/ */
int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int dest = 1, src = 0;

    for (; dest < numsSize; dest++)
        if (nums[dest] != nums[src])
            nums[++src] = nums[dest];

    return src + 1;

}