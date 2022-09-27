#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-301/ */

/*װ��������Ҫ�����ʱ��*/
//class Solution {
//public:
//
//    int fillCups(vector<int>& amount) {
//
//        int cnt = 0;
//        while (true)
//        {
//            sort(amount.begin(), amount.end(), [&](int& a, int& b)//����
//                {
//                    return a > b;
//                });
//            if (amount[0] > 0)
//            {
//                amount[0]--;
//                amount[1]--;
//                cnt++;
//            }
//            else break;
//        }
//        return cnt;
//
//    }
//};

/*���޼��е���С����*/
// /*set*/
//class SmallestInfiniteSet {
//    set<int> sma;
//public:
//    SmallestInfiniteSet() {
//        sma.clear();
//        for (int i = 1; i <= 1000; i++) sma.insert(i);
//
//    }
//
//    int popSmallest() {
//
//        int a = *(sma.begin());
//        sma.erase(sma.begin());
//
//        return a;
//
//    }
//
//    void addBack(int num) {
//        sma.insert(num);
//    }
//};
// /*ģ��
//class SmallestInfiniteSet {
//    int _min = 1;
//    bool arr[1007] = {0};
//    int size = 0;
//public:
//    SmallestInfiniteSet() {
//
//        _min = 1;//��ʼ��������С��
//        memset(arr, 0, sizeof(arr));//��ʼ��������
//
//    }
//
//    int popSmallest() {
//        int pos = -1;
//        for(int i = 1; i < _min; i++)//���������С
//            if(arr[i])
//            {
//                pos = i;
//                break;
//            }
//        if(pos != -1)//������
//        {
//            arr[pos] = false;
//            return pos;
//        }
//        else//������
//        {
//            _min++;
//            return _min - 1;
//        }
//
//    }
//
//    void addBack(int num) {
//        if(num >= _min) return ;
//
//        arr[num] = true;
//
//    }
//};*/
// /**
// * Your SmallestInfiniteSet object will be instantiated and called as such:
// * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
// * int param_1 = obj->popSmallest();
// * obj->addBack(num);
// */

/*�ƶ�Ƭ�εõ��ַ���*/
////������ĸ������Ӧ
////��Σ� ��Ӧ�ģ�s��L������t���ұߣ�s��R������t�����
//class Solution {
//public:
//    bool canChange(string start, string target) {
//
//        int j = 0;
//        for (int i = 0; i < start.size(); i++)//�����������ж�
//        {
//            if (start[i] == '_') continue;
//            while (j < start.size() && target[j] == '_') j++;
//
//            if (j == start.size()) return false;//Խ��
//            if (start[i] != target[j]) return false;//��ĸ��ͬ
//            if (start[i] == 'L' && i < j) return false;//s��L ���� t��L ����ߣ���s��L�޷������ƶ�
//            if (start[i] == 'R' && i > j) return false;//ͬ��
//            j++;//����
//        }
//
//        //�ж� s���ַ� �� t���ַ�
//        for (j; j < start.size(); j++)
//            if (target[j] != '_') return false;
//
//        return true;
//
//    }
//};

/*ͳ�������������Ŀ--����*/
////DP
//class Solution {
//public:
//    int idealArrays(int n, int maxValue) {
//        const int MOD = 1e9 + 7;
//        vector< vector<int> > f(maxValue + 1, vector<int>(15));
//        for (int i = 1; i <= maxValue; i++) f[i][1] = 1;//��i��β��ֻ��һ��Ԫ��
//
//        for (int j = 1; j < 14; j++)//j���Ϊ14 -- 1*2^14 ,��ʱ��jΪͳ�ƹ��ģ������Ϊ13
//            for (int i = 1; i <= maxValue; i++)
//                for (int k = 2; k * i <= maxValue; k++)//ģ�ⱶ��
//                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % MOD;
//
//        //�������
//        vector< vector<int> > C(n, vector<int>(15));
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j <= i && j <= 14; j++)
//                if (j == 0) C[i][j] = 1;
//                else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//
//        int res = 0;
//        for (int i = 1; i <= maxValue; i++)
//            for (int j = 1; j <= 14 && j <= n; j++)//j��1��ʼ�� ���ֵΪ min(14, n)
//                res = (res + (long long)f[i][j] * C[n - 1][j - 1]) % MOD;
//
//        return res;
//    }
//};
////����--yxc
////f[i][j] -- ��i��β������j�в�ͬԪ��
////i = (1, maxV), j = (1, 14) --> ��С����2������13�Σ����ϳ�ʼ1��14��Ԫ��
////��ÿһ��״̬���Դ��� f[i][j] * C[n - 1][j - 1]�������� --> ���巨����n��λ�ã�����j������n - 1��λ�ÿ��ԷŸ��壬��Ҫj-1�����塣
//////����
////class Solution {
////public:
////    int n, m;
////    int ans = 0;
////    const int MOD = 1e9 + 7;
////    vector<vector<int>> f;
////
////    void dfs(int u, int cnt) {
////        ans = (ans + f[n - 1][cnt - 1]) % MOD;//���巨
////        if (cnt < n) {
////            for (int i = 2; i * u <= m; i++)
////                dfs(i * u, cnt + 1);
////        }
////    }
////
////    int idealArrays(int n, int m) {
////        this->n = n, this->m = m;
////        f = vector<vector<int>>(n, vector<int>(20));
////        for (int i = 0; i < n; i++)
////            for (int j = 0; j < 20 && j <= i; j++)
////                if (!j) f[i][j] = 1;
////                else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
////
////        for (int i = 1; i <= m; i++)
////            dfs(i, 1);
////
////        return ans;
////    }
////};
//////���ߣ�yxc
