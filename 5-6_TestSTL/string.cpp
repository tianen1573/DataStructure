#define _CRT_SECURE_NO_WARNINGS 1

/*HJ1 字符串最后一个单词的长度*/
/* https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da */
//#include<stdlib.h>
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string str;
//    getline(cin, str);
//
//    int pos = str.rfind(' ') + 1;
//    int res = str.size() - pos;
//
//    cout << res << endl;
//
//    return 0;
//}

/*917. 仅仅反转字母*/
/* https://leetcode-cn.com/problems/reverse-only-letters/submissions/ */
//bool isEngAlphabet(char c)
//{
//    if ((c >= 'A' && c <= 'Z')
//        || (c >= 'a' && c <= 'z'))
//        return true;
//
//    return false;
//}
//class Solution {
//public:
//    string reverseOnlyLetters(string s) {
//
//
//
//        size_t begin = 0, end = s.size() - 1;
//
//        while (begin < end)
//        {
//            while (begin < end && !isEngAlphabet(s[begin]))
//                begin++;
//            while (begin < end && !isEngAlphabet(s[end]))
//                end--;
//
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//
//        return s;
//
//    }
//};

/*387. 字符串中的第一个唯一字符*/
/* https://leetcode-cn.com/problems/first-unique-character-in-a-string/ */
//class Solution {
//public:
//    int firstUniqChar(string s) {
//
//        int num[32] = { 0 };
//
//        for (char e : s)
//        {
//            num[e - 'a']++;
//        }
//
//        for (int cur = 0; cur < s.size(); cur++)
//        {
//            if (num[s[cur] - 'a'] == 1)
//                return cur;
//        }
//
//
//        return -1;
//    }
//};

/*125. 验证回文串*/
/* https://leetcode-cn.com/problems/valid-palindrome/ */



//#include <string>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
////string str = "abcdefg";
////
////int main()
////{
////	string str1;
////	string str2(7, 'a');
////	string str3(str);
////	string str4(str, 0, 5);
////	string str5(str, 2, 5);
////	string str6(str.begin(), str.end());
////
////	printf("%s\n", str.c_str());
////	printf("%s\n", str1.c_str());
////	printf("%s\n", str2.c_str());
////	printf("%s\n", str3.c_str());
////	printf("%s\n", str4.c_str());
////	printf("%s\n", str5.c_str());
////	printf("%s\n", str6.c_str());
////
////
////
////	return 0;
////}
////#include<string>
////#include<iostream>
////#include<algorithm>
//
//string str[10];
//int pos;
//
//int main()
//{
//	str[0] = "abcdef";
//	str[1] = "aabc";
//	str[2] = "affasdad";
//	str[3] = "aa";
//
//	size_t len_str = 4;
//	for (int i = 0; i < len_str; i++)
//	{
//		if (str[i].find("aa") == 0 && str[i].size() == 2)
//		{
//			pos = i;
//			break;
//		}
//	}
//
//	cout << pos << endl;
//
//	return 0;
//}

//bool isEngAlphabet(char c)
//{
//    if ((c >= 'a' && c <= 'z')
//        || (c >= '0' && c <= '9'))
//        return true;
//
//    return false;
//}
//class Solution {
//public:
//    bool isPalindrome(string s) {
//
//        for (char& c : s)
//        {
//            if (c >= 'A' && c <= 'Z')
//                c += 32;
//        }
//        int begin = 0, end = s.size() - 1;
//
//        while (begin < end)
//        {
//            while (begin < end && !isEngAlphabet(s[begin]))
//                begin++;
//            while (begin < end && !isEngAlphabet(s[end]))
//                end--;
//
//            if (s[begin] == s[end])
//            {
//                begin++;
//                end--;
//            }
//            else
//                return false;
//
//        }
//
//        return true;
//    }
//};
//
//int main()
//{
//
//    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
//
//    return 0;
//}

//string str = "abcdefgh";
//
//int main()
//{
//	for (auto& e : str) printf("%c ", e);
//	cout << endl;
//
//	for (auto it = str.begin(); it != str.end(); it++) printf("%c ", *it);
//	cout << endl;
//
//	for (auto it = str.rbegin(); it != str.rend(); it++) printf("%c ", *it);
//	cout << endl;
//
//	for (auto i = 0; i < str.size(); i++) printf("%c ", str[i]);
//	cout << endl;
//
//	for (auto i = 0; i < str.size(); i++) printf("%c ", str.at(i));
//	cout << endl;
//
//	auto it_begin = str.begin();
//
//	printf("%c\n", it_begin + 3);
//
//	return 0;
//}