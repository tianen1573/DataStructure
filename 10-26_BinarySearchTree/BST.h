#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>

using namespace std;

namespace _BST
{
	template<typename K>
	struct BSTNode
	{
		K _key;
		struct BSTNode<K>* _left;
		struct BSTNode<K>* _right;

		BSTNode (const K& key)
			:_key(key)
			,_left(nullptr)
			,_right(nullptr)
		{}
	};

	template<typename K>
	struct BST
	{
	public:

		typedef BSTNode<K> Node;
		BST ()
			:_root(nullptr)
			,_size(0)
		{}
		BST(const BST<K>& bst)
		{
			_root = _myCopy(bst._root);
			_size = bst._size;
		}
		BST<K>& operator= (BST<K> bst)//形参是深拷贝出来的， 在函数结束时会销毁
		{
			swap(_root, bst._root);
			swap(_size, bst._size);

			return (*this);
		}
		~BST()
		{
			_Destory(_root);
		}

		bool insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur)
			{
				
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (key > parent->_key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;

		}
		bool insertR(const K& key)
		{
			return _insertR(_root, key);
		}

		bool erase(const K& key)
		{
			Node* cur = _root;
			Node* pre = nullptr;

			while (cur)
			{

				if (key > cur->_key)
				{
					pre = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					pre = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)//1. 左为空
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
					else if (cur->_right == nullptr)//2. 左不空，右为空
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
					else//3. 左右都不空
					{
						Node* minRP = cur;
						Node* minR = cur->_right;
						while (minR->_left)
						{
							minRP = minR;
							minR = minR->_left;
						}

						swap(cur->_key, minR->_key);
						if (minRP->_left == minR)//1. 右子树 有左叶子节点， 放到pre的左边
						{
							minRP->_left = minR->_right;
						}
						else//2. 右子树 没有左叶子节点， 则cur->_right 就是最小节点， 放到pre的右边
						{
							minRP->_right = minR->_right;
						}
						delete minR;
					}
					return true;//存在
				}
			}

			return false;//不存在

		}
		bool eraseR(const K& key)
		{
			return _eraseR(_root, key);
		}

		bool find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key == key)
				{
					return true;
				}
				else if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
			}

			return false;
		}
		bool findR(const K& key)
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

			Node* cur = new Node(root->_key);
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

		//返回的是bool， 无法通过返回值修改父节点的左右孩子，使用引用，直接修改原节点的内容
		bool _insertR(Node*& root, const K& key) 
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (key > root->_key)
			{
				return _insertR(root->_right, key);
			}
			else if (key < root->_key)
			{
				return _insertR(root->_left, key);
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

			if (key > root->_key)
			{
				return _eraseR(root->_right, key);
			}
			else if (key < root->_key)
			{
				return _eraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)//1. 左为空
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)//2. 左不空，右为空
				{
					root = root->_left;
				}
				else//3. 左右都不空
				{
					Node* minR = root->_right;
					while (minR->_left)
					{
						minR = minR->_left;
					}

					swap(root->_key, minR->_key);
					//此时， _key值被转移到了右子树的最左边， 未删除， 仍需要删除这个节点
					//删除方法使用的是上述的 左为空
					return _eraseR(root->_right, key);
				}

				//如果是第一第二种情况， del为待删节点
				//如果是第三种情况， 此时del不再是待删节点， 但已经return了， 不会到达这个位置
				//可以把下2行语句， 写在前两种情况里面
				delete del;
				del = nullptr;
				return true;
			}

		}
		bool _findR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key == key)
			{
				return true;
			}
			else if (key > root->_key)
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

			//中序遍历为有序
			_inorderR(root->_left);
			cout << root->_key << ' ';
			_inorderR(root->_right);

			return;
		}

	private:
		size_t _size;
		Node* _root = nullptr;
	};
}

