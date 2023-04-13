#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

void test()
{
	LTNode* phead = ListInit();
	if (phead == NULL)
	{
		return;
	}
	ListPushBack(phead, 1);//测试:尾插
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

  	ListPopBack(phead);//测试:尾删
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	ListPopBack(phead);//测试:如果链表为空继续删除会不会报错
	ListPopBack(phead);

	ListPushBack(phead, 1);//尾插一个数据来对比头插
	ListPushFront(phead, 1);//测试:头插
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);

	ListPopFront(phead);//测试:头删
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPopFront(phead);//测试:如果链表删除完毕，继续删除会不会报错
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPushBack(phead, 1);//插入新元素进行后续测试
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);
	ListFind(phead, 5);

	LTNode* pos = ListFind(phead, 2);//测试:在2前面插入数字5
	ListInsert(pos, 5);
	ListPrint(phead);

	pos = ListFind(phead, 2);//测试:删除结点2
	ListErase(pos);
	ListPrint(phead);

	ListDestroy(phead);//测试:销毁链表
}

int main()
{
	test();
	return 0;
}