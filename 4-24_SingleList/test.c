#define _CRT_SECURE_NO_WARNINGS 1

//#include"SingleList.h"
//
//void test1()
//{
//	SList* psl = NULL;
//
//	SLPushBack(&psl, 0);
//	SLPushBack(&psl, 1);
//	SLPushBack(&psl, 2);
//	SLPushBack(&psl, 3);
//
//	SLPrint(psl);
//
//	SLPopBack(&psl);
//	SLPopBack(&psl);
//	SLPopBack(&psl);
//	SLPopBack(&psl);
//
//	SLPrint(psl);
//
//}
//void test2()
//{
//	SList* psl = NULL;
//
//	SLPushFront(&psl, 0);
//	SLPushFront(&psl, 1);
//	SLPushFront(&psl, 2);
//	SLPushFront(&psl, 3);
//	SLPushFront(&psl, 4);
//
//	SLPrint(psl);
//
//	SLPopFront(&psl);
//	SLPopFront(&psl);
//	SLPopFront(&psl);
//	SLPopFront(&psl);
//	SLPopFront(&psl);
//
//	SLPrint(psl);
//
//}
//void test3()
//{
//	SList* psl = NULL;
//
//	//�����ַΪNULL������ͷ��
//	SLInsertAfter(&psl, NULL, -1);
//	SLPushFront(&psl, 0);
//	SLPushFront(&psl, 1);
//	SLPushFront(&psl, 2);
//	SLPushFront(&psl, 3);
//	SLPushFront(&psl, 4);
//	SLPrint(psl);
//	//��2�������һ��5
//	SLInsertAfter(&psl, SLFind(psl, 2), 5);
//	SLPrint(psl);
//	//ɾ��3
//	SLEraseAfter(&psl, SLFind(psl, 3));
//	SLPrint(psl);
//	//�޸�5Ϊ2
//	SLModify(&psl, SLFind(psl, 5), 2);
//	SLPrint(psl);
//
//}
//void test4()
//{
//	SList* psl = NULL;
//
//	SLPushFront(&psl, 0);
//	SLPushFront(&psl, 1);
//	SLPushFront(&psl, 2);
//	SLPushFront(&psl, 3);
//	SLPushFront(&psl, 4);
//	SLPrint(psl);
//
//	SLInsert(&psl, SLFind(psl, 3), 5);
//	SLPrint(psl);
//
//	SLInsertAfter(&psl, SLFind(psl, 5), 6);
//	SLPrint(psl);
//
//	SLErase(&psl, SLFind(psl, 5));
//	SLPrint(psl);
//
//	SLEraseAfter(&psl, SLFind(psl, 4));
//	SLPrint(psl);
//
//	SLDestory(&psl);
//	SLPrint(psl);
//
//}
//
//void menu()
//{
//	printf("****************************************************\n");
//	printf("*******1. PushBack        2. PopBack ***************\n");
//	printf("*******3. PushFront       4. PopFront **************\n");
//	printf("*******5. Insert          6. Erase *****************\n");
//	printf("*******7. InsAfter        8. EraAfter **************\n");
//	printf("*******9. Find            10. Modify ***************\n");
//	printf("*******11. Print          12. Destory **************\n");
//	printf("*******0. Exit                        **************\n");
//	printf("****************************************************\n");
//
//}
//
//void test()
//{
//	menu();
//
//	SList* psl = NULL;
//	int input = 0;
//	int elem = 0;
//	int tmp = 0;
//	SLNode pos = NULL;
//	
//
//	do
//	{
//		printf("\n��ѡ��>��\t");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case EXIT:
//			exit(0);
//		case PUSH_B:
//			printf("����������->: \t");
//			scanf("%d", &elem);
//			SLPushBack(&psl, elem);
//			break;
//		case POP_B:
//			SLPopBack(&psl);
//			break;
//		case PUSH_F:
//			printf("����������->: \t");
//			scanf("%d", &elem);
//			SLPushFront(&psl, elem);
//			break;
//		case POP_F:
//			SLPopFront(&psl);
//			break;
//		case INSERT:
//			printf("������ڵ����� �� �½ڵ�����->: \t");
//			scanf("%d %d", &tmp, &elem);
//			pos = SLFind(psl, tmp);
//			if (pos == NULL)
//			{
//				printf("û������ڵ㣡����\n");
//			}
//			else
//			{
//				
//				SLInsert(&psl, pos, elem);
//				printf("����ɹ�!!!\n");
//			}
//			break;
//		case ERASE:
//			printf("������ڵ�����->: \t");
//			scanf("%d", &elem);
//			pos = SLFind(psl, elem);
//			if (pos == NULL)
//			{
//				printf("û������ڵ㣡����\n");
//			}
//			else
//			{
//				SLErase(&psl, pos);
//				printf("ɾ���ɹ�������\n");
//			}
//			break;
//		case INSERT_AFTER:
//			printf("������ڵ����� �� �½ڵ�����->: \t");
//			scanf("%d %d", &tmp, &elem);
//			pos = SLFind(psl, tmp);
//			if (pos == NULL)
//			{
//				printf("û������ڵ㣡����\n");
//			}
//			else
//			{
//				SLInsertAfter(&psl, pos, elem);
//				printf("����ɹ�!!!\n");
//			}
//			break;
//		case ERASE_AFTER:
//			printf("������ڵ�����->: \t");
//			scanf("%d", &elem);
//			pos = SLFind(psl, elem);
//			if (pos == NULL)
//			{
//				printf("û������ڵ㣡����\n");
//			}
//			else
//			{
//				SLEraseAfter(&psl, pos);
//				printf("ɾ���ɹ�������\n");
//			}
//			break;
//		case FIND:
//			printf("������ڵ�����->: \t");
//			scanf("%d", &elem);
//			pos = SLFind(psl, elem);
//			if (pos == NULL)
//			{
//				printf("û������ڵ㣡����\n");
//			}
//			else
//			{
//				printf("�ڵ��ַΪ��%0x", pos);
//			}
//			break;
//		case MODIFY:
//			printf("������ �ڵ����� �� �޸�����->: \t");
//			scanf("%d %d", &tmp, &elem);
//			pos = SLFind(psl, tmp);
//			if (pos == NULL)
//			{
//				printf("û������ڵ㣡����\n");
//			}
//			else
//			{
//				SLModify(&psl, pos, elem);
//				printf("�޸ĳɹ�������\n");
//			}
//			break;
//		case PRINT:
//			SLPrint(psl);
//			break;
//		case DESTORY:
//			SLDestory(&psl);
//			printf("���ٳɹ�������\n");
//			break;
//		default:
//			printf("������ѡ�񣡣���\n");
//			break;
//		}
//	} while (input);
//
//
//}
//
//
//int main()
//{
//	test();
//
//	return 0;
//}


#include"CirDoublyLinkList.h"


void test1()
{
	ListNode* pHead = BuyListNode(0);
	//ͷ��
	ListPushBack(pHead, 1);ListPushBack(pHead, 2);ListPushBack(pHead, 3);ListPushBack(pHead, 4);
	ListPrint(pHead);
	//β��
	ListPushFront(pHead, 2);ListPushFront(pHead, 3);ListPushFront(pHead, 4);
	ListPrint(pHead);

	//ͷɾ
	ListPopBack(pHead);ListPopBack(pHead);ListPopBack(pHead);
	ListPrint(pHead);
	//βɾ
	ListPopFront(pHead);ListPopFront(pHead);ListPopFront(pHead);
	ListPrint(pHead);
	//ָ��posǰ����
	ListInsert(ListFind(pHead, 1), 2);ListInsert(ListFind(pHead, 1), 4);ListInsert(ListFind(pHead, 1), 6);ListInsert(ListFind(pHead, 1), 8);
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