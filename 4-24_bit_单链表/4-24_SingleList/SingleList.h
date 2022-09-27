#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

enum
{
	EXIT,

	PUSH_B,
	POP_B,
	PUSH_F,
	POP_F,

	INSERT,
	ERASE,
	INSERT_AFTER,
	ERASE_AFTER,

	FIND,
	MODIFY,
	PRINT,
	DESTORY,

};

//没有独立出去的头节点

typedef int SLDataType;
typedef struct SingleListNode
{
	SLDataType data;
	struct SingleListNode* next;
}SList, * SLNode;

//申请节点
SLNode BuyListNode(SLDataType elem);

/*头插删，尾插删*/
void SLPushBack(SList** pps, SLDataType elem);
void SLPopBack(SList** pps);
void SLPushFront(SList** pps, SLDataType elem);
void SLPopFront(SList** pps);

/*在指定节点：插入，删除*/
void SLInsert(SList** pps, SLNode pos, SLDataType elem);
void SLErase(SList** pps, SLNode pos);
/*在指定节点后：插入，删除*/
void SLInsertAfter(SList** pps, SLNode pos, SLDataType elem);
void SLEraseAfter(SList** pps, SLNode pos);

//查找
SLNode SLFind(SList* ps, SLDataType val);
//修改
void SLModify(SList** pps, SLNode pos, SLDataType elem);
//打印
void SLPrint(const SList* ps);
//销毁
void SLDestory(SList** ps);


