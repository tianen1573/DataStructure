#define _CRT_SECURE_NO_WARNINGS 1

/*ACWing-week54*/
/* https://www.acwing.com/activity/content/1876/ */

/*4428. �ַ���*/
/*ģ��*/
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//int ans[26];
//string str;
//
//int main()
//{
//    int l = 0;
//    cin >> l;
//    cin >> str;
//
//    for (int i = 0; i < l; i++)
//    {
//        if (str[i] >= 'a' && str[i] <= 'z')
//            ans[str[i] - 'a']++;
//        else
//            ans[str[i] - 'A']++;
//    }
//
//    for (int i = 0; i < 26; i++)
//        if (ans[i] < 1)
//        {
//            cout << "NO";
//            return 0;
//        }
//
//    cout << "YES";
//    return 0;
//}

/*4429. ��������*/
/*˼ά*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//#define x first
//#define y second
//
//typedef pair<int, int> PII;
//typedef long long LL;
//const int N = 2009;
//
//PII q[N];
//PII s1, s2;
//int n;
//
//LL dis(PII a, PII b)
//{
//    LL x = a.x - b.x;
//    LL y = a.y - b.y;
//
//    return x * x + y * y;
//}
//
//bool cmp(PII a, PII b)
//{
//    return dis(a, s1) < dis(b, s1);
//}
//
//
//int main()
//{
//    cin >> n >> s1.x >> s1.y >> s2.x >> s2.y;
//
//    /*����ţ��s1�ľ���Ϊ��λ���򣬴�С����*/
//    for (int i = 1; i <= n; i++) cin >> q[i].x >> q[i].y;
//    sort(q + 1, q + 1 + n, cmp);
//
//    LL ans = 1e18 + 7, dis2 = 0;
//
//    /*ÿ��ȥ����Զ�ģ���s2�����ǣ�����s2���ǵ���Զ����*/
//    for (int i = n; i >= 1; i--)
//    {
//        ans = min(ans, dis(s1, q[i]) + dis2);
//        dis2 = max(dis2, dis(s2, q[i]));
//    }
//
//    ans = min(ans, dis2);
//
//    printf("%lld", ans);
//
//    return 0;
//
//}

/*4430. ��������*/
/*˼ά-ǰ׺��*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int n = 0;
//string str;
//
//int work()
//{
//    int cnt = 0, r = 0;
//    for (int i = 0; i < n; i++)
//        if (str[i] == '(') cnt++;
//        else
//        {
//            cnt--;
//            r++;
//            if (cnt < 0)
//            {
//                cnt += 2;
//                for (i = i + 1; i < n; i++)
//                    if (str[i] == '(') cnt++;
//                    else
//                    {
//                        cnt--;
//                        if (cnt < 0) return 0;
//
//                    }
//                return r;
//            }
//        }
//
//    return 0;
//}
//
//
//int main()
//{
//    cin >> n >> str;
//    int l = 0, r = 0;
//    for (int i = 0; i < n; i++)
//        if (str[i] == '(') l++;
//        else r++;
//
//    if (r == l + 2) printf("%d", work());
//    else if (l == r + 2)
//    {
//        /*
//        �����Ŵ��������ţ���cnt����ǰ׺�ͣ���ǰ׺��Ϊ��ʱ�����׸����˸������ű�����ڱ��
//        �����Ŵ��������ţ������ң�cnt == 2���ܱ�ţ�
//        Ϊ���Ҵ����󱣳�һ�£�������cnt > 0 ֮ǰ���׸����˸������ű�����ڱ�ţ����ñ�� -�� r == l + 2
//        */
//        reverse(str.begin(), str.end());
//        for (int i = 0; i < n; i++)
//            if (str[i] == '(') str[i] = ')';
//            else str[i] = '(';
//        printf("%d", work());
//    }
//    else printf("0");
//
//    return 0;
//}