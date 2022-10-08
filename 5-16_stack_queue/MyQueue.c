#define _CRT_SECURE_NO_WARNINGS 1

#include"MyQueue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = q->_rear = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	//����ڵ�
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		printf("malloc err");
		exit(-1);
	}
	node->_data = data;
	node->_next = NULL;

	//�ն������⻯����
	if (q->_rear == NULL)
	{
		q->_front = q->_rear = node;
	}
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_rear);

	//ֻ��һ��Ԫ��
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_rear);

	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);

	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);

	int size = 0;
	QNode* cur = q->_front;

	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;

}
// �������Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_rear == NULL;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;

	while (cur)
	{
		QNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}

	q->_front = q->_rear = NULL;
}