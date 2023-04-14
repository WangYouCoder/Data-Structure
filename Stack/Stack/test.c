#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void test()
{
	Stack st;
	StackInit(&st);//初始化

	StackPush(&st, 1);//测试:入栈
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while(!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");


	StackPush(&st, 5);//入栈一些元素进行测试
	StackPush(&st, 6);

	StackPop(&st);//测试:中途出栈的效果,实际就是将6提前出栈

	StackPush(&st, 7);
	StackPush(&st, 8);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");


	StackPush(&st, 1);//入栈一些数据进行测试
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	int sz = StackSize(&st);//测试:计算栈中元素个数
	printf("%d\n", sz);

	StackDestroy(&st);
}
int main()
{
	test();
	return 0;
}