#define _CRT_SECURE_NO_WARNINGS 1

#include"BST.h"

#include"BST_KV.h"

void TestBSTree1()
{
	//using namespace _BST;
	_BST::BST<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
	for (auto e : a)
	{
		t.insert(e);
	}

	// 排序+去重
	t.inorder();

	t.erase(3);
	t.inorder();

	t.erase(8);
	t.inorder();
	for (auto e : a)
	{
		t.erase(e);
		t.inorder();
	}
}

void TestBSTree2()
{
	_BST::BST<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
	for (auto e : a)
	{
		t.insertR(e);
	}

	// 排序+去重
	t.inorder();

	t.eraseR(14);
	t.inorder();

	t.eraseR(8);
	t.inorder();

	for (auto e : a)
	{
		t.erase(e);
		t.inorder();
	}
}

void TestBSTree3()
{
	_BST::BST<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
	for (auto e : a)
	{
		t.insertR(e);
	}

	_BST::BST<int> copy = t;
	copy.inorder();
	t.inorder();

	_BST::BST<int> t1;
	t1.insert(2);
	t1.insert(1);
	t1.insert(3);

	copy = t1;
	copy.inorder();
	t1.inorder();

	_BST::BST<int> copyy(t);
	copyy.inorder();
}

void TestBSTree21()
{
	_BST_KV::BST<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });
	dict.insert({ "string", "字符串" });
	dict.insert({ "insert", "插入" });
	string str;
	while (cin >> str)
	{
		_BST_KV::BSTNode<const string, string>* ret = dict.findR(str);//对key值加上const属性， 禁止更改
		if (ret)
		{
			cout << "对应的中文:" << ret->_kv.second << endl;
		}
		else
		{
			cout << "对应的中文->无此单词" << endl;
		}
	}
}
void TestBSTree22()
{
	string arr[] = { "香蕉", "苹果", "香蕉", "草莓", "香蕉", "苹果", "苹果", "苹果" };

	_BST_KV::BST<string, int> countTree;
	for (auto& str : arr)
	{
		//_BST_KV::BSTNode<const string, int>* ret = countTree.find(str);
		auto ret = countTree.find(str);
		if (ret)
		{
			ret->_kv.second++;
		}
		else
		{
			countTree.insert({ str, 1 });
		}
	}

	countTree.inorder();
}

int main()
{
	//TestBSTree1();
	//TestBSTree2();
	//TestBSTree3();

	//TestBSTree21();
	TestBSTree22();



	return 0;
}



