#define _CRT_SECURE_NO_WARNINGS 1

/*�����������*/
/* https://www.acwing.com/problem/content/4482/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_set>
//using namespace std;
//
//unordered_set<int> b;
//int a[11];
//int n, m;
//int main()
//{
//    int tmp = 0;
//    scanf("%d%d", &n, &m);
//
//    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", &tmp);
//        b.insert(tmp);
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (b.count(a[i])) cout << a[i] << " ";
//
//    return 0;
//}

/*������*/
/* https://www.acwing.com/problem/content/description/4483/ */
////��STLʱ�䳬�ޣ���Ҫ��һ��������Ᵽ������Ͱ�±꣬��������ʱ��
////O(n + m)
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//typedef pair<bool, int> PBI;
//
//map<int, PBI> que;//���꣬��ʶ������
//vector<int> ash;
//
//int n, m;
//
//int main()
//{
//    int tmp = 0;
//    scanf("%d%d", &n, &m);
//    //������Ϣ
//    for (int i = 0; i < n + m; i++)
//    {
//        scanf("%d", &tmp);
//        que.insert({ tmp, {false, 0} });
//    }
//    //��ʶ����Ͱ������������Ͱ�±�
//    for (auto& it : que)
//    {
//        scanf("%d", &tmp);
//        if (tmp == 1)
//        {
//            it.second.first = true;
//            ash.push_back(it.first);
//        }
//    }
//    //��ʼ��������Ͱ���±�
//    int rig = ash[0], left = ash[0];//��������Ͱ�±�
//    int ashPos = 1, lag = 0;
//
//    for (auto it = que.begin(); it != que.end(); it++)
//    {
//        if (it->second.first == false)//����
//        {
//            while (ashPos < ash.size() && rig < it->first) rig = ash[ashPos++];//����������Ͱ
//
//            //������������ֵ������룬��Ϊ��������ȫ�Ǿ���������Ͱ�޷����µ����
//            if (abs(it->first - left) > abs(rig - it->first)) que[rig].second++;
//            else que[left].second++;
//        }
//        else //����������Ͱ������ӡ����������
//        {
//            if (lag == 1) cout << que[left].second << " ";//�ӵڶ�������Ͱ��ʼ����ӡ��ǰһ��
//            left = it->first;
//            lag = 1;
//        }
//    }
//
//    //��ӡ���һ������Ͱ
//    auto it = que.end(); it--;
//    cout << que[left].second;
//
//    return 0;
//}