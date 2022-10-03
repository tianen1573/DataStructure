#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

//����ڵ�
//slnode buylistnode(sldatatype elem)
//{
//	slnode newnode = (slnode)malloc(sizeof(slist));
//	if (newnode != null)
//	{
//		newnode->data = elem;
//		newnode->next = null;
//		return newnode;
//	}
//
//	assert(newnode);
//	return null;
//}

/*ͷ��ͷɾ*/
void SLPushBack(SList** pps, SLDataType elem)
{
	assert(pps);

	//������������
	if (*pps == NULL)
	{
		SLNode newnode = BuyListNode(elem);
		*pps = newnode;
	}
	//������
	else
	{
		SLNode tail = *pps;
		while (tail->next != NULL)
			tail = tail->next;

		SLNode newnode = BuyListNode(elem);
		tail->next = newnode;
	}
}
void SLPopBack(SList** pps)
{
	assert(pps && *pps);
	
	//���ֻ��һ���ڵ�
	if ((*pps)->next == NULL)
	{
		free(*pps);
		*pps = NULL;
	}
	else 
	{
		SLNode tailPrev = NULL;
		SLNode tail = *pps;
		while (tail->next != NULL)
		{
			tailPrev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		tailPrev->next = NULL;
	}
}
void SLPushFront(SList** pps, SLDataType elem)
{
	assert(pps);

	SLNode newnode = BuyListNode(elem);
	newnode->next = *pps;
	*pps = newnode;

}
void SLPopFront(SList** pps)
{
	assert(pps && *pps);

	SLNode begin = *pps;
	*pps = (*pps)->next;
	free(begin);
	begin = NULL;
}


/*��ָ���ڵ㣺���룬ɾ��*/
void SLInsert(SList** pps, SLNode pos, SLDataType elem)
{
	assert(pps);
	assert(pos);

	//�����ͷ�ڵ����
	if (pos == *pps)
	{
		SLNode newnode = BuyListNode(elem);

		newnode->next = *pps;
		*pps = newnode;
	}
	else
	{
		//1. �����ҽڵ�ĸ��ڵ�--O(n)
		//2. ����pos�ڵ���½ڵ��ֵ--O(1)
		//--1
		SLNode posPrve = *pps;
		SLNode newnode = BuyListNode(elem);
		while (posPrve->next != pos)
		{
			posPrve = posPrve->next;
		}
		newnode->next = pos;
		posPrve->next = newnode;

		//--2
		/*SLNode newnode = BuyListNode(pos->data);
		pos->data = elem;
		newnode->next = pos->next;
		pos->next = newnode;*/


	}

}
void SLErase(SList** pps, SLNode pos)
{
	assert(pps);
	assert(pos);
	assert(*pps);

	//���ɾ��ͷ�ڵ�
	if (pos == *pps)
	{
		SLNode tmp = (*pps)->next;
		free(*pps);
		*pps = tmp;
	}
	else
	{

		// ����pos�ڵ�ͺ�ڵ��ֵ--O(1)/O(n)--���һ���ڵ㲻�ܽ��������ֵ��ֻ�ܱ���
		if (pos->next != NULL)
		{
			SLNode del = pos->next;
			pos->data = del->data;
			pos->next = del->next;
			free(del);
			del = NULL;
		}
		else
		{
			SLNode posPrve = *pps;
			while (posPrve->next != pos)
			{
				posPrve = posPrve->next;
			}
			posPrve->next = pos->next;
			free(pos);
		}

	}
}
/*��ָ���ڵ�󣺲��룬ɾ��*/
void SLInsertAfter(SList** pps, SLNode pos, SLDataType elem)
{
	assert(pps);
	assert(pos);

	SLNode newnode = BuyListNode(elem);
	newnode->next = pos->next;
	pos->next = newnode;

}
void SLEraseAfter(SList** pps, SLNode pos)
{
	assert(pps && *pps && pos);
	//���һ���ڵ���治��ɾ��
	assert(pos->next);

	SLNode tmp = pos->next->next;
	pos->next->next = NULL;
	free(pos->next);
	pos->next = tmp;
	
}


//�޸�
void SLModify(SList** pps, SLNode pos, SLDataType elem)
{
	assert(*pps && pos && pps);

	pos->data = elem;

}
//����
SLNode SLFind(SList* ps, SLDataType val)
{

	SLNode cur = ps;
	
	while (cur)
	{
		if (cur->data == val)
		{
			return cur;
		}

		cur = cur->next;
	}
	//�Ҳ�������NULL
	return NULL;

}
//��ӡ
void SLPrint(const SList* ps)
{

	SLNode cur = ps;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//����
void SLDestory(SList** pps)
{
	assert(*pps);

	//�ͷŵ�һ���ڵ�֮��Ľڵ�
	SLNode cur = (*pps)->next;
	while (cur)
	{
		SLNode tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	//�ͷŵ�һ���ڵ�
	free(*pps);
	*pps = NULL;
}

