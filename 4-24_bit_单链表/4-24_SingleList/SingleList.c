#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

//申请节点
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

/*头增头删*/
void SLPushBack(SList** pps, SLDataType elem)
{
	assert(pps);

	//若单链表不存在
	if (*pps == NULL)
	{
		SLNode newnode = BuyListNode(elem);
		*pps = newnode;
	}
	//若存在
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
	
	//如果只有一个节点
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


/*在指定节点：插入，删除*/
void SLInsert(SList** pps, SLNode pos, SLDataType elem)
{
	assert(pps);
	assert(pos);

	//如果在头节点插入
	if (pos == *pps)
	{
		SLNode newnode = BuyListNode(elem);

		newnode->next = *pps;
		*pps = newnode;
	}
	else
	{
		//1. 遍历找节点的父节点--O(n)
		//2. 交换pos节点和新节点的值--O(1)
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

	//如果删除头节点
	if (pos == *pps)
	{
		SLNode tmp = (*pps)->next;
		free(*pps);
		*pps = tmp;
	}
	else
	{

		// 交换pos节点和后节点的值--O(1)/O(n)--最后一个节点不能交换后面的值，只能遍历
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
/*在指定节点后：插入，删除*/
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
	//最后一个节点后面不可删除
	assert(pos->next);

	SLNode tmp = pos->next->next;
	pos->next->next = NULL;
	free(pos->next);
	pos->next = tmp;
	
}


//修改
void SLModify(SList** pps, SLNode pos, SLDataType elem)
{
	assert(*pps && pos && pps);

	pos->data = elem;

}
//查找
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
	//找不到返回NULL
	return NULL;

}
//打印
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
//销毁
void SLDestory(SList** pps)
{
	assert(*pps);

	//释放第一个节点之后的节点
	SLNode cur = (*pps)->next;
	while (cur)
	{
		SLNode tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	//释放第一个节点
	free(*pps);
	*pps = NULL;
}

