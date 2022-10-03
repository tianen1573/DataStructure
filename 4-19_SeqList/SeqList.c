#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//��ʼ��
void SLInit(SL* ps)
{
	assert(ps);

	ps->capacity = 5;
	ps->size = 0;
	ps->data = (SLDataType*)malloc(sizeof(SLDataType) * ps->capacity);

	memset(ps->data, 0, sizeof(SLDataType) * ps->capacity);

}
//����
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
		printf("���ݳɹ�\n");
	}
	else
	{
		ps->capacity -= 5;
		printf("����ʧ��\n");
	}
}


//��ɾ
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
//����
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


//����
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
//�޸�
void SLModifyVal(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->data[pos] = x;
}

//����
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
//ɾ��
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

//����
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
//����
void SLPrint(const SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}

	printf("-----------------------------------\n");
	for (int i = 0; i < ps->size; i++)
	{
		printf("%-5d", ps->data[i]);
	}
	printf("\n-----------------------------------\n");

}
//���
void SLClear(SL* ps)
{
	ps->size = 0;
	ps->capacity = 5;
	SLDataType* tmp = (SLDataType*)realloc(ps->data, sizeof(SLDataType) * ps->capacity);
	if (tmp == NULL)
		printf("���ʧ��\n");
	else
	{
		ps->data = tmp;
		tmp = NULL;
		printf("��ճɹ�\n");
	}
}