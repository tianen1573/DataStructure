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

	//��ʼ��
	SL sl;
	SLInit(&sl);

	int input = 0, pos = -1;
	int elem = 0;
	
	do
	{
		printf("\n��ѡ��->��\t");
		scanf("%d", &input);
		switch (input)
		{
		case INSERT:
			printf("���������ݺͲ����±�->:\t");
			scanf("%d %d", &elem, &pos);
			SLInsert(&sl, pos, elem);
			break;
		case DELETE:
			printf("������ɾ����Ԫ��->:\t");
			scanf("%d", &elem);
			pos = SLFindVal(&sl, elem);
			if (pos == -1)
				printf("û�д�Ԫ��\n");
			else
			{
				int x = 0;
				printf("1. ɾ����һ����ֵΪ%d��Ԫ��\n", elem);
				printf("2. ɾ��������ֵΪ%d��Ԫ��\n", elem);
				printf("��ѡ��->: \t");

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
			printf("����������, 0 �������β��->:\t");
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
			printf("����������, 0 �������ͷ��->:\t");
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
			printf("��������ҵ�����->:\t");
			scanf("%d", &elem);
			pos = SLFindVal(&sl, elem);
			if (pos == -1)
				printf("û�д�Ԫ��\n");
			else
			{
				printf("��һ����ֵΪ %d ��Ԫ�ص��±�Ϊ: %d\n", elem, pos);
				int begin = 0;
				printf("��ֵΪ %d �����е�Ԫ�ص��±�:  ", elem);
				while (begin < sl.size)
				{
					if (sl.data[begin] == elem)
						printf("%-4d", begin);
					begin++;
				}
			}
				
			break;
		case MODIFY:
			printf("�������޸ĵ�Ԫ�ص��±����ֵ->:\t");
			scanf("%d %d", &pos, &elem);
			SLModifyVal(&sl, pos, elem);
			break;
		case SORT:
			SLSort(&sl);
			break;
		case SIZE:
			printf("�� %d ��Ԫ��\n", sl.size);
			break;
		case CLEAR:
			SLClear(&sl);
			break;
		case PRINTF:
			SLPrint(&sl);
			break;
		case EXIT:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ��ʧ�ܣ�������ѡ��\n");
			break;
		}
	} while (input);
}

/*int main()
{
	test();

	return 0;
}*/