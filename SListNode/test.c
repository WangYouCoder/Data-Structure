#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

void test()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead,1);//测试:尾插
	SListPushBack(&phead,2);
	SListPushBack(&phead,3);
	SListPrint(phead);

	SListPushFront(&phead, 1);//测试:头插
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPrint(phead);

	SListPopBack(&phead);//测试:尾删
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(phead);

	SListPopBack(&phead);//测试:当链表为空，继续尾删会不会报错
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(phead);

	SListPushBack(&phead, 1);//插入一些元素来进行后面的测试
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPrint(phead);

	SListPopFront(&phead);//测试:当链表为空，继续头删会不会报错
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(phead);

	SListPushBack(&phead, 1);//再查入一些元素及进行后续测试
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 2);
	SLTNode* pos = SListFind(phead, 2);//测试:查找
	int i = 1;
	while (pos != NULL)
	{
		printf("第%d个pos结点:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	pos = SListFind(phead, 3);//测试:在pos位置后插入元素
	SListInsertAfter(pos, 20);
	SListPrint(phead);

	SListInsert(&phead, pos, 30);//测试:在pos位置插入元素
	SListPrint(phead);

	pos = SListFind(phead, 20);//测试:删除pos位置后的元素
	SListEraseAfter(pos);
	SListPrint(phead);

	pos = SListFind(phead, 3);//测试:删除pos位置的元素
	SListErase(&phead, pos);
	SListPrint(phead);

	SListDestory(&phead); //销毁链表
}
int main()
{
	test();
	return 0;
}