#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"

int main()
{

	
	char arr[] = "ABD##E##CF##G##";
	int i = 0;
	BTNode* bt = BinaryTreeCreate(arr, strlen(arr), &i);

	/*BinaryTreePrevOrder(bt); 
	printf("\n");
	BinaryTreeInOrder(bt);
	printf("\n");
	BinaryTreePostOrder(bt);
	printf("\n");*/
	BinaryTreeLevelOrder(bt);
	printf("\n");

	//BinaryTreeDestory(&bt);

	//printf("\n%d", BinaryTreeSize(bt));

	//printf("\n%d", BinaryTreeLeafSize(bt));

	//printf("\n%d ", BinaryTreeLevelKSize(bt, 2));

	if (BinaryTreeComplete(bt))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}


	return 0;
}