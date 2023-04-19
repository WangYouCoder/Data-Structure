#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);//����:�����
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n",QueueFront(&q));//����:��ȡ��ͷԪ��

	printf("%d\n", QueueSize(&q));//����:ͳ��Ԫ�ظ���

	QueueDestroy(&q);
}

void test1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);//����:�����
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		Datatype x = QueueFront(&q);
		printf("%d ", x);
		QueuePop(&q);   //����:������
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