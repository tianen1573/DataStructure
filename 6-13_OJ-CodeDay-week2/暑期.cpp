#define _CRT_SECURE_NO_WARNINGS 1

/*����ϲ�*/
/* https://www.acwing.com/problem/content/4276/ */
//#include<string>
//#include<vector>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 100011;
//
//int val[N], ne[N];
//vector< pair<int, int> > a, b, c;
//
//int main()
//{
//	int h1, h2, n;
//	scanf("%d%d%d", &h1, &h2, &n);
//	int addr, data, next;
//	while (n--)
//	{
//		scanf("%d%d%d", &addr, &data, &next);
//		val[addr] = data, ne[addr] = next;
//	}
//	for (int i = h1; i != -1; i = ne[i]) a.push_back({ i, val[i] });
//	for (int i = h2; i != -1; i = ne[i]) b.push_back({ i, val[i] });
//
//	if (a.size() < b.size()) swap(a, b);
//
//	for (int i = 0, j = b.size() - 1; i < a.size(); i += 2)
//	{
//		printf("%05d %d ", a[i].first, a[i].second);//�����a1
//
//		if (i < a.size() - 1)//�ж��ܷ����a2
//		{
//			printf("%05d\n", a[i + 1].first);
//			printf("%05d %d ", a[i + 1].first, a[i + 1].second);
//			if (j >= 0)//�ж��ܷ����b1
//			{
//				printf("%05d\n", b[j].first);
//				printf("%05d %d ", b[j].first, b[j].second);
//
//				if (i < a.size() - 2) printf("%05d\n", a[i + 2].first);//�ж��ܷ������һ��a1
//				else printf("-1\n");
//				j--;
//			}
//			else if (i < a.size() - 2) printf("%05d\n", a[i + 2].first);//�ж��ܷ������һ��a1
//			else printf("-1\n");
//		}
//		else printf("-1\n");
//	}
//
//
//	return 0;
//}

/*��׺���ʽ*/
/* https://www.acwing.com/problem/content/4277/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 23;
//
//string d[N];//����
//int l[N], r[N];//�����ӽڵ�
//bool ir[N];//�Ƿ�Ϊ���ڵ�
//
//int n;
//
//string suffix(int rt)
//{
//    if (~l[rt] && ~r[rt]) return '(' + suffix(l[rt]) + suffix(r[rt]) + d[rt] + ')';//�����������
//    else if (~r[rt]) return '(' + d[rt] + suffix(r[rt]) + ')';//���к���
//    return '(' + d[rt] + ')';//��
//}
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)//�ڵ��Ŵ�1��ʼ
//    {
//        cin >> d[i] >> l[i] >> r[i];
//        //~(-1) = 0, ���� �Ͳ�Ϊ���ڵ�
//        if (~l[i]) ir[l[i]] = true;
//        if (~r[i]) ir[r[i]] = true;
//    }
//    int rt = 1;
//    while (ir[rt]) rt++;
//
//    cout << suffix(rt);
//
//    return 0;
//}

/*Dij����*/
/* https://www.acwing.com/problem/content/description/4278/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1011;
//
//int dist[N], g[N][N];
//int n, m, k, q[N];
//bool st[N];
//
//bool dij()
//{
//    memset(dist, 0x3f, sizeof dist);
//    memset(st, 0, sizeof st);
//
//    dist[q[0]] = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        int t = q[i];// ���� t ��
//        //δȷ������ĵ㣬����벻��С�� t �㣬����Ͳ��ܷ��� t ��
//        for (int j = 1; j <= n; j++)
//            if (!st[j] && dist[j] < dist[t])
//                return false;
//
//        st[t] = true;//ȷ�� t�� ����
//        //����δȷ������ĵ�
//        for (int j = 1; j <= n; j++)
//            dist[j] = min(dist[j], dist[t] + g[t][j]);
//    }
//
//}
//
//int main()
//{
//    cin >> n >> m;
//    memset(g, 0x3f, sizeof(g));
//    while (m--)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        g[a][b] = g[b][a] = c;
//    }
//
//    cin >> k;
//    while (k--)
//    {
//        for (int i = 0; i < n; i++) cin >> q[i];
//
//        if (dij()) puts("Yes");
//        else puts("No");
//    }
//
//    return 0;
//}