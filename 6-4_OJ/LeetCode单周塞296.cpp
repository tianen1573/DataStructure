#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-296 */

/*����С��Ϸ*/
/*ģ��*/
//class Solution {
//public:
//    int minMaxGame(vector<int>& nums) {
//
//        if (nums.size() == 1)
//            return nums[0];
//        int n = nums.size();
//        while (n > 1)
//        {
//            for (int i = 0; i < n / 2; i++)
//            {
//                if (i % 2 == 0)
//                    nums[i] = min(nums[i * 2], nums[i * 2 + 1]);
//                else
//                    nums[i] = max(nums[i * 2], nums[i * 2 + 1]);
//            }
//            n /= 2;
//        }
//        return nums[0];
//
//    }
//};

/*��������ʹ����Ϊ K*/
/*����-����ָ��*/
//class Solution {
//public:
//    int partitionArray(vector<int>& nums, int k) {
//
//        int cnt = 0;
//        sort(nums.begin(), nums.end());
//        int last = 0, fast = 0;
//        for (last = 0; fast < nums.size(); fast++)
//        {
//            if (nums[fast] - nums[last] > k)
//            {
//                cnt++;
//                last = fast;
//            }
//        }
//        cnt++;
//
//        return cnt;
//
//    }
//};

/*�滻�����е�Ԫ��*/
/*ֵ-�±� ģ��*/
//class Solution {
//public:
//    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
//        int pos[1000007] = { 0 };//����numsԪ�ص��±�
//        for (int i = 0; i < nums.size(); i++) pos[nums[i]] = i;
//
//        for (int i = 0; i < operations.size(); i++)
//        {
//
//            nums[pos[operations[i][0]]] = operations[i][1];//����Ԫ��ֵ
//            pos[operations[i][1]] = pos[operations[i][0]];//����ԭԪ�ص��±�Ϊ��ǰԪ�ص��±�
//
//        }
//
//        return nums;
//    }
//};
