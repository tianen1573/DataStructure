#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include<malloc.h>
#include<stdlib.h>


typedef int SLDataType;
typedef struct SeqList
{
	int* data;
	int size;
	int capacity;
}SL;

enum
{
	EXIT,
	INSERT,
	DELETE,
	PushB,
	PopB,
	PushF,
	PopF,
	FIND,
	MODIFY,
	SORT,
	SIZE,
	CLEAR,
	PRINTF,
};


//��ʼ��
void SLInit(SL* ps);
//����
void CheckCapacity(SL* ps);

//��ɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//����
int SLFindVal(SL* ps, SLDataType x);
//�޸�
void SLModifyVal(SL* ps, int pos, SLDataType x);

//����
void SLInsert(SL* ps, int pos, SLDataType x);
//ɾ��
void SLDelete(SL* ps, int pos);

//����
int SLDataCmp(void* s1, void* s2);
void SLSort(SL* ps);
//����
void SLPrint(SL* ps);
//���
void SLClear(SL* ps);
