#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define x first 
#define y second 

namespace _BST_KV
{
	
	template<typename K, typename V>
	struct BSTNode
	{
		typedef pair<K, V> KV;//typedef ֻ�ܸ�ȷ�������� �� ������������ �������

		KV _kv;
		struct BSTNode<K, V>* _left;
		struct BSTNode<K, V>* _right;

		BSTNode(const KV& kv)
			:_kv(kv)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<typename K, typename V>
	struct BST
	{
	public:
		typedef pair<K, V> KV;
		typedef BSTNode<K, V> Node;

		BST()
			:_root(nullptr)
			, _size(0)
		{}
		BST(const BST<K, V>& bst)
		{
			_root = _myCopy(bst._root);
			_size = bst._size;
		}
		BST<K, V>& operator= (BST<K, V> bst)//�β�����������ģ� �ں�������ʱ������
		{
			swap(_root, bst._root);
			swap(_size, bst._size);

			return (*this);
		}
		~BST()
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

			cur = new Node(kv);
			if (kv.x > parent->_kv.x)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;

		}
		bool insertR(const KV& kv)
		{
			return _insertR(_root, kv);
		}

		bool erase(const K& key)
		{
			Node* cur = _root;
			Node* pre = nullptr;

			while (cur)
			{

				if (key > cur->_kv.x)
				{
					pre = cur;
					cur = cur->_right;
				}
				else if (key < cur->_kv.x)
				{
					pre = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)//1. ��Ϊ��
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == pre->_left)
							{
								pre->_left = cur->_right;
							}
							else
							{
								pre->_right = cur->_right;
							}
						}

						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr)//2. �󲻿գ���Ϊ��
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == pre->_left)
							{
								pre->_left = cur->_left;
							}
							else
							{
								pre->_right = cur->_left;
							}
						}
					}
					else//3. ���Ҷ�����
					{
						//������������С�ڵ��滻����ǰ�ڵ�
						Node* minRP = cur;
						Node* minR = cur->_right;
						while (minR->_left)
						{
							minRP = minR;
							minR = minR->_left;
						}

						swap(cur->_kv, minR->_kv);
						if (minRP->_left == minR)//1. ������ ����Ҷ�ӽڵ㣬 �ŵ�pre�����
						{
							minRP->_left = minR->_right;
						}
						else//2. ������ û����Ҷ�ӽڵ㣬 ��cur->_right ������С�ڵ㣬 �ŵ�pre���ұ�
						{
							minRP->_right = minR->_right;
						}
						delete minR;
					}
					return true;//����
				}
			}

			return false;//������

		}
		bool eraseR(const K& key)
		{
			return _eraseR(_root, key);
		}

		BSTNode<const K, V>* find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_kv.x == key)
				{
					return (BSTNode<const K, V>*)cur;
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
		BSTNode<const K, V>* findR(const K& key)
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
		bool _insertR(Node*& root, const KV& kv)
		{
			if (root == nullptr)
			{
				root = new Node(kv);
				return true;
			}

			if (kv.x > root->_kv.x)
			{
				return _insertR(root->_right, kv);
			}
			else if (kv.x < root->_kv.x)
			{
				return _insertR(root->_left, kv);
			}
			else
			{
				return false;
			}
		}
		bool _eraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (key > root->_kv.x)
			{
				return _eraseR(root->_right, key);
			}
			else if (key < root->_kv.x)
			{
				return _eraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)//1. ��Ϊ��
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)//2. �󲻿գ���Ϊ��
				{
					root = root->_left;
				}
				else//3. ���Ҷ�����
				{
					Node* minR = root->_right;
					while (minR->_left)
					{
						minR = minR->_left;
					}

					swap(root->_kv, minR->_kv);
					//��ʱ�� _keyֵ��ת�Ƶ���������������ߣ� δɾ���� ����Ҫɾ������ڵ�
					//ɾ������ʹ�õ��������� ��Ϊ��
					return _eraseR(root->_right, key);
				}

				//����ǵ�һ�ڶ�������� delΪ��ɾ�ڵ�
				//����ǵ���������� ��ʱdel�����Ǵ�ɾ�ڵ㣬 ���Ѿ�return�ˣ� ���ᵽ�����λ��
				//���԰���2����䣬 д��ǰ�����������
				delete del;
				del = nullptr;
			}

		}
		BSTNode<const K, V>* _findR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_kv.x == key)
			{
				return (BSTNode<const K, V>*)root;
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

	private:
		size_t _size;
		Node* _root = nullptr;
	};
}


