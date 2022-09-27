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

//û�ж�����ȥ��ͷ�ڵ�

typedef int SLDataType;
typedef struct SingleListNode
{
	SLDataType data;
	struct SingleListNode* next;
}SList, * SLNode;

//����ڵ�
SLNode BuyListNode(SLDataType elem);

/*ͷ��ɾ��β��ɾ*/
void SLPushBack(SList** pps, SLDataType elem);
void SLPopBack(SList** pps);
void SLPushFront(SList** pps, SLDataType elem);
void SLPopFront(SList** pps);

/*��ָ���ڵ㣺���룬ɾ��*/
void SLInsert(SList** pps, SLNode pos, SLDataType elem);
void SLErase(SList** pps, SLNode pos);
/*��ָ���ڵ�󣺲��룬ɾ��*/
void SLInsertAfter(SList** pps, SLNode pos, SLDataType elem);
void SLEraseAfter(SList** pps, SLNode pos);

//����
SLNode SLFind(SList* ps, SLDataType val);
//�޸�
void SLModify(SList** pps, SLNode pos, SLDataType elem);
//��ӡ
void SLPrint(const SList* ps);
//����
void SLDestory(SList** ps);


