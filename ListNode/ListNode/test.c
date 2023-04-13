#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

void test()
{
	LTNode* phead = ListInit();
	if (phead == NULL)
	{
		return;
	}
	ListPushBack(phead, 1);//����:β��
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

  	ListPopBack(phead);//����:βɾ
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	ListPopBack(phead);//����:�������Ϊ�ռ���ɾ���᲻�ᱨ��
	ListPopBack(phead);

	ListPushBack(phead, 1);//β��һ���������Ա�ͷ��
	ListPushFront(phead, 1);//����:ͷ��
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);

	ListPopFront(phead);//����:ͷɾ
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPopFront(phead);//����:�������ɾ����ϣ�����ɾ���᲻�ᱨ��
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPushBack(phead, 1);//������Ԫ�ؽ��к�������
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);
	ListFind(phead, 5);

	LTNode* pos = ListFind(phead, 2);//����:��2ǰ���������5
	ListInsert(pos, 5);
	ListPrint(phead);

	pos = ListFind(phead, 2);//����:ɾ�����2
	ListErase(pos);
	ListPrint(phead);

	ListDestroy(phead);//����:��������
}

int main()
{
	test();
	return 0;
}