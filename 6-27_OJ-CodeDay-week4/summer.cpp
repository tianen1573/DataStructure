#define _CRT_SECURE_NO_WARNINGS 1

/*�г�����*/
/* https://www.acwing.com/problem/content/695/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//
//using namespace std;
//
//#define x first
//#define y second
//
//typedef unordered_map<string, string> UMSS;
//
//const int N = 10011;
//
//int T, n;
//
//int main()
//{
//    cin >> T;
//    for (int t = 1; t <= T; t++)
//    {
//        UMSS um;//��¼�ڵ�
//        set<string> in;//��¼���
//        string a, b;
//
//        cin >> n;
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> a >> b;
//            um[a] = b;
//            //um.insert({ a, b });
//            in.insert(b);
//        }
// 
//        /*��ͷ*/
//        string hh;
//        for (auto h : um)
//            if (in.find(h.first) == in.end())
//            {
//                hh = h.first;
//                break;
//            }
//
//    
//        printf("Case #%d: ", t);
//
//        /*����*/
//        for (; um.find(hh) != um.end(); hh = um[hh])
//            cout << hh << '-' << um[hh] << ' ';
//
//        cout << endl;
//
//    }
//
//    return 0;
//}

/*��ƻ��*/
/* https://www.acwing.com/problem/content/description/3431/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//
//// int sum, ans;
//// int n, m;
//
//// //���п����ӣ�ǰ������ӻ�գ�����Ĳ���
//// void dfs(int step, int num)
//// {
////     if(step == n)//
////     {
////         if(m - sum >= num) ans++;
////         return;
////     }
////     for(int j = num; j <= m - sum; j++)
////     {
////         sum += j;
////         dfs(step + 1, j);
////         sum -= j;
////     }
//// }
//
//// int main()
//// {
////     while(~scanf("%d%d", &m, &n))
////     {
////         sum = ans = 0;
////         dfs(1, 0);
////         cout << ans << endl;
////     }
//
//
////     return 0;
//// }
//
//
//const int N = 12;
//
//int m, n;
//int f[N][N]; // f[m][n] ��ʾ�� m ��ͬ����ƻ������ n ��ͬ����������ķַ���
//
//int main()
//{
//    for (int i = 0; i < N; i++) f[i][1] = 1; // �� i ��ƻ������ 1 �������ֻ�� 1 �ַ���
//    for (int i = 0; i < N; i++) f[0][i] = 1; // �� 0 ��ƻ������ i �������Ҳֻ�� 1 �ַ���
//
//    for (int i = 1; i < N; i++) // ö��ƻ����
//        for (int j = 2; j < N; j++) // ö��������
//            if (i < j) f[i][j] = f[i][i]; // ���ƻ���� < ����������ض��� (������ - ƻ����) �����ŵ����ӣ����Խ���Щ���ŵ�����ȥ��
//            else f[i][j] = f[i][j - 1] + f[i - j][j]; // ƻ���� �� ��������������������ۣ�������һ�����ӿ��ţ�Ҳ����ÿ���������ٷ� 1 ��
//
//    while (cin >> m >> n) cout << f[m][n] << '\n';
//
//    return 0;
//}

/*������*/
/* https://www.acwing.com/problem/content/description/3480/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 1007;
//
//vector<int> p;
//bool t[N];
//int n;
//
//int main()
//{
//    cin >> n;
//
//    int a;
//    // for (int i = 0; i < n; i ++ )
//    //     cin >> a, p.push_back(a);
//
//    // sort(p.begin(), p.end());
//
//    // p.erase(unique(p.begin(), p.end()), p.end());
//
//    // for(auto x : p)
//    //     cout << x << ' ';
//
//    //Ͱ����
//    for (int i = 1; i <= n; i++)
//        cin >> a, t[a] = true;
//    for (int i = 1; i <= N; i++)
//        if (t[i]) cout << i << ' ';
//
//
//    return 0;
//}

/*��������*/
/* https://www.acwing.com/problem/content/description/3534/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
////�������Ĵ�Ȩ·������Ϊ �ڵ�������ϵĺ� �� ��
//
//const int N = 1009;
//
//vector<int> p;
//int sum, Sum;
//int a, n;
//
//int cmp(int a, int b)
//{
//    return a > b;
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> a, p.push_back(a);
//    sort(p.begin(), p.end(), cmp);
//
//    while (p.size() > 1)//���һ��Ϊ���ڵ㣬����Ϊ0
//    {
//        sum = p[p.size() - 1] + p[p.size() - 2];
//        Sum += sum;
//
//        p.pop_back(), p.pop_back();
//
//        p.push_back(sum);
//        sort(p.begin(), p.end(), cmp);
//    }
//
//
//    cout << Sum;
//    return 0;
//}

/*��ֵת��*/
/* https://www.acwing.com/problem/content/3441/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//char num[16] = { '0', '1', '2', '3', '4', '5','6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//int a, b;
//string n;
//string m;
//
//int sum, rem, quo;
//
//int main()
//{
//    cin >> a >> n >> b;
//
//    //ת����ʮ����
//    for (int i = 0; i < n.size(); i++)
//    {
//        if (n[i] >= 'a')
//            sum = sum * a + (n[i] - 'a' + 10);
//        else if (n[i] >= 'A')
//            sum = sum * a + (n[i] - 'A' + 10);
//        else
//            sum = sum * a + (n[i] - '0');
//    }
//    //����-ת����b����
//    while (sum)
//    {
//        m += num[sum % b];
//        sum /= b;
//    }
//
//    //����
//    reverse(m.begin(), m.end());
//
//
//    cout << m;
//
//    return 0;
//}

/*��ˮ����*/
/* https://www.acwing.com/problem/content/3514/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_set>
//
//using namespace std;
//
//const long long X = 10000;
//unordered_set <int> ans;//C��״̬
//unordered_set <long long> wat;//ACB��״̬
//int C[3];
//
//long long getVal(int c[])
//{
//    return c[2] * X * X + c[1] * X + c[0];
//}
//void pour(int t[], int i, int j)
//{
//    int v = min(t[i], C[j] - t[j]);
//    t[i] -= v, t[j] += v;
//}
//void dfs(int c[])
//{
//    ans.insert(c[2]); wat.insert(getVal(c));
//
//    int t[3];//�ݹ�ʱ������һ���������� �ڴ���ҪС�� ��ʼ����ֵ
//    for (int i = 0; i < 3; i++)
//        for (int j = 0; j < 3; j++)
//            if (i != j)
//            {
//                memcpy(t, c, sizeof(t));
//                pour(t, i, j);
//                if (!wat.count(getVal(t)))//��״̬δ���֣��ݹ�
//                    dfs(t);
//            }
//}
//
//int main()
//{
//    while (cin >> C[0] >> C[1] >> C[2])
//    {
//        ans.clear(); wat.clear();
//        int c[3] = { 0, 0, C[2] };//ˮ������� C������
//        dfs(c);
//        cout << ans.size() << endl;
//    }
//
//    return 0;
//}