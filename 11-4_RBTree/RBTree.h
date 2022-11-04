#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
#include<set>

using namespace std;

#define x first 
#define y second 

namespace myRBT
{
	enum Colour
	{
		RED,
		BLACK
	};

	template<typename K, typename V>
	struct RBTNode
	{
		typedef pair<K, V> KV;//typedef ֻ�ܸ�ȷ�������� �� ������������ �������

		KV _kv;
		Colour _colour;
		struct RBTNode<K, V>* _left;
		struct RBTNode<K, V>* _right;
		struct RBTNode<K, V>* _parent;

		RBTNode(const KV& kv)
			:_kv(kv)
			, _colour(RED)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
		{}
	};

	template<typename K, typename V>
	struct RBT
	{
	public:
		typedef pair<K, V> KV;
		typedef RBTNode<K, V> Node;

		RBT()
			:_root(nullptr)
			, _size(0)
		{}
		RBT(const RBT<K, V>& RBT)
		{
			_root = _myCopy(RBT._root);
			_size = RBT._size;
		}
		RBT<K, V>& operator= (RBT<K, V> avl)//�β�����������ģ� �ں�������ʱ������
		{
			swap(_root, avl._root);
			swap(_size, avl._size);

			return (*this);
		}
		~RBT()
		{
			_Destory(_root);
		}

		bool insert(const KV& kv)
		{
			_size++;

			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_colour = BLACK;
				return true;
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur)
			{

				if (kv.x > cur->_kv.x)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kv.x < cur->_kv.x)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			//��ʼ���½ڵ�
			cur = new Node(kv);
			cur->_parent = parent;
			if (kv.x > parent->_kv.x)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			//����ƽ��
			//���״��ڣ� ����Ϊ��ɫ,���Ϻ����; ����Ϊ��ɫ�����е���
			//���ײ����ڣ���Ϊ���ڵ㣬ֻ��������ڵ����ɫ
			while (parent && parent->_colour == RED)
			{
				Node* grandfat = parent->_parent;
				assert(grandfat);//��Ϊ���ڵ�Ϊ��ɫ�� ����һ����һ����ɫ���ڵ�
				assert(grandfat->_colour == BLACK);

				//�������ұ�
				if (parent == grandfat->_left)
				{
					Node* uncle = grandfat->_right;
					//1. ������ڣ� ������Ϊ��ɫ
					//�� �����׺������Ϊ��ɫ��үү��ɺ�ɫ���������ϵ���
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//�� cur = grandfat, �������ϴ���
						cur = grandfat;
						parent = cur->_parent;
					}
					//���岻���ڣ��������������Ϊ��ɫ
					//�� ��Ҫ��ת����ɫ
					else
					{
						if (cur == parent->_left)
						{
							// 2. ��������������
							//    g
							//  p   u
							//c
							//үү�ڵ�����������ڣ�����
							RotateR(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. ��������������
							//      g
							//  p       u
							//    c
							//���׽ڵ�������үү�ڵ��������Լ���ڣ�����
							RotateL(parent);
							RotateR(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// ��������Ϻ����
					}
				}
				else//���������
				{
					Node* uncle = grandfat->_left;
					//1. ������ڣ� ������Ϊ��ɫ
					//�� �����׺������Ϊ��ɫ��үү��ɺ�ɫ���������ϵ���
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//�� cur = grandfat, �������ϴ���
						cur = grandfat;
						parent = cur->_parent;
					}
					//���岻���ڣ��������������Ϊ��ɫ
					//�� ��Ҫ��ת����ɫ
					else
					{
						if (cur == parent->_right)
						{
							// 3. ��������������
							//    g
							//  u   p
							//        c
							//үү�ڵ�����������ڣ�����
							RotateL(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. ��������������
							//      g
							//  u       p
							//        c
							//���׽ڵ�������үү�ڵ��������Լ���ڣ�����
							RotateR(parent);
							RotateL(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// ��������Ϻ����
					}
				}

			}

			_root->_colour = BLACK;//���ڵ�һ��Ϊ��ɫ

			return true;

		}


		RBTNode<const K, V>* find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_kv.x == key)
				{
					return (RBTNode<const K, V>*)cur;
				}
				else if (key > cur->_kv.x)
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
			}

			return nullptr;
		}
		RBTNode<const K, V>* findR(const K& key)
		{
			return _findR(_root, key);
		}

		void inorder()
		{
			_inorderR(_root);
			cout << endl;
		}

		// ��ȡ����������ڵ�
		RBTNode<const K, V>* LeftMost()
		{
			if (_root == nullptr)
			{
				return (RBTNode<const K, V>*)false;
			}
			else return _LeftMost(_root);
		}
		// ��ȡ��������Ҳ�ڵ�
		RBTNode<const K, V>* RightMost()
		{
			if (_root == nullptr)
			{
				return (RBTNode<const K, V>*)nullptr;
			}
			else
			{
				return _RightMost(_root);
			}
		}

		size_t size()
		{
			return _size;
		}


