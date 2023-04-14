#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void test()
{
	Stack st;
	StackInit(&st);//��ʼ��

	StackPush(&st, 1);//����:��ջ
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while(!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");


	StackPush(&st, 5);//��ջһЩԪ�ؽ��в���
	StackPush(&st, 6);

	StackPop(&st);//����:��;��ջ��Ч��,ʵ�ʾ��ǽ�6��ǰ��ջ

	StackPush(&st, 7);
	StackPush(&st, 8);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");


	StackPush(&st, 1);//��ջһЩ���ݽ��в���
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	int sz = StackSize(&st);//����:����ջ��Ԫ�ظ���
	printf("%d\n", sz);

	StackDestroy(&st);
}
int main()
{
	test();
	return 0;
}