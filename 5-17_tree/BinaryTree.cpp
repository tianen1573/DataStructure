#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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
// ����������
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
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	
}
// ������Ҷ�ӽڵ����
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
// ��������k��ڵ����
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
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
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
// �������������
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
// �������������
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
// �������
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
// �ж϶������Ƿ�����ȫ������
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