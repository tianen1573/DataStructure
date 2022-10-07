#define _CRT_SECURE_NO_WARNINGS 1

#include "CirDoublyLinkList.h"


//����ڵ�
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

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* phead = BuyListNode(0);

	return phead;
	//Buyʱ, �Ѿ���֤�ڵ�Ϸ�
}
// ˫����������
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

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	newNode->_prev = pos->_prev;
	pos->_prev = newNode;
	newNode->_next = pos;
	newNode->_prev->_next = newNode;
}

// ˫������β��
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
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	/*ListNode* NewPtail = pHead->_prev->_prev;
	free(NewPtail->_next);
	NewPtail->_next = pHead;
	pHead->_prev = NewPtail;*/

	ListErase(pHead->_prev);

}
// ˫������ͷ��
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
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	
	/*ListNode* PHNext = pHead->_next;
	pHead->_next = PHNext->_next;
	pHead->_next->_prev = pHead;
	free(PHNext);*/

	ListErase(pHead->_next);

}

// ˫���������
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
// ˫�������ӡ
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