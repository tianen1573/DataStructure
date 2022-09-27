#define _CRT_SECURE_NO_WARNINGS 1

#include "CirDoublyLinkList.h"


//申请节点
ListNode* BuyListNode(LTDataType elem)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode != NULL)
	{
		newnode->_data = elem;
		newnode->_next = newnode;
		newnode->_prev = newnode;
		return newnode;
	}

	assert(newnode);
}

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* phead = BuyListNode(0);

	return phead;
	//Buy时, 已经验证节点合法
}
// 双向链表销毁
void ListDestory(ListNode** pHead)
{
	ListNode* cur = (*pHead)->_next;
	ListNode* next = cur->_next;
	while (cur != *pHead)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	free(*pHead);
	*pHead = NULL;

}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	newNode->_prev = pos->_prev;
	pos->_prev = newNode;
	newNode->_next = pos;
	newNode->_prev->_next = newNode;
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	/*ListNode* newNode = BuyListNode(x);
	ListNode* ptail = pHead->_prev;
	ptail->_next = newNode;
	newNode->_prev = ptail;
	pHead->_prev = newNode;
	newNode->_next = pHead;*/

	ListInsert(pHead, x);

}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	/*ListNode* NewPtail = pHead->_prev->_prev;
	free(NewPtail->_next);
	NewPtail->_next = pHead;
	pHead->_prev = NewPtail;*/

	ListErase(pHead->_prev);

}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	/*ListNode* newNode = BuyListNode(x);
	ListNode* pHNext = pHead->_next;
	pHNext->_prev = newNode;
	newNode->_next = pHNext;
	pHead->_next = newNode;
	newNode->_prev = pHead;*/

	ListInsert(pHead->_next, x);

}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	
	/*ListNode* PHNext = pHead->_next;
	pHead->_next = PHNext->_next;
	pHead->_next->_prev = pHead;
	free(PHNext);*/

	ListErase(pHead->_next);

}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x) return cur;

		cur = cur->_next;
	}

	return NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}