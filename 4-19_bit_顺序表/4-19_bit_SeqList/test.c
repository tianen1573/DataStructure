#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void menu()
{
	printf("***************SeqList***************\n");
	printf("***** 1.Insert         2.Delete******\n");
	printf("***** 3.PushBack       4.PopBack*****\n");
	printf("***** 5.PushFront      6.PopFront****\n");
	printf("***** 7.FindVal        8.ModifyVal***\n");
	printf("***** 9.Sort          10.SLSize******\n");
	printf("*****11.Clear         12.PRINT*******\n");
	printf("***** 0.EXIT                  *******\n");
	printf("*************************************\n");
}

void test()
{
	menu();

	//初始化
	SL sl;
	SLInit(&sl);

	int input = 0, pos = -1;
	int elem = 0;
	
	do
	{
		printf("\n请选择->：\t");
		scanf("%d", &input);
		switch (input)
		{
		case INSERT:
			printf("请输入数据和插入下标->:\t");
			scanf("%d %d", &elem, &pos);
			SLInsert(&sl, pos, elem);
			break;
		case DELETE:
			printf("请输入删除的元素->:\t");
			scanf("%d", &elem);
			pos = SLFindVal(&sl, elem);
			if (pos == -1)
				printf("没有此元素\n");
			else
			{
				int x = 0;
				printf("1. 删除第一个数值为%d的元素\n", elem);
				printf("2. 删除所有数值为%d的元素\n", elem);
				printf("请选择->: \t");

				scanf("%d", &x);
				if(x == 1)
					SLDelete(&sl, pos);
				else
				{
					while ((pos = SLFindVal(&sl, elem)) != -1)
						SLDelete(&sl, pos);
				}
			}
			
			break;
		case PushB:
			printf("请输入数据, 0 代表结束尾插->:\t");
			do
			{
				scanf("%d", &elem);
				//getchar();
				if (elem != 0)
					SLPushBack(&sl, elem);
			} while (elem);
			break;
		case PopB:
			SLPopBack(&sl);
			break;
		case PushF:
			printf("请输入数据, 0 代表结束头插->:\t");
			do
			{
				scanf("%d", &elem);
				//getchar();
				if(elem != 0)
					SLPushFront(&sl, elem);
			} while (elem);
			break;
		case PopF:
			SLPopFront(&sl);
			break;
		case FIND:
			printf("请输入查找的数据->:\t");
			scanf("%d", &elem);
			pos = SLFindVal(&sl, elem);
			if (pos == -1)
				printf("没有此元素\n");
			else
			{
				printf("第一个数值为 %d 的元素的下标为: %d\n", elem, pos);
				int begin = 0;
				printf("数值为 %d 的所有的元素的下标:  ", elem);
				while (begin < sl.size)
				{
					if (sl.data[begin] == elem)
						printf("%-4d", begin);
					begin++;
				}
			}
				
			break;
		case MODIFY:
			printf("请输入修改的元素的下标和新值->:\t");
			scanf("%d %d", &pos, &elem);
			SLModifyVal(&sl, pos, elem);
			break;
		case SORT:
			SLSort(&sl);
			break;
		case SIZE:
			printf("共 %d 个元素\n", sl.size);
			break;
		case CLEAR:
			SLClear(&sl);
			break;
		case PRINTF:
			SLPrint(&sl);
			break;
		case EXIT:
			printf("退出\n");
			break;
		default:
			printf("选择失败，请重新选择\n");
			break;
		}
	} while (input);
}

/*int main()
{
	test();

	return 0;
}*/