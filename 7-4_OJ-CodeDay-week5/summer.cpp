#define _CRT_SECURE_NO_WARNINGS 1

/*������*/
/* https://www.acwing.com/problem/content/description/3540/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//const int N = 1007;
//
//int n, k, arr[N];
//bool lag;
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> arr[i];
//
//    cin >> k;
//
//    for (int p = (int)pow(2, k - 1); p <= min((int)pow(2, k) - 1, n); p++)
//        lag = true, cout << arr[p] << " ";
//
//    if (!lag) cout << "EMPTY";
//
//    return 0;
//
//}
////��ȫ��������k��ڵ�ı��Ϊ��[2^(k-1), 2^k - 1], �±��1��ʼ

/*������*/
/* https://www.acwing.com/problem/content/3567/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int md[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//int n;
//int y, m, d;
//
//int main()
//{
//    cin >> n;
//    while (n--)
//    {
//        cin >> y >> m >> d;
//
//        if (d + 1 > md[m] && m + 1 > 12) y++, m = d = 1;//����
//        else if (d + 1 > md[m]) m++, d = 1;//����
//        else d++;
//        printf("%04d-%02d-%02d\n", y, m, d);
//    }
//
//    return 0;
//}

/*�ݴη� -- ������*/
/* https://www.acwing.com/problem/content/description/3628/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int MOD = 233333;
//int x, n;
//
//int powMod(LL x, LL n)//long long ��ֹ����
//{
//    LL res = 1 % MOD;
//    while (n)
//    {
//        if (n & 1) res = res * x % MOD;
//        x = x * x % MOD;
//        n >>= 1;
//    }
//    return res % MOD;
//
//}
//
//int main()
//{
//    cin >> x >> n;
//
//    int res = powMod(x, n);
//
//    cout << res;
//
//    return 0;
//}
////x^c == x^a * x^b ����x^2a -> x^a * x^a ���� (x*x)^a
////����Ϊ���������ȥ��������ƽ������������

/*��ͨͼ*/
/* https://www.acwing.com/problem/content/3590/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
// /*����BFS*/
// const int N = 1009;
// bool map[N][N];
// bool sta[N];
// int n, m;
// int main()
// {
//     while(~scanf("%d%d", &n, &m))
//     {
//         memset(map, 0, sizeof(map));
//         memset(sta, 0, sizeof(sta));
//         int x, y;
//         while (m -- )
//         {
//             cin >> x >> y;
//             map[x][y] = map[y][x] = true;
//         }
//         queue<int> que;
//         que.push(1); sta[0] = sta[1] = true; 
//         while(que.size())
//         {
//             int h = que.front();
//             for(int i = 1; i <= n; i++)
//                 if(map[h][i] && !sta[i])
//                 {
//                     que.push(i);
//                     sta[i] = true;
//                 }
//             que.pop();
//         }
//         bool flag = true;
//         for(int i = 1; i <= n; i++)
//             if(!sta[i])
//                 {
//                     flag = false;
//                     break;
//                 }
//         if(flag) cout << "YES" << endl;
//         else cout << "NO" << endl;;
//     }
//    return 0;
//}
// /*���鼯*/
//
//const int N = 1009;
//
//int fat[N], cnt[N];
//
//int n, m;
//
//int find(int x)
//{
//    if (fat[x] != x) fat[x] = find(fat[x]);
//
//    return fat[x];
//}
//
//int main()
//{
//    while (cin >> n >> m)
//    {
//        memset(fat, 0, sizeof fat);
//        //memset(cnt, 1, sizeof cnt);
//
//        for (int i = 1; i <= n; i++) fat[i] = i, cnt[i] = 1;
//
//        int x, y;
//        while (m--)
//        {
//            cin >> x >> y;
//            if (find(x) != find(y))
//            {
//                fat[find(x)] = find(y);
//                cnt[find(y)] += cnt[find(x)];
//            }
//        }
//
//        if (cnt[find(1)] == n) cout << "YES" << endl;
//        else cout << "NO" << endl;
//
//    }
//
//    return 0;
//}

/*�ֻ�����*/
/* https://www.acwing.com/problem/content/3384/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int cnt[26] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3,1, 2, 3, 4 };
//
//char l, r;
//int ans;
//string str;
//
//int main()
//{
//    while (cin >> str)
//    {
//        ans = 0;
//        l = r = 'A';
//        for (auto x : str)
//        {
//            if (x >= l && x <= r) ans += 2;//���
//            ans += cnt[x - 'a'];
//            l = x - (cnt[x - 'a'] - 1);
//            r = l + 2;
//            if (l == 'p' || l == 'w') r++;
//        }
//
//        cout << ans << endl;
//    }
//
//    return 0;
//}

/*����������*/
/* https://www.acwing.com/problem/content/3601/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
////��kΪroot�����������λ��
////��ǰ������У�1��ʼ��k���ַ� ����������ǰ������� k + 1 ~ �� ��������
////��������У�0��ʼ��k���ַ��������������������k + 1 ~ �� ��������
//
//
//void dfs(string pre, string in)
//{
//    if (pre.empty()) return;//ǰ�������һ��Ϊ���ڵ�
//
//    char root = pre[0];
//    int k = in.find(root);
//
//    dfs(pre.substr(1, k), in.substr(0, k));//����������
//    dfs(pre.substr(k + 1), in.substr(k + 1));//����������
//
//    cout << root;
//}
//
//int main()
//{
//    string pre, in;
//
//    while (cin >> pre >> in)
//    {
//        dfs(pre, in);
//
//        cout << endl;
//    }
//
//    return 0;
//}