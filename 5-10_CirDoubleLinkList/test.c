#define _CRT_SECURE_NO_WARNINGS 1


#include"CirDoublyLinkList.h"


void test1()
{
	ListNode* pHead = BuyListNode(0);
	//头插
	ListPushBack(pHead, 1); ListPushBack(pHead, 2); ListPushBack(pHead, 3); ListPushBack(pHead, 4);
	ListPrint(pHead);
	//尾插
	ListPushFront(pHead, 2); ListPushFront(pHead, 3); ListPushFront(pHead, 4);
	ListPrint(pHead);

	//头删
	ListPopBack(pHead); ListPopBack(pHead); ListPopBack(pHead);
	ListPrint(pHead);
	//尾删
	ListPopFront(pHead); ListPopFront(pHead); ListPopFront(pHead);
	ListPrint(pHead);
	//指定pos前插入
	ListInsert(ListFind(pHead, 1), 2); ListInsert(ListFind(pHead, 1), 4); ListInsert(ListFind(pHead, 1), 6); ListInsert(ListFind(pHead, 1), 8);
	ListPrint(pHead);
	//插入失败/删除失败
	int val = 3;
	ListNode* Valpos = ListFind(pHead, val);
	if (Valpos)
	{
		ListInsert(Valpos, val - 1);
		ListErase(Valpos);
	}
	else
		printf("%d 不存在\n", val);

	val = 4;
	Valpos = ListFind(pHead, val);
	if (Valpos)
	{
		ListInsert(Valpos, val - 1);
		ListErase(Valpos);
	}
	else
		printf("%d 不存在\n", val);

	ListPrint(pHead);

	//销毁
	ListDestory(&pHead);
	if (!pHead) printf("已销毁\n");

}

int main()
{
	test1();

	return 0;
}