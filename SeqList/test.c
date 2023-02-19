#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void test1()
{
	//≤‚ ‘π¶ƒ‹
	SL s1;
	InitSeqList(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPrint(&s1);

	SeqListPopback(&s1);
	SeqListPopback(&s1);
	SeqListPopback(&s1);
	SeqListPopback(&s1);

	SeqListPushBack(&s1, 1);
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 3);
	SeqListPrint(&s1);

	SeqListPopFront(&s1);

	SeqListFind(&s1, 1);

	SeqListInsert(&s1, 1, 5);
	SeqListPrint(&s1);

	SeqListErase(&s1, 1);
	SeqListPrint(&s1);
	SeqListErase(&s1, 4);
	SeqListPrint(&s1);

	SeqListDestory(&s1);

}

int main()
{
	test1();
	return 0;
}