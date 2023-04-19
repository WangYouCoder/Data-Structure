#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);//测试:入队列
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n",QueueFront(&q));//测试:获取队头元素

	printf("%d\n", QueueSize(&q));//测试:统计元素个数

	QueueDestroy(&q);
}

void test1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);//测试:入队列
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		Datatype x = QueueFront(&q);
		printf("%d ", x);
		QueuePop(&q);   //测试:出队列
	}
	printf("\n");

	QueueDestroy(&q);
}
int main()
{
	test();
	//test1();
	return 0;
}