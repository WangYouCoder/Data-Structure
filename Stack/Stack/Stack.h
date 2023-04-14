#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Stack
{
	DataType* data;
	int top;
	int capacity;
}Stack;

// ��ʼ��ջ
void StackInit(Stack* ps);

// ��ջ
void StackPush(Stack* ps, DataType x);

// ��ջ
void StackPop(Stack* ps);

// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);