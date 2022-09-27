#define _CRT_SECURE_NO_WARNINGS 1

/*��������*/
/* https://www.acwing.com/problem/content/1814/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int ax1, ax2, ay1, ay2;
//int bx1, bx2, by1, by2;
//
//int x1, x2, y1, y2;
//
//int main()
//{
//    cin >> ax1 >> ay1 >> ax2 >> ay2;
//    cin >> bx1 >> by1 >> bx2 >> by2;
//
//    x1 = min(ax1, bx1); y1 = min(ay1, by1);
//    x2 = max(ax2, bx2); y2 = max(ay2, by2);
//
//    int side = max(x2 - x1, y2 - y1);
//
//    cout << side * side;
//
//    return 0;
//}

/*�������һ����*/
/* https://www.acwing.com/problem/content/1802/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//#define x first
//#define y second
//
//typedef unordered_map<string, int> UMSI;
//UMSI m;
//vector<int> vec;
//
//int main()
//{
//    //��ʼ��
//    m["Bessie"] = 0;
//    m["Elsie"] = 0;
//    m["Daisy"] = 0;
//    m["Gertie"] = 0;
//    m["Annabelle"] = 0;
//    m["Maggie"] = 0;
//    m["Henrietta"] = 0;
//
//    //����
//    int n; cin >> n;
//    string a; int b;
//    while (n--) {
//        cin >> a >> b;
//        m[a] += b;
//    }
//    //������ת�Ƶ������У�������
//    for (auto mv : m)
//        vec.push_back(mv.y);
//    sort(vec.begin(), vec.end());
//
//    int nmin = vec[0], cnt = 0, i = 1;//����Сֵ������Сֵ����
//    //�Ҵ���Сֵ
//    for (; i < 7; i++)
//        if (vec[i] > vec[0])
//        {
//            nmin = vec[i];
//            break;
//        }
//    //��¼����
//    for (; i < 7; i++)
//        if (vec[i] == nmin)
//            cnt++;
//
//    //���
//    if (nmin == vec[0] || cnt > 1)
//        cout << "Tie";
//    else
//    {
//        for (auto mv : m)
//            if (mv.y == nmin)
//            {
//                cout << mv.x;
//                break;
//            }
//    }
//
//    return 0;
//}

/*ţΪʲô����·*/
/* https://www.acwing.com/problem/content/1790/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//bool one[11];//��¼��һ��λ��
//bool side[11];//��¼��n�ι۲�ǰ��λ��
//int ans;
//
//int n;
//
//int main()
//{
//    cin >> n;
//    int num; bool s;
//    while (n--)
//    {
//        cin >> num >> s;
//        if (!one[num]) one[num] = true, side[num] = s;
//        else if (side[num] != s) ans++, side[num] = s;
//    }
//
//    cout << ans;
//    return 0;
//}

/*��ʧ��ţ*/
/* https://www.acwing.com/problem/content/description/1777/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//int x, y;
//
//int main()
//{
//    cin >> x >> y;
//    int len = abs(x - y);
//
//    int i = 0;
//    for (i = 0; ; i++)
//    {
//        /*��ţ���λ�ò�ͬ��i����ֵ��ͬ*/
//        if ((y >= x) && (int)pow(2, i) >= len) break;
//        i++;
//        if ((x > y) && (int)pow(2, i) >= len) break;
//    }
//
//    int dis = 2 * (pow(2, i) - 1) + len;
//    cout << dis;
//
//    return 0;
//}

/*Χ��ˢ��*/
/* https://www.acwing.com/problem/content/description/1868/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int a, b, c, d;
//
//int main()
//{
//    cin >> a >> b >> c >> d;
//
//    int len = 0;
//
//    if (c > b || d < a) len = (b - a) + (d - c);//���غ�
//    else len = (max(a, max(b, max(c, d))) - min(a, min(b, min(c, d))));//�غ�
//
//    cout << len;
//
//    return 0;
//}

/*��������*/
/* https://www.acwing.com/problem/content/1856/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int p[4][2];
//
//int a, b, c;
//
//int main()
//{
//    for (int i = 0; i < 4; i++)
//        cin >> p[i][0] >> p[i][1];
//
//    c = p[3][1] - p[3][0];//�׽� �� - ǰ
//    b = p[2][1] - (p[2][0] - c);//��� - (��ǰ - ����) 
//    a = p[1][1] - (p[1][0] - b);//���� - (��ǰ - ����)
//
//    cout << a << endl << b << endl << c;
//
//    return 0;
//}