		bool IsBalance()
		{
			if (_root == nullptr)
			{
				return true;
			}

			if (_root->_colour == RED)
			{
				cout << "���ڵ����ɫΪ��ɫ�� Υ������" << endl;
				return true;
			}

			// ��ɫ�ڵ�������׼ֵ
			int benchmark = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_colour == BLACK)
					++benchmark;

				cur = cur->_left;
			}

			return PrevCheck(_root, 0, benchmark);
		}



	private:
		Node* _myCopy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* cur = new Node(root->_kv);
			cur->_left = _myCopy(root->_left);
			cur->_right = _myCopy(root->_right);

			return cur;
		}
		void _Destory(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Destory(root->_left);
			_Destory(root->_right);
			delete(root);
			root = nullptr;

			return;
		}

		//���ص���bool�� �޷�ͨ������ֵ�޸ĸ��ڵ�����Һ��ӣ�ʹ�����ã�ֱ���޸�ԭ�ڵ������
		RBTNode<const K, V>* _findR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_kv.x == key)
			{
				return (RBTNode<const K, V>*)root;
			}
			else if (key > root->_kv.x)
			{
				return _findR(root->_right, key);
			}
			else
			{
				return _findR(root->_left, key);
			}
		}
		void _inorderR(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			//�������Ϊ����
			_inorderR(root->_left);
			cout << root->_kv.x << " : " << root->_kv.y << ' ';
			_inorderR(root->_right);

			return;
		}
		// ��ȡ����������ڵ�
		RBTNode<const K, V>* _LeftMost(Node* root)
		{
			if (root->_left == nullptr)
			{
				return (RBTNode<const K, V>*)root;
			}
			else
			{
				return _LeftMost(root->_left);
			}
		}
		// ��ȡ��������Ҳ�ڵ�
		RBTNode<const K, V>* _RightMost(Node* root)
		{
			if (root->_right == nullptr)
			{
				return (RBTNode<const K, V>*)root;
			}
			else
			{
				return _RightMost(root->_right);
			}
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;//�������ڵ��������
			Node* subRL = subR->_left;//��������������

			parent->_right = subRL;//1. ������������ɸ��ڵ��������
			if (subRL)
			{
				subRL->_parent = parent;//2. �������������ĸ��ڵ�
			}

			Node* Pparent = parent->_parent;//��¼���ڵ�ĸ��ڵ�

			subR->_left = parent;//3. �����ڵ���subR��������
			parent->_parent = subR;//4. �����丸�ڵ�

			if (_root == parent)//����Ǹ��ڵ�
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				subR->_parent = Pparent;// 5. �������ڵ�
				//���ڵ���������
				if (Pparent->_left == parent)
				{
					Pparent->_left = subR;// 6. 

				}
				else
				{
					Pparent->_right = subR;// 6. 
				}
			}


		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}

			Node* Pparent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;

			if (_root == parent)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				subL->_parent = Pparent;
				if (Pparent->_left == parent)
				{
					Pparent->_left = subL;
				}
				else
				{
					Pparent->_right = subL;
				}
			}

		}
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;

			RotateL(subL);
			RotateR(parent);

		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;

			RotateR(subR);
			RotateL(parent);

		}

		bool PrevCheck(Node* root, int blackNum, int& benchmark)
		{
			if (root == nullptr)
			{

				if (blackNum != benchmark)
				{
					cout << "ĳ��·���ĺ�ɫ�ڵ�����������" << endl;
					return false;
				}
				else
				{
					return true;
				}
			}

			if (root->_colour == BLACK)
			{
				++blackNum;
			}

			if (root->_colour == RED && root->_parent->_colour == RED)
			{
				cout << "���������ĺ�ɫ�ڵ�" << endl;
				return false;
			}

			return PrevCheck(root->_left, blackNum, benchmark)
				&& PrevCheck(root->_right, blackNum, benchmark);
		}

	private:
		size_t _size;
		Node* _root = nullptr;
	};

	void TestRBTree1()
	{
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 0,5,30,25,20,4,13,30,28,27 };  // ����˫��ƽ�����ӵ���
		//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		RBT<int, int> t1;
		for (auto e : a)
		{
			t1.insert(make_pair(e, e));
		}

		t1.inorder();
		cout << "IsBalance:" << t1.IsBalance() << endl;
	}

	void TestRBTree2()
	{
		size_t N = 1000;
		srand(time(0));
		RBT<int, int> t1;
		for (size_t i = 0; i < N; ++i)
		{
			int x = rand();
			cout << "Insert:" << x << ":" << i << endl;
			t1.insert(make_pair(x, i));
		}
		cout << "IsBalance:" << t1.IsBalance() << endl;
	}

	void TestRBTree3()
	{
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 0,5,30,25,20,4,13,30,28,27 };  // ����˫��ƽ�����ӵ���
		//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		RBT<int, int> t1;
		for (auto e : a)
		{
			t1.insert(make_pair(e, e));
		}

		t1.inorder();
		cout << "IsBalance:" << t1.IsBalance() << endl;

		myRBT::RBTNode<const int, int>* left = t1.LeftMost();
		auto right = t1.RightMost();

		cout << "leftMost : " << left->_kv.first << " : " << left->_kv.second << endl;
		cout << "rightMost : " << right->_kv.first << " : " << right->_kv.second << endl;

	}

}



