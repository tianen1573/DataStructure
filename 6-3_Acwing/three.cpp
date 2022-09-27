#define _CRT_SECURE_NO_WARNINGS 1

/*�߾��ȼӼ��˳�*/

/*��*/
/* https://www.acwing.com/problem/content/793/ */
//#include<string>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string strA, strB;
//
//void sum()
//{
//    int carry = 0;
//    int i = 0;
//
//    for (; i < strA.size() && i < strB.size(); i++)
//    {
//        int a = strA[i] - '0', b = strB[i] - '0';
//        strA[i] = (a + b + carry) % 10 + '0';
//        carry = (a + b + carry) / 10;
//    }
//    //A��
//    while (i < strA.size())
//    {
//        int a = strA[i] - '0';
//        strA[i] = (a + carry) % 10 + '0';
//        carry = (a + carry) / 10;
//        i++;
//    }
//    //B��
//    while (i < strB.size())
//    {
//        int b = strB[i] - '0';
//        strA.push_back('0' + (b + carry) % 10 );
//        carry = (b + carry) / 10;
//        i++;
//    }
//    //�ж�����Ƿ���Ҫ��λ
//    if (carry == 1) strA.push_back('1');
//
//    return;
//}
//
//int main()
//{
//    cin >> strA >> strB;
//
//    reverse(strA.begin(), strA.end());
//    reverse(strB.begin(), strB.end());
//
//    sum();
//    reverse(strA.begin(), strA.end());
//
//    cout << strA;
//
//    return 0;
//}

/*��*/
/* https://www.acwing.com/problem/content/description/794/ */
//#include<string>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string strA, strB;
//
//bool cmp(string& A, string& B)
//{
//    if (A.size() != B.size()) return A.size() > B.size();
//
//    for (int i = A.size() - 1; i >= 0; i--)//��λ->��λ
//        if (A[i] != B[i])
//            return A[i] > B[i];
//
//    return true;
//}
//
//void sub(string& A, string& B)
//{
//    int carry = 0;
//    int i = 0;
//
//    for (; i < A.size() && i < B.size(); i++)
//    {
//        int a = A[i] - '0', b = B[i] - '0';
//
//        A[i] = (a - b + carry + 10) % 10 + '0';
//
//        if (a - b + carry < 0) carry = -1;
//        else carry = 0;
//    }
//    //A��
//    while (i < A.size())
//    {
//        int a = A[i] - '0';
//        A[i] = (a + carry + 10) % 10 + '0';
//        if (a + carry < 0) carry = -1;
//        else carry = 0;
//        i++;
//    }
//
//    //�ж����λ�Ƿ�Ϊ0
//    while (A.size() > 1 && A.back() == '0') A.pop_back();
//    return;
//}
//
//int main()
//{
//
//    cin >> strA >> strB;
//
//
//    reverse(strA.begin(), strA.end());
//    reverse(strB.begin(), strB.end());
//
//    if (cmp(strA, strB) == false)//������ȽϺ�compare�Ƚ� ---����
//    {
//        sub(strB, strA);
//        strA = strB;
//        strA.push_back('-');
//    }
//    else sub(strA, strB);
//
//    reverse(strA.begin(), strA.end());
//
//    cout << strA;
//
//    return 0;
//}
//
// /*
// * compare �� ������Ƚ� �������ְ��ֵ���Ƚϣ��޷��жϳ�������
// */
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//string a = "abc";
//string b = "bc";
//
//int main()
//{
//	cout << a.compare(b) << endl;
//	cout << (a > b);
//
//	return 0;
//}

/*��*/
/* https://www.acwing.com/problem/content/795/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//
//using namespace std;
//
//string A;
//int b;
//
//void mul()
//{
//    unsigned carry = 0;
//
//    for (int i = 0; i < A.size(); i++)
//    {
//        int a = A[i] - '0';
//        A[i] = (a * b + carry) % 10 + '0';
//        carry = (a * b + carry) / 10;
//    }
//
//    while (carry > 0)//ʣ���λ
//    {
//        A.push_back(carry % 10 + '0');
//        carry /= 10;
//    }
//
//}
//int main()
//{
//    cin >> A >> b;
//
//    if (b == 0 || A[0] == '0')//�ж��Ƿ��� 0
//    {
//        cout << "0";
//        return 0;
//    }
//
//    reverse(A.begin(), A.end());
//    mul();
//    reverse(A.begin(), A.end());
//
//    cout << A;
//
//    return 0;
//}

/*��*/
/* https://www.acwing.com/problem/content/796/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//string A;
//int b, rem;
//
//void div()
//{
//    for (int i = 0; i < A.size(); i++)
//    {
//        int a = A[i] - '0';
//        A[i] = (a + rem * 10) / b + '0';
//        rem = (a + rem * 10) % b;
//    }
//
//    /*
//    û��ͷɾ�����ú�βɾ
//    */
//    reverse(A.begin(), A.end());
//    while (A.size() > 1 && A.back() == '0') A.pop_back();
//    reverse(A.begin(), A.end());
//}
//
//int main()
//{
//
//    cin >> A >> b;
//
//    div();
//
//    cout << A << endl << rem;
//
//}