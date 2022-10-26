#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	assert(a && pi);
	
	if (a[*pi] == '#')
	{
		return NULL;
	}

	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc err");
		exit(1);
	}
	node->_data = a[*pi];
	
	++(*pi);
	if (*pi < n)
	{
		node->_left = BinaryTreeCreate(a, n, pi);
	}
	++(*pi);
	if (*pi < n)
	{
		node->_right = BinaryTreeCreate(a, n, pi);
	}
		

	return node;

}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	assert(root);

	if (*root == NULL)
	{
		return;
	}

	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));

	free(*root);
	*root = NULL;

}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (!root->_left && !root->_right)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);

	
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(root);

	queue<BTNode*> que;
	que.push(root);

	for (int i = 1; i < k; ++i)
	{
		int _size = que.size();
		for (int j = 0; j < _size; ++j)
		{
			BTNode* cur = que.front();
			que.pop();

			if (cur->_left)
			{
				que.push(cur->_left);
			}
			if (cur->_right)
			{
				que.push(cur->_right);
			}
		}
	}

	return que.size();

}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%c ", root->_data);

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);

}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);

	queue<BTNode*> que;
	que.push(root);

	while(!que.empty())
	{
		BTNode* cur = que.front();
		que.pop();

		if (cur)
		{
			printf("%c ", cur->_data);
			que.push(cur->_left);
			que.push(cur->_right);
		}
		else
		{
			printf("# ");
		}
		
	}

}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	assert(root);

	queue<BTNode*> que;
	BTNode* cur = root;

	while (cur)
	{
		
		que.push(cur->_left);
		que.push(cur->_right);
		cur = que.front();que.pop();

	}

	while (!que.empty())
	{
		cur = que.front();
		que.pop();

		if (cur)
		{
			return false;
		}
	}

	return true;
}