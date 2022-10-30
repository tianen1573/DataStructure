#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    bool flag = true;
    cin >> str1 >> str2;

    int tmp = 1 << 5;

    int _p1 = 0, _p2 = 0;
    while (_p1 < str1.size() && _p2 < str2.size())
    {
        if ((str1[_p1] == '?' && isalnum(str2[_p2]))
            || ((str1[_p1] | tmp) == (str2[_p2] | tmp)))
        {
            ++_p1;
            ++_p2;
        }
        else if (str1[_p1] == '*')
        {
            while (_p1 < str1.size() && (str1[_p1] == '*' || str1[_p1] == '?'))
            {
                ++_p1;
            }
            if (_p1 == str1.size())
            {
                _p1 = str1.size();
                _p2 = str2.size();
            }
            while (_p2 < str2.size() && ((str1[_p1] | tmp) != (str2[_p2] | tmp)))
            {
                ++_p2;
            }
            if (_p2 == str2.size())
            {
                flag = false;
                _p1 = str1.size();
                _p2 = str2.size();
            }
            else
            {
                ++_p1;
                ++_p2;
            }
        }
        else
        {
            flag = false;
            _p1 = str1.size();
            _p2 = str2.size();
        }
    }
    if (_p1 != str1.size() || _p2 != str2.size())
    {
        flag = false;
    }

    cout << (flag ? "true" : "false");

    return 0;
}