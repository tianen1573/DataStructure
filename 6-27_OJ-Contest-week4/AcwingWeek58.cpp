#define _CRT_SECURE_NO_WARNINGS 1

/* https://www.acwing.com/activity/content/1994/ */

/*Ѱ��1*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int n, a;
//bool lag;
//
//int main()
//{
//    cin >> n;
//    while (n--)
//    {
//        cin >> a;
//        if (a) lag = true;
//    }
//
//    if (lag) cout << "YES";
//    else cout << "NO";
//
//    return 0;
//}

/*������� -- ̰��*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 2e5 + 11;
//int cnt, mcnt, last, cur, n;
//
// /*�����ڣ���һ�����������У����ֵΪ1����󳤶�������*/
//int main()
//{
//    cin >> n;
//
//    if (n == 1)
//    {
//        cout << "1";
//        return 0;//������ģ�������ʱ����return�ˣ�
//    }
//    else
//    {
//        n--;
//        cin >> last;
//        cnt = mcnt = 1;
//    }
//
//    while (n--)
//    {
//        cin >> cur;
//
//        if (cur > 2 * last)
//        {
//            mcnt = max(mcnt, cnt);
//            cnt = 1;
//        }
//        else
//        {
//            cnt++;
//        }
//
//        last = cur;
//    }
//    mcnt = max(cnt, mcnt);
//
//    cout << mcnt;
//
//    return 0;
//}

/*Ⱦɫ -- ˼ά*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 1e4 + 11;
//int fat[N], clr[N], F, C, n;
//int cnt = 1;//���ڵ�Ⱦɫ
//
//int main()
//{
//    cin >> n;
//    for (int i = 2; i <= n; i++)//��¼���׽ڵ�
//        cin >> F, fat[i] = F;
//    for (int i = 1; i <= n; i++)//��¼�ڵ���ɫ
//        cin >> C, clr[i] = C;
//
//    for (int i = 2; i <= n; i++)//
//        if (clr[i] != clr[fat[i]])//����͸��׽ڵ���ɫ��һ�£���ýڵ���Ҫ����Ⱦɫ
//            cnt++;
//
//    cout << cnt;
//    return 0;
//}