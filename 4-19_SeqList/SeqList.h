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


//初始化
void SLInit(SL* ps);
//增容
void CheckCapacity(SL* ps);

//增删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//查找
int SLFindVal(SL* ps, SLDataType x);
//修改
void SLModifyVal(SL* ps, int pos, SLDataType x);

//插入
void SLInsert(SL* ps, int pos, SLDataType x);
//删除
void SLDelete(SL* ps, int pos);

//排序
int SLDataCmp(void* s1, void* s2);
void SLSort(SL* ps);
//遍历
void SLPrint(SL* ps);
//清空
void SLClear(SL* ps);
