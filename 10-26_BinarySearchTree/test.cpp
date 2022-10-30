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

	// ����+ȥ��
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

	// ����+ȥ��
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
	dict.insert({ "sort", "����" });
	dict.insert({ "left", "���" });
	dict.insert({ "right", "�ұ�" });
	dict.insert({ "string", "�ַ���" });
	dict.insert({ "insert", "����" });
	string str;
	while (cin >> str)
	{
		_BST_KV::BSTNode<const string, string>* ret = dict.findR(str);//��keyֵ����const���ԣ� ��ֹ����
		if (ret)
		{
			cout << "��Ӧ������:" << ret->_kv.second << endl;
		}
		else
		{
			cout << "��Ӧ������->�޴˵���" << endl;
		}
	}
}
void TestBSTree22()
{
	string arr[] = { "�㽶", "ƻ��", "�㽶", "��ݮ", "�㽶", "ƻ��", "ƻ��", "ƻ��" };

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



