#define _CRT_SECURE_NO_WARNINGS 1

/*77˫����*/

/*6051. ͳ���Ǹ����ַ���ǰ׺���ַ�����Ŀ*/
/* https://leetcode-cn.com/contest/biweekly-contest-77/problems/count-prefixes-of-a-given-string/ */
//int countPrefixes(char** words, int wordsSize, char* s) {
//    int count = 0;
//
//    for (int i = 0; i < wordsSize; i++)
//    {
//        char* pw = words[i];
//        char* ps = s;
//        while (*pw && *ps)
//        {
//            if (*pw == *ps)
//            {
//                pw++;
//                ps++;
//            }
//            else
//            {
//                break;
//            }
//        }
//
//        if (*pw == 0)
//            count++;
//
//    }
//    return count;
//
//}

/*6052. ��Сƽ����*/
/* https://leetcode-cn.com/contest/biweekly-contest-77/problems/minimum-average-difference/ */
//int minimumAverageDifference(int* nums, int numsSize) {
//
//    long* sum = (long*)malloc(numsSize * sizeof(long));
//	  //���⴦���һ����
//    sum[0] = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        sum[i] = sum[i - 1] + nums[i];
//    }
//
//	  //���⴦�����Ϊ0��Ԫ�صķ���
//    long min = (int)(sum[numsSize - 1] / numsSize);
//    int pos = numsSize - 1;
//
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        int ave = 0;
//        ave = abs((int)(sum[i] / (i + 1)) - (int)((sum[numsSize - 1] - sum[i]) / (numsSize - i - 1)));
//
//        if (ave <= min)
//        {
//            pos = i;
//            min = ave;
//        }
//    }
//
//    return pos;
//
//}



/*291����*/
/* https://leetcode-cn.com/contest/weekly-contest-291/ */
/*��*/



/*2260. �����������С����������*/
/* https://leetcode-cn.com/problems/minimum-consecutive-cards-to-pick-up/ */
//class Solution {
//public:
//    int minimumCardPickup(vector<int>& cards)
//    {
//
//        map<int, int> MAP;
//        int res = INT_MAX;
//        for (int i = 0; i < cards.size(); i++)
//        {
//            if (MAP.count(cards[i]))
//                res = min(res, i - MAP[cards[i]] + 1);
//            // res = min(res,i - map[cards[i]] + 1)
//            MAP[cards[i]] = i;
//        }
//
//        return res == INT_MAX ? -1 : res;
//
//    }
//};

/*2259. �Ƴ�ָ�����ֵõ��������*/
/* https://leetcode-cn.com/problems/remove-digit-from-number-to-maximize-result/comments/ */
//class Solution {
//public:
//    string removeDigit(string number, char digit)
//    {
//        string ans;
//
//        for (int i = 0; i < number.size(); i++)
//        {
//            if (number[i] == digit)
//                ans = max(number.substr(0, i) + number.substr(i + 1, number.size() - 1), ans);
//        }
//
//        return ans;
//    }
//};