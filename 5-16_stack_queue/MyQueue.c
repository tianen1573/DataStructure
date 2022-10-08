#define _CRT_SECURE_NO_WARNINGS 1

#include"MyQueue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = q->_rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	//申请节点
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		printf("malloc err");
		exit(-1);
	}
	node->_data = data;
	node->_next = NULL;

	//空队列特殊化处理
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
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_rear);

	//只有一个元素
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_rear);

	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);

	return q->_rear->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_rear == NULL;
}
// 销毁队列 
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