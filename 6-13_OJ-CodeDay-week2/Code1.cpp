#define _CRT_SECURE_NO_WARNINGS 1

/*���ʴ�����*/
/* https://www.acwing.com/problem/content/1444/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//string str[107];
//int N, K;
//
//int main()
//{
//    cin >> N >> K;
//    int curLen = 0;
//    for (int i = 1; i <= N; i++) cin >> str[i];
//
//    for (int i = 1; i <= N; )
//    {
//        if (curLen + str[i].size() <= K)//��ǰ�г���curLen + ���ʳ��� <= K�����,������Ϣ
//        {
//            if (curLen != 0) cout << " ";
//            cout << str[i];
//            curLen += str[i].size();
//            i++;
//        }
//        else//>= K, ����
//        {
//            cout << endl;
//            curLen = 0;
//        }
//    }
//
//    return 0;
//}

/*������*/
/*https://www.acwing.com/problem/content/1673/*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//#define x first
//#define y second
//
//using namespace std;
//
//typedef pair<int, int> PII;
//PII pos[107];
//int N;
//
//int main()
//{
//    cin >> N;
//    for (int i = 1; i <= N; i++) cin >> pos[i].x >> pos[i].y;
//
//    int area = 0;
//    for (int i = 1; i <= N; i++)
//        for (int j = 1; j <= N; j++)
//            for (int k = 1; k <= N; k++)
//            {
//                if (i == j || i == k || j == k) continue;
//                /*��iģ��Ϊֱ�ǵ㣬j��kΪ������ǵ�*/
//                if ((pos[i].x == pos[j].x) && (pos[i].y == pos[k].y))
//                    area = max(area, abs((pos[i].y - pos[j].y) * (pos[i].x - pos[k].x)));
//            }
//
//    cout << area;
//}

/*�罻����*/
/* https://www.acwing.com/problem/content/1661/ */
// /*#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//
//int max_1 = 0, max_2 = 0, D = 1e5 + 11;
//string str;
//char c, hc, tc;
//int N;
//
//int main()
//{
//    cin >> N;
//    cin >> str;
//
//    int count = 0;
//    int h_len = (int)str.find('1') - 0;//��һ��1�ı�
//    int t_len = N - 1 - (int)str.rfind('1');//���һ��1���±�
//
//    if (str.find('1') == -1)//������1
//    {
//        printf("%d", N - 1);
//        return 0;
//    }
//    //�ӵ�һ�� 1 �� ���һ�� 1����¼�������max_1���δ�����max_2����С���D
//    for (int i = (int)str.find('1') + 1; i <= (int)str.rfind('1'); i++)//�ӵ�һ��1�ĺ�һλ��ʼ������D��ʼΪ0
//    {
//        if (str[i] == '0') count++;
//        else
//        {
//            if (count + 1 >= max_1)
//            {
//                max_2 = max_1;
//                max_1 = count + 1;
//            }
//            else if (count + 1 > max_2) max_2 = count + 1;
//
//            D = min(D, count + 1);
//            count = 0;
//        }
//    }
//
//    int d = 0;//��¼�����������������
//
//    d = max(d, max_1 / 3);//2��ţ�嵽һ������
//    d = max(d, max_2 / 2);//�嵽��������
//
//    if (h_len && t_len)//��ͷβ��ûţ���嵽��ͷ��β
//    {
//        d = max(d, min(h_len, t_len));
//    }
//    if (h_len)//�嵽��ͷ
//    {
//        int  max_11 = max(max_1, h_len);//�����������
//        d = max(d, min(h_len, max_11 / 2));
//    }
//    if (t_len)//�嵽��β
//    {
//        int max_11 = max(max_1, t_len);
//        d = max(d, min(t_len, max_11 / 2));
//    }
//
//    D = min(D, d);//������С���
//    cout << D;
//
//    return 0;
//}*/
//
// /*y��*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 100010;
//
//int n, m;
//char str[N];
//int p[N];
//
//int main()
//{
//    scanf("%d%s", &n, str + 1);
//    for (int i = 1; i <= n; i++)
//        if (str[i] == '1')
//            p[++m] = i;
//
//    if (!m) printf("%d\n", n - 1);
//    else
//    {
//        int xmin = N;
//        for (int i = 1; i < m; i++)
//            xmin = min(xmin, p[i + 1] - p[i]);
//
//        int y = max((p[1] - 1) / 2, (n - p[m]) / 2);
//        for (int i = 1; i < m; i++)
//            y = max(y, (p[i + 1] - p[i]) / 3);
//
//        int y1 = p[1] - 1, y2 = n - p[m];
//        if (y1 < y2) swap(y1, y2);
//        for (int i = 1; i < m; i++)
//        {
//            int d = (p[i + 1] - p[i]) / 2;
//            if (d >= y1) y2 = y1, y1 = d;
//            else if (d > y2) y2 = d;
//        }
//        printf("%d\n", min(xmin, max(y, y2)));
//    }
//
//    return 0;
//}

/*���ţ��*/
/* https://www.acwing.com/problem/content/1716/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int c[3], m[3];
//
//int main()
//{
//    for (int i = 0; i < 3; i++)
//        cin >> c[i] >> m[i];
//
//    for (int i = 0; i < 100; i++)
//    {
//        int a = i % 3, b = (i + 1) % 3;
//        int ml = min(m[a], c[b] - m[b]);
//        m[a] -= ml, m[b] += ml;
//    }
//
//    cout << m[0] << endl;
//    cout << m[1] << endl;
//    cout << m[2] << endl;
//
//    return 0;
//}

/*������Ϸ*/
/* https://www.acwing.com/problem/content/1697/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
///* ģ�⣺O(m * n) */
//int ans[3][4];
//
//int n;
//
//int main()
//{
//
//    ans[0][1] = ans[1][2] = ans[2][3] = 1;//��ʼ���� 1��2��3 ���������ʯͷ
//    cin >> n;
//
//    while (n--) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        for (int i = 0; i < 3; i++)
//        {
//            swap(ans[i][a], ans[i][b]);
//            if (ans[i][c]) ans[i][0]++;
//        }
//    }
//
//    int Ans = max(ans[0][0], max(ans[1][0], ans[2][0]));
//
//    cout << Ans;
//
//    return 0;
//}
// /*�Ż���O(n), ����һ��������ͬλ�ü����ͬһ�ֲ���������λ�ò����ص���ֱ���Ҳ²�λ��������һ�����
//int n, x[4], ans[4];
//int main()
//{
//    for (int i = 1; i <= 3; i++) x[i] = i;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        swap(x[a], x[b]);
//        ans[x[c]]++;
//    }
//    cout << max({ans[1], ans[2], ans[3]});
//    return 0;
//}*/
