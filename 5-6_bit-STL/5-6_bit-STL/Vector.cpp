#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> vecI = { 1,3,5,7,2,4,6,8 };
vector<char> vecCh = { 'a','c','e','g','b','d','f' };

int my_cmp(int a, int b)
{
	return a > b;
}

int main()
{
	auto posI = find(vecI.begin(), vecI.end(), 5);

	cout << posI - vecI.begin() << endl;
	cout << "front :" << vecI.front() << endl;
	cout << "back :" << vecI.back() << endl;

	vector<int> vecI2;
	vecI2.push_back(1);
	vecI2.push_back(3);
	vecI2.push_back(2);
	vecI2.push_back(4);
	vecI2.push_back(5);
	vecI2.insert(vecI2.begin(), 9);
	vecI2.insert(vecI2.begin(), vecI.begin(), vecI.begin() + 3);
	cout << vecI2.front() << endl;

	sort(vecI2.begin(), vecI2.end(), greater<int>());
	//reverse(vecI2.begin(), vecI2.end());

	for (auto e : vecI2) cout << e << " ";




}