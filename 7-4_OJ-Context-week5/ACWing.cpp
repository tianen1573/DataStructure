#define _CRT_SECURE_NO_WARNINGS 1

/*Acwing-week-59*/
/* https://www.acwing.com/activity/content/2015/ */

/*�������*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sum[109] = { 0 }, SUM = 0, Min = 99999;
//int n;
//
//int main()
//{
//    cin >> n;
//    int tmp;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> tmp;
//        sum[i] = sum[i - 1] + tmp;//ǰ׺��
//        Min = min(Min, sum[i]);//��Сǰ׺��
//        SUM += tmp;//�����
//    }
//    Min = min(Min, 0);//����
//    cout << SUM - Min;
//    return 0;
//}

/*��������*/
////ÿ�μ�ȥ��С�����������Ĺ����У����������ı䣬��С������Ҳ��ı䣻
////����С������Ϊ2�������������Ϊ2������С������һֱΪ2����
////��nΪ������ֻ���һ��
////��nΪż����ÿ�ζ���2���� n / 2 ��
////��nΪ����������С������һ��Ϊ��������ȥ������Ϊż���� �� ��n - d��/ 2 + 1 ��
//
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <math.h>
//
//using namespace std;
//
//typedef long long LL;
//
//LL Mind, n, cnt = 0;
//
//bool prime(LL p)//�����ж�����
//{
//    if (p == 2 || p == 3)
//    {
//        return true;
//    }
//    if (p % 6 != 1 && p % 6 != 5)
//    {
//        return false;
//    }
//    for (int i = 5; i <= floor(sqrt(p)); i += 6)
//    {
//        if (p % i == 0 || p % (i + 2) == 0)
//        {
//            return false;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    cin >> n;
//
//    if (prime(n))//����
//    {
//        cout << "1";
//        return 0;
//    }
//
//    if (n % 2)//����
//    {
//        for (Mind = 3; Mind <= n; Mind += 2)
//            if (n % Mind == 0)
//            {
//                cnt++;
//                n -= Mind;
//                break;
//            }
//    }
//
//    cnt += (n / 2);
//    cout << cnt;
//    return 0;
//}

/*������ͨ����*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//const int N = 2e5 + 7;
//
//bool s[N];//״̬
//short b[N];//�����
//vector<int> map[N];//
//
//int n, m;
//int cnt;
//bool flag;
//
//void dfs(int i)
//{
//    s[i] = true;
//    for (auto x : map[i])
//    {
//        if (s[x]) continue;
//        if (b[x] != 2) flag = false;
//        dfs(x);
//    }
//}
//
//int main()
//{
//    cin >> n >> m;
//    int x, y;
//    while (m--)
//    {
//        scanf("%d %d", &x, &y);
//
//        map[x].push_back(y);
//        map[y].push_back(x);
//
//        b[x]++; b[y]++;
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (s[i] || b[i] != 2) continue;
//        flag = true;
//        dfs(i);
//        if (flag) cnt++;
//    }
//
//    cout << cnt;
//
//    return 0;
//}