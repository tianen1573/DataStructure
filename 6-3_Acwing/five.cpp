#define _CRT_SECURE_NO_WARNINGS 1


/*��������ظ�������*/
/* https://www.acwing.com/problem/content/801/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int n;
//short c[N] = { 0 };
//int arr[N];
//int maxL = 1;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//
//    for (int i = 0, j = 0; i < n; i++)
//    {
//        c[arr[i]]++;
//        if (c[arr[i]] > 1)//ֵΪ2�������ظ�Ԫ��
//        {
//            while (j < i && c[arr[j]] != 2)//���ظ�Ԫ��λ��
//            {
//                c[arr[j]]--;
//                j++;
//            }
//            c[arr[j++]]--;
//        }
//        maxL = max(maxL, i - j + 1);//�������ֵ
//    }
//
//    cout << maxL;
//    return 0;
//}

/*����Ԫ�ص�Ŀ���*/
/* https://www.acwing.com/problem/content/802/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int n, m;
//int a[N], b[N];
//int res;
//long long x;
//
//int main()
//{
//    cin >> n >> m >> x;
//    for (int i = 0; i < n; i++) cin >> a[i];
//    for (int i = 0; i < m; i++) cin >> b[i];
//
//    int i = 0, j = m - 1;
//
//    while (i < n && j >= 0)
//    {
//        if ((long long)a[i] + b[j] == x)
//        {
//            cout << i << ' ' << j;
//            break;
//        }
//        else if ((long long)a[i] + b[j] > x) j--;
//        else i++;
//    }
//
//    return 0;
//}


/*�ж�������*/
/* https://www.acwing.com/problem/content/description/2818/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int n, m;
//int arr[N], brr[N];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//    for (int i = 0; i < m; i++) cin >> brr[i];
//
//    int i = 0, j = 0;
//    for (; i < m; i++)
//    {
//        if (brr[i] == arr[j]) j++;
//
//        if (j == n) break;
//    }
//
//    if (j == n) cout << "Yes";
//    else cout << "No";
//
//    return 0;
//}

/*��������1�ĸ���*/
/* https://www.acwing.com/problem/content/803/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int n, val;
//
//int main()
//{
//    cin >> n;
//
//    while (n--)
//    {
//        int ans = 0;
//        cin >> val;
//
//        while (val) val -= val & (-val), ans++;//val & -val ���Եõ����һ��1��β����ֵ
//
//        cout << ans << " ";
//    }
//
//    return 0;
//}

/*��ɢ��---�����*/
/* https://www.acwing.com/activity/content/problem/content/836/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//typedef pair<int, int> PII;
//const int N = 3e5 + 7;//n�����룬2m����ѯ
//
//int nums[N], sum[N];//Ԫ�����飬ǰ׺������
//
//vector<int> alls;//��ɢ�������±�Ͳ�ѯ�±�
//vector<PII> add, query;//������Ϣ����ѯ��Ϣ
//
//int n, m;
//
//int find(int x)
//{
//    int l = 0, r = alls.size() - 1;
//    while (l < r)
//    {
//        int mid = l + r >> 1;
//        if (alls[mid] >= x) r = mid;
//        else l = mid + 1;
//    }
//    return r + 1;
//}
//
//int main()
//{
//    cin >> n >> m;
//    //����������
//    for (int i = 0; i < n; i++)
//    {
//        int x, c; cin >> x >> c;
//
//        add.push_back({ x, c });//���������Ϣ
//        alls.push_back(x);//��������±�
//    }
//    //������Ҳ���
//    for (int i = 0; i < m; i++)
//    {
//        int l, r; cin >> l >> r;
//        query.push_back({ l, r });//�����ѯ��Ϣ
//        alls.push_back(l); alls.push_back(r);//�����ѯ�±�
//    }
//    //ȥ�أ���ɢ�������±�
//    sort(alls.begin(), alls.end());
//    alls.erase(unique(alls.begin(), alls.end()), alls.end());
//    //��ʱ�������±�Ψһ������alls�����������Լ���Ψһӳ�� --���±�
//
//    //��������
//    for (auto ait : add)
//    {
//        int x = find(ait.first);
//        nums[x] += ait.second;
//    }
//    //ǰ׺��
//    for (int i = 1; i <= alls.size(); i++) sum[i] = sum[i - 1] + nums[i];
//
//    //��ѯǰ׺��
//    for (auto qit : query)//qit��query��һ��Ԫ��
//    {
//        int l = find(qit.first), r = find(qit.second);
//        cout << sum[r] - sum[l - 1] << endl;
//    }
//    //for (vector<PII>::iterator qite = query.begin(); qite != query.end(); qite++)//qite��query�ĵ�����
//    //{
//    //    int l = find(qite->first), r = find(qite->second);
//    //    cout << sum[r] - sum[l - 1] << endl;
//    //}
//    //for (int i = 0; i < m; i++)//��0��ʼ
//    //{
//    //    int l = find(query[i].first), r = find(query[i].second);
//    //    cout << sum[r] - sum[l - 1] << endl;
//    //}
//    return 0;
//}


/*����Ͳ�*/
/* https://www.acwing.com/problem/content/805/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//typedef pair<int, int> PII;
//
//vector <PII> vec;
//
//int n, l, r, ans;
//
//void merge(vector<PII>& segs)//����������
//{
//    vector<PII> res;
//
//    sort(segs.begin(), segs.end());
//
//    int st = -2e9, ed = -2e9;
//    for (auto seg : segs)
//        if (ed < seg.first)
//        {
//            if (st != -2e9) res.push_back({ st, ed });//�Ƚ����䲻����
//            st = seg.first, ed = seg.second;
//        }
//        else ed = max(ed, seg.second);//�����Ҷ˵�
//
//    if (st != -2e9) res.push_back({ st, ed });
//
//    segs = res;
//}
//
//
//int main()
//{
//    cin >> n;
//
//    while (n--)
//    {
//        cin >> l >> r;
//        vec.push_back({ l, r });
//    }
//    sort(vec.begin(), vec.end());
//
//    int l = -1e9 - 7, r = -1e9 - 7;
//    for (int i = 0; i < vec.size(); i++)
//    {
//        if (vec[i].first <= r) //�ཻ
//            if (vec[i].second > r) r = vec[i].second;//���������Ҷ˵���󣬸����Ҷ˵�
//            else
//            {
//                l = vec[i].first; r = vec[i].second;//���ཻ���������Ҷ˵�
//                ans++;//���ཻ������������䣬ans++
//            }
//    }
//    cout << ans;
//    return 0;
//}

