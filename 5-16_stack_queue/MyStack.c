#define _CRT_SECURE_NO_WARNINGS 1

#include"MyStack.h"

//��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newCapa = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newCapa);
		//relloc��һ������Ϊ��ָ��ʱ, �൱��malloc, ��Ҫ����stdlib.hͷ�ļ�

		if (tmp == NULL)
		{
			printf("realloc err\n");
			exit(-1);//ֱ�ӽ�������
		}

		//free(ps->_a); relloc�����¿��ռ�, ���Զ��Ƿ�ԭ�ռ�, ����ӿռ�, ��ԭ�ռ䲻���Ƿ�
		ps->_a = tmp;
		ps->_capacity = newCapa;
		tmp = NULL;
	}

	ps->_a[ps->_top] = data;
	ps->_top++;

}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->_top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;

}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps) 
{
	assert(ps);

	return ps->_top == 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);

	ps->_a = NULL;

	ps->_capacity = ps->_top = 0;

}