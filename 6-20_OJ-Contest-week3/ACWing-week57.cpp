#define _CRT_SECURE_NO_WARNINGS 1

/*57*/
/* https://www.acwing.com/activity/content/introduction/1974/ */

/*�ȴ�С*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int a, b, suma, sumb, n;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> a, suma += a;
//    for (int i = 0; i < n; i++)
//        cin >> b, sumb += b;
//
//    if (suma >= sumb) cout << "Yes";
//    else cout << "No";
//
//    return 0;
//}

/*���ֲ���*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//
//
//
//int main()
//{
//    int n; cin >> n;
//    int res = 1, cnt = 0;//min, cnt
//    vector<int> p;
//
//    /*�ֽ�������*/
//    for (int i = 2; i * i <= n; i++)
//    {
//        if (n % i == 0)
//        {
//            int c = 0;
//            while (n % i == 0) n /= i, c++;//ե��
//            p.push_back(c);//����
//            res *= i;//������Сֵ
//            while ((1 << cnt) < c) cnt++;//��������С����
//        }
//    }
//    if (n > 1)//�ж�����n�Ƿ�Ϊ������
//    {
//        res *= n;
//        p.push_back(1);
//        while ((1 << cnt) < 1) cnt++;
//    }
//
//    for (auto x : p)
//    {
//        if (x < (1 << cnt))
//        {
//            cnt++;
//            break;
//        }
//    }
//
//    cout << res << " " << cnt;
//    return 0;
//}

/*�����������*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
////(a(l + 1) + ... + ar) > 100 * (r + 1 - (l + 1)) 
////->> ((a(l + 1) - 100) + ... + (ar - 100)) + 100 *(r + 1 - (l + 1)) > 100 * (r + 1 - (l + 1))
////->>((a(l + 1) - 100) + ... + (ar - 100)) > 0 
////->> sum[r] > sum[l]�����ж�����Ϊsum[r] > sum[l]
////��ǰ׺�ͼ�Ϊһ�������ݼ����У������Ҷ˵�̶�ʱ���������� ���� ��һ��С���Ҷ˵�Ľڵ㼴��
////�ٽڵ�ǰ׺�ͱ�������СֵС����Ҫ���У���Ϊû�б�����С�Ľڵ㣬
////������������Сֵ����һ������һ���±����С���ڵ�ֵҲ����С�Ľڵ㣬����ڵ����Ҷ˵�ĳ���һ����������������
//
//typedef long long LL;
//
//const int N = 1000010;
//
//int n;
//LL s[N];//ǰ׺��
//int stk[N];
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        int x;
//        scanf("%d", &x);
//        s[i] = s[i - 1] + x - 100;//�Ż�ǰ׺��
//    }
//
//    int top = 0, res = 0;
//    stk[++top] = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if (s[stk[top]] > s[i]) stk[++top] = i;//�����
//        else if (s[stk[top]] < s[i])//�����
//        {
//            int l = 1, r = top;
//            while (l < r)
//            {
//                int mid = l + r >> 1;
//                if (s[stk[mid]] < s[i]) r = mid;
//                else l = mid + 1;
//            }
//            res = max(res, i - stk[r]);
//            //str[r]���������ڵ����һ���ڵ�de�±�
//            //stk[r] == (l + 1) - 1 -> i - stk[r] == i - (l + 1) + 1
//        }
//    }
//
//    printf("%d\n", res);
//    return 0;
//}

