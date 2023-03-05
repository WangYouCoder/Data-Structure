#define _CRT_SECURE_NO_WARNINGS 1
#include"SListNode.h"

void test()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead,1);//����:β��
	SListPushBack(&phead,2);
	SListPushBack(&phead,3);
	SListPrint(phead);

	SListPushFront(&phead, 1);//����:ͷ��
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPrint(phead);

	SListPopBack(&phead);//����:βɾ
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(phead);

	SListPopBack(&phead);//����:������Ϊ�գ�����βɾ�᲻�ᱨ��
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(phead);

	SListPushBack(&phead, 1);//����һЩԪ�������к���Ĳ���
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPrint(phead);

	SListPopFront(&phead);//����:������Ϊ�գ�����ͷɾ�᲻�ᱨ��
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(phead);

	SListPushBack(&phead, 1);//�ٲ���һЩԪ�ؼ����к�������
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 2);
	SLTNode* pos = SListFind(phead, 2);//����:����
	int i = 1;
	while (pos != NULL)
	{
		printf("��%d��pos���:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	pos = SListFind(phead, 3);//����:��posλ�ú����Ԫ��
	SListInsertAfter(pos, 20);
	SListPrint(phead);

	SListInsert(&phead, pos, 30);//����:��posλ�ò���Ԫ��
	SListPrint(phead);

	pos = SListFind(phead, 20);//����:ɾ��posλ�ú��Ԫ��
	SListEraseAfter(pos);
	SListPrint(phead);

	pos = SListFind(phead, 3);//����:ɾ��posλ�õ�Ԫ��
	SListErase(&phead, pos);
	SListPrint(phead);

	SListDestory(&phead); //��������
}
int main()
{
	test();
	return 0;
}