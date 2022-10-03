#define _CRT_SECURE_NO_WARNINGS 1

/*�Ƴ�Ԫ��*/
/* https://leetcode-cn.com/problems/remove-element/submissions/ */
//int removeElement(int* nums, int numsSize, int val) {
//    int L = numsSize;//L�����鳤��
//    for (int i = 0; i < L; i++)//����ʼ������val��Lֵ�ڸı�
//    {
//        if (nums[i] == val)//ֵΪvalʱ�����ҿ�ʼ�ҷ�valֵ�滻
//        {
//            while (i < L)
//            {
//                if (nums[L - 1] != val)
//                {
//                    nums[i] = nums[L - 1];
//                    --L;
//                    break;//�ҵ�ʱ���˳� while ѭ��
//                }
//                L--;
//            }
//            //nums[i] = nums[L-1];//�����滻�������ǲ���valֵ
//            //--L;
//            //--i;
//        }
//    }
//    return L;
//}
//���ҿ����ı�˳��
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
//ԭ˳�򣬽�������
*/

/*�ϲ���������*/
/* https://leetcode-cn.com/problems/merge-sorted-array/submissions/ */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //���泤��
    nums1Size = m + n;
    //�ϲ�����������±꣬nums1��nums2ĩβԪ���±�
    int Len = m-- + n-- - 1;
    //�Ӻ�Ƚϲ���
    while (m >= 0 && n >= 0)
    {
        //nums1�󣬱���nums1��nums1ĩβ
        if (nums1[m] > nums2[n])
        {
            nums1[Len] = nums1[m];
            m--;
            Len--;
        }
        //���򱣴�nums2
        else
        {
            nums1[Len] = nums2[n];
            n--;
            Len--;
        }
    }
    //����ʣ��Ԫ��
    while (m >= 0)
    {
        nums1[Len--] = nums1[m--];
    }
    while (n >= 0)
    {
        nums1[Len--] = nums2[n--];
    }

}

/*��ת����*/
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
    //k ���ܴ��� ���鳤��
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);

}

/*ɾ�����������е��ظ���*/
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