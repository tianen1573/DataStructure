#define _CRT_SECURE_NO_WARNINGS 1


#include"CirDoublyLinkList.h"


void test1()
{
	ListNode* pHead = BuyListNode(0);
	//ͷ��
	ListPushBack(pHead, 1); ListPushBack(pHead, 2); ListPushBack(pHead, 3); ListPushBack(pHead, 4);
	ListPrint(pHead);
	//β��
	ListPushFront(pHead, 2); ListPushFront(pHead, 3); ListPushFront(pHead, 4);
	ListPrint(pHead);

	//ͷɾ
	ListPopBack(pHead); ListPopBack(pHead); ListPopBack(pHead);
	ListPrint(pHead);
	//βɾ
	ListPopFront(pHead); ListPopFront(pHead); ListPopFront(pHead);
	ListPrint(pHead);
	//ָ��posǰ����
	ListInsert(ListFind(pHead, 1), 2); ListInsert(ListFind(pHead, 1), 4); ListInsert(ListFind(pHead, 1), 6); ListInsert(ListFind(pHead, 1), 8);
	ListPrint(pHead);
	//����ʧ��/ɾ��ʧ��
	int val = 3;
	ListNode* Valpos = ListFind(pHead, val);
	if (Valpos)
	{
		ListInsert(Valpos, val - 1);
		ListErase(Valpos);
	}
	else
		printf("%d ������\n", val);

	val = 4;
	Valpos = ListFind(pHead, val);
	if (Valpos)
	{
		ListInsert(Valpos, val - 1);
		ListErase(Valpos);
	}
	else
		printf("%d ������\n", val);

	ListPrint(pHead);

	//����
	ListDestory(&pHead);
	if (!pHead) printf("������\n");

}

int main()
{
	test1();

	return 0;
}