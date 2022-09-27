#define _CRT_SECURE_NO_WARNINGS 1

/*����ģ��*/
/* https://www.acwing.com/problem/content/787/ */
//#include<iostream>
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N];
//
//void quickSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//
//    int i = l - 1, j = r + 1, val = nums[l + r >> 1];//ȡ�м�ֵ����Ч
//    while (i < j)
//    {
//        do i++; while (nums[i] < val && i < r);
//        do j--; while (nums[j] > val && j > l);
//        if (i < j) swap(nums[i], nums[j]);
//        else break;
//    }
//
//    quickSort(nums, l, j);
//    quickSort(nums, j + 1, r);
//    /*
//    �������Ϊ��ʱ��[l, j],[j+1, r]�ɱ�����ѭ�����磨1��2��
//    �Ұ�����Ϊ��ʱ��[l, i - 1],[i, r],�磨2��1��
//    */
//    return;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//
//    for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
//
//    quickSort(nums, 1, n);
//
//    for (int i = 1; i <= n; i++) printf("%d ", nums[i]);
//
//    return 0;
//}

/*��k����*/
/* https://www.acwing.com/problem/content/788/ */
//#include <iostream>
//#include <algorithm>
//#include <stdlib.h>
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N];
//
//void qiuckSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//    int i = l - 1, j = r + 1, val = nums[l + r >> 1];
//    while (i < j)
//    {
//        do i++; while (nums[i] < val && i < r);
//        do j--; while (nums[j] > val && j > l);
//        if (i < j) swap(nums[i], nums[j]);
//        else break;
//    }
//
//    qiuckSort(nums, l, j), qiuckSort(nums, j + 1, r);
//
//    return;
//}
//
//int main()
//{
//    int n = 0, k = 0;
//    cin >> n >> k;
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//
//    qiuckSort(nums, 1, n);
//    //sort(nums + 1, nums + 1 + n);
//
//    cout << nums[k];
//
//    return 0;
//}

/*�鲢ģ��*/
/* https://www.acwing.com/problem/content/789/ */
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N], tmp[N];
// /*
// �ȷָ�ٺϲ���������Ƶ�ԭ�����Ӧλ��
// */
//void mergeSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//
//    int mid = (l + r) >> 1;
//
//    mergeSort(nums, l, mid), mergeSort(nums, mid + 1, r);//�ȷָ�
//
//    int k = 0, i = l, j = mid + 1;
//
//    //�ٺϲ�����������
//    while (i <= mid && j <= r)
//    {
//        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
//        else tmp[k++] = nums[j++];
//    }
//    while (i <= mid) tmp[k++] = nums[i++];
//    while (j <= r) tmp[k++] = nums[j++];
//
//    //���Ƶ�ԭ�����Ӧλ��
//    for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
//
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//
//    mergeSort(nums, 1, n);
//
//    for (int i = 1; i <= n; i++) cout << nums[i] << " ";
//
//    return 0;
//}

/*����Ե�����*/
/* https://www.acwing.com/problem/content/790/ */
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 7;
//int nums[N], tmp[N];
//long long count = 0;
// /*
// �ȷָ�ٺϲ���������Ƶ�ԭ�����Ӧλ��
// */
//void mergeSort(int nums[], int l, int r)
//{
//    if (l >= r) return;
//
//    int mid = (l + r) >> 1;
//
//    mergeSort(nums, l, mid), mergeSort(nums, mid + 1, r);//�ȷָ�
//
//    int k = 0, i = l, j = mid + 1;
//
//    //�ٺϲ�����������
//
//    while (i <= mid && j <= r)
//    {
//        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
//        /*
//        ���ȣ�i��Ӧ���֣�һ����j��Ӧ����������֮ǰ���� i < j �����
//        ��Σ���nums[i] > nums[j], �� i �� mid ������nums[j]����Ϊi��j��Ӧ�������������
//        �򣬴���nums[j] ���� mid - i + 1 ��
//        */
//        else count += mid - i + 1, tmp[k++] = nums[j++];
//    }
//    while (i <= mid) tmp[k++] = nums[i++];
//    while (j <= r) tmp[k++] = nums[j++];
//
//    //���Ƶ�ԭ�����Ӧλ��
//    for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
//
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    for (int i = 1; i <= n; i++) cin >> nums[i];
//    mergeSort(nums, 1, n);
//
//    cout << count << endl;
//
//    return 0;
//}
