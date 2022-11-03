#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>

using namespace std;

#define x first 
#define y second 

namespace myAVL
{

	template<typename K, typename V>
	struct AVLNode
	{
		typedef pair<K, V> KV;//typedef ֻ�ܸ�ȷ�������� �� ������������ �������

		KV _kv;
		int _bf;
		struct AVLNode<K, V>* _left;
		struct AVLNode<K, V>* _right;
		struct AVLNode<K, V>* _parent;

		AVLNode(const KV& kv)
			:_kv(kv)
			, _bf(0)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
		{}
	};

	template<typename K, typename V>
	struct AVL
	{
	public:
		typedef pair<K, V> KV;
		typedef AVLNode<K, V> Node;

		AVL()
			:_root(nullptr)
			, _size(0)
		{}
		AVL(const AVL<K, V>& AVL)
		{
			_root = _myCopy(AVL._root);
			_size = AVL._size;
		}
		AVL<K, V>& operator= (AVL<K, V> avl)//�β�����������ģ� �ں�������ʱ������
		{
			swap(_root, avl._root);
			swap(_size, avl._size);

			return (*this);
		}
		~AVL()
		{
			_Destory(_root);
		}

		bool insert(const KV& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
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
			while (parent)
			{
				//1. ����ƽ�����ӣ� ����Ҽ�
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else
				{
					parent->_bf--;
				}

				//2. �ж��Ƿ���ת
				if (parent->_bf == 0)// �� 1 �� -1 ��� 0�� ����߶Ȳ��䣬 �������ϸ���
				{
					break;
				}
				else if(abs(parent->_bf) == 1)//�� 0 ��� 1 �� -1���߶ȱ仯�� ���ϸ���
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
				else if (abs(parent->_bf) == 2)//����1�� ��ƽ�⣬ ��Ҫ��ת
				{
					if (parent->_bf == 2 && cur->_bf == 1)//��������������
					{
						RotateL(parent);
					}
					else if ((parent->_bf == -2 && cur->_bf == -1))//��������������
					{
						RotateR(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)//��������������
					{
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)//��������������
					{
						RotateRL(parent);
					}
					else
					{
						assert(false);
					}

					break;//��ת��õ�����parent��bfΪ0����ֱ�ӽ���������Ҫ���ϸ���
				}
				else
				{
					assert(false);
				}
			}

			return true;

		}


		AVLNode<const K, V>* find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_kv.x == key)
				{
					return (AVLNode<const K, V>*)cur;
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
		AVLNode<const K, V>* findR(const K& key)
		{
			return _findR(_root, key);
		}

		void inorder()
		{
			_inorderR(_root);
			cout << endl;
		}

		size_t size()
		{
			return _size;
		}

		bool IsBalance()
		{
			return _IsBalance(_root);
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
		AVLNode<const K, V>* _findR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_kv.x == key)
			{
				return (AVLNode<const K, V>*)root;
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

			parent->_bf = 0;
			subR->_bf = 0;
			
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

			parent->_bf = 0;
			subL->_bf = 0;

		}
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			RotateL(subL);
			RotateR(parent);

			subLR->_bf = 0;//�µĸ��ڵ�

			// ����ƽ������
			if (bf == 0)//subLRΪҶ�ӽڵ�
			{
				parent->_bf = 0;
				subL->_bf = 0;
			}
			else if (bf == 1)
			{
				parent->_bf = 0;
				subL->_bf = -1;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subL->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			int bf = subRL->_bf;

			RotateR(subR);
			RotateL(parent);

			subRL->_bf = 0;//�µ�parent

			// ����ƽ������
			if (bf == 0)//subRLΪҶ�ӽڵ�
			{
			parent->_bf = 0;
			subR->_bf = 0;
			}
			else if (bf == 1)
			{
				subR->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == -1)
			{
				subR->_bf = 1;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}

		}

		bool _IsBalance(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}

			int leftHT = Height(root->_left);
			int rightHT = Height(root->_right);
			int diff = rightHT - leftHT;

			// �ж����������߶Ȳ��Ƿ�� bf ���
			if (diff != root->_bf)
			{
				cout << root->_kv.first << "ƽ�������쳣" << endl;
				return false;
			}

			return abs(diff) < 2//bf < 2
				&& _IsBalance(root->_left)//������������AVLTree
				&& _IsBalance(root->_right);
		}
		int Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			return max(Height(root->_left), Height(root->_right)) + 1;
		}

	private:
		size_t _size;
		Node* _root = nullptr;
	};

	void TestAVLTree1()
	{
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };  // ����˫��ƽ�����ӵ���
		//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		AVL<int, int> t1;
		for (auto e : a)
		{
			t1.insert(make_pair(e, e));
		}

		t1.inorder();
		cout << "IsBalance:" << t1.IsBalance() << endl;
	}
	void TestAVLTree2()
	{
		size_t N = 10000;
		srand(time(0));
		AVL<int, int> t1;
		for (size_t i = 0; i < N; ++i)
		{
			int x = rand();
			t1.insert(make_pair(x, i));
			/*	bool ret = t1.IsBalance();
				if (ret == false)
				{
					int u = 1;
				}
				else
				{
					cout << "Insert:" << x << " IsBalance:" <<ret<< endl;
				}*/
		}
		cout << "IsBalance:" << t1.IsBalance() << endl;
	}
}



