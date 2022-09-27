#define _CRT_SECURE_NO_WARNINGS 1


#include <vector>
#include <map>
#include <iostream>
using namespace std;

/*���㲼����������ֵ*/
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//
//        if (root->left == NULL)
//            return root->val;
//        else if (root->val == 2)
//            return evaluateTree(root->left) || evaluateTree(root->right);
//        else
//            return evaluateTree(root->left) & evaluateTree(root->right);
//
//    }
//};

/*�����ϳ�ʱ��*/
//class Solution {
//public:
//
//    //�����midʱ�̣��Ƿ������ϳ�
//    bool check(int mid, vector<int>& bs, vector<int>& ps, int cpa)
//    {
//        int n = bs.size(), m = ps.size();
//        vector<int> tmp = ps;
//        tmp.push_back(mid);
//        int k = m;//��ʱtmp��СΪm+1
//
//        while (k && tmp[k - 1] > tmp[k]) swap(tmp[k - 1], tmp[k]), k--;
//
//        for (int i = 0, j = 0; i < n; i++)
//            for (int c = 0; c < cpa && j <= m && tmp[j] <= bs[i]; c++, j++)//����ѭ����ʹ������ʱ�����ϳ�
//                if (tmp[j] >= mid)//���ڵ���mid���ʹ���mid���ϳ�
//                    return true;
//
//        return false;
//    }
//
//    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
//
//        sort(buses.begin(), buses.end());
//        sort(passengers.begin(), passengers.end());
//
//        //���ݷ���ʱ����������������ϳ������ʱ�� -- �������ϳ���ʱ�̣���
//        int l = 0, r = 1e9;
//        while (l < r)
//        {
//            int mid = (l + r + 1) >> 1;
//            if (check(mid, buses, passengers, capacity)) l = mid;
//            else r = mid - 1;
//        }
//
//        //�������ϳ����ʱ�� �� 0
//        //�����ʱ�����ˣ���ǰһ����
//        unordered_set<int> hash;
//        for (auto x : passengers) hash.insert(x);
//        while (hash.count(r)) r--;
//
//        return r;
//
//    }
//};
////������ϳ�ʱ��
////��1e9 ~ 1 �ö��֣����Լ�ģ�������ϳ�ʱ����뵽�˿��������ϳ�ʱ��
////Ȼ����ģ������ϳ�ʱ�� ~ 0���Ҳ���ͻʱ�䣬����һ��
////����--yxc
//// class Solution {
//// public:
////     int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
////         sort(buses.begin(), buses.end());
////         sort(passengers.begin(), passengers.end());
////         int j = 0, c;
////         for (int t: buses)
////             for (c = capacity; c && j < passengers.size() && passengers[j] <= t; ++j)
////                 --c;
////         --j;
////         int ans = c ? buses.back() : passengers[j]; // �ڷ���ʱ���﹫��վ or ��һ���ϳ��ĳ˿�
////         while (j >= 0 && passengers[j--] == ans) --ans; // ��ǰ��û�˵����ʱ��
////         return ans;
////     }
//// };
//// //�����һ���� == ������ϳ�ʱ��
//// //�����һ��������ʱ�Ƿ��п�λ���п�λ�ڷ���ʱ���ϳ���û��λ�����һλ�˿��ϳ�ʱ���ϳ�
//// //��ģ�⵽0������һ��
//// //����--���ɽ����

/*��С��ֵƽ����*/
//class Solution {
//public:
//    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//
//        const int n = nums1.size();
//        map<int, int, greater<int>>sub;
//        int k = k1 + k2;
//
//        for (int i = 0; i < n; i++)
//            sub[abs(nums1[i] - nums2[i])] ++;
//
//        while (k)
//        {
//            auto it = sub.begin();
//            if (it->first == 0) break;
//
//            if (k >= it->second)
//            {
//                sub[it->first - 1] += it->second;
//                k -= it->second;
//
//                sub.erase(it);
//            }
//            else
//            {
//                sub[it->first - 1] += k;
//                sub[it->first] -= k;
//                k = 0;
//            }
//        }
//
//        long long res = 0;
//        for (auto x : sub)
//            res += ((long long)x.first * x.first) * x.second;
//
//        return res;
//
//    }
//};