#define _CRT_SECURE_NO_WARNINGS 1

#include"MyStack.h"

//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newCapa = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newCapa);
		//relloc第一个参数为空指针时, 相当于malloc, 需要包含stdlib.h头文件

		if (tmp == NULL)
		{
			printf("realloc err\n");
			exit(-1);//直接结束程序
		}

		//free(ps->_a); relloc若是新开空间, 会自动是否原空间, 若后接空间, 则原空间不能是否
		ps->_a = tmp;
		ps->_capacity = newCapa;
		tmp = NULL;
	}

	ps->_a[ps->_top] = data;
	ps->_top++;

}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->_top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->_a[ps->_top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;

}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps) 
{
	assert(ps);

	return ps->_top == 0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);

	ps->_a = NULL;

	ps->_capacity = ps->_top = 0;

}