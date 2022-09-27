#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//初始化
void SLInit(SL* ps)
{
	assert(ps);

	ps->capacity = 5;
	ps->size = 0;
	ps->data = (SLDataType*)malloc(sizeof(SLDataType) * ps->capacity);

	memset(ps->data, 0, sizeof(SLDataType) * ps->capacity);

}
//增容
void CheckCapacity(SL* ps)
{
	assert(ps);

	SLDataType* tmp = NULL;
	ps->capacity += 5;
	tmp = (SLDataType*)realloc(ps->data, sizeof(SLDataType) * ps->capacity);

	if (tmp != NULL)
	{
		ps->data = tmp;
		tmp = NULL;
		printf("扩容成功\n");
	}
	else
	{
		ps->capacity -= 5;
		printf("扩容失败\n");
	}
}


//增删
/*
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	if (ps->size == ps->capacity)
		CheckCapacity(ps);

	ps->data[ps->size++] = x;

}
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);

	ps->size--;

}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	if (ps->size == ps->capacity)
		CheckCapacity(ps);
	
	int end = ps->size;
	while (end > 0)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	ps->data[end] = x;
	ps->size++;

}
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);

	int begin = 0;
	while (begin < ps->size - 1)
	{
		ps->data[begin] = ps->data[begin + 1];
			begin++;
	}

	ps->size--;

}
*/
//复用
void SLPushBack(SL* ps, SLDataType x) 
{
	assert(ps);

	SLInsert(ps, ps->size, x);
}
void SLPopBack(SL* ps)
{
	assert(ps);

	SLDelete(ps, ps->size - 1);
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLInsert(ps, 0, x);
}
void SLPopFront(SL* ps)
{
	assert(ps);

	SLDelete(ps, 0);
}


//查找
int SLFindVal(SL* ps, SLDataType x)
{
	assert(ps);

	int begin = 0;
	while (begin < ps->size)
	{
		if (ps->data[begin] == x)
			return begin;
		begin++;
	}
	return -1;
}
//修改
void SLModifyVal(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->data[pos] = x;
}

//插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	if (ps->size == ps->capacity)
		CheckCapacity(ps);

	int end = ps->size;
	while (end > pos)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	ps->data[end] = x;
	ps->size++;

}
//删除
void SLDelete(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	int begin = pos;
	while (begin < ps->size - 1)
	{
		ps->data[begin] = ps->data[begin + 1];
		begin++;
	}

	ps->size--;
}

//排序
int SLDataCmp(void* s1, void* s2)
{
	SLDataType* p1 = (SLDataType*)s1;
	SLDataType* p2 = (SLDataType*)s2;
	return *p1 > *p2 ? 1 : -1;
}
void SLSort(SL* ps)
{
	qsort(ps->data, ps->size, sizeof(SLDataType), SLDataCmp);
}
//遍历
void SLPrint(const SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("顺序表为空\n");
		return;
	}

	printf("-----------------------------------\n");
	for (int i = 0; i < ps->size; i++)
	{
		printf("%-5d", ps->data[i]);
	}
	printf("\n-----------------------------------\n");

}
//清空
void SLClear(SL* ps)
{
	ps->size = 0;
	ps->capacity = 5;
	SLDataType* tmp = (SLDataType*)realloc(ps->data, sizeof(SLDataType) * ps->capacity);
	if (tmp == NULL)
		printf("清空失败\n");
	else
	{
		ps->data = tmp;
		tmp = NULL;
		printf("清空成功\n");
	}
}