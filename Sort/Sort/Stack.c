#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	/*DataType* tmp = (DataType*)malloc(sizeof(DataType));
	if (tmp == NULL)
	{
		return;
	}*/

	ps->data = NULL;
	ps->top = 0;      //ָ��ջ��Ԫ�ص���һ��λ�ã�ͬʱҲ������ջ���ж���Ԫ��
	ps->capacity = 0;
}

void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	//�ж��Ƿ���Ҫ����
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		DataType* tmp = (DataType*)realloc(ps->data,sizeof(DataType) * newcapacity);
		if (tmp == NULL)
		{
			return;
		}
		ps->data = tmp;
		ps->capacity = newcapacity;
	}
	ps->data[ps->top] = x;
	ps->top++;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackPop(Stack* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	ps->top--;
}

DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

void StackDestroy(Stack* ps)
{
	ps->top = 0;
	ps->capacity = 0;
	free(ps->data);
	ps->data = NULL;
}