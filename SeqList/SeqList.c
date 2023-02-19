#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void InitSeqList(SL* ps)
{
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}

void AddCapacity(SL* ps)
{
	//����
	if (ps->sz == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* pc = (SLDataType*)realloc(ps->data, sizeof(SLDataType) * newcapacity);
		if (pc == NULL)
		{
			perror("SeqListPushBack");
		}
		ps->data = pc;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	AddCapacity(ps);
	ps->data[ps->sz] = x;
	ps->sz++;
}

void SeqListPopback(SL* ps)
{
	//assert(ps->sz > 0);
	if (ps->sz > 0)
	{
		ps->sz--;
	}
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	AddCapacity(ps);
	int end = ps->sz - 1;
	while (end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->sz++;
}

void SeqListPopFront(SL* ps)
{
	if (ps->sz > 0)
	{
		int front = 1;
		while (front < ps->sz)
		{
			ps->data[front - 1] = ps->data[front];
			front++;
		}
		ps->sz--;
	}
}

void SeqListFind(SL* ps, SLDataType x)
{
	int front = 0;
	while (front < ps->sz)
	{
		if (ps->data[front] == x)
		{
			printf("�ҵ���,�±�Ϊ:>%d\n", front);
			break;
		}
		front++;
		if (front == ps->sz)
		{
			printf("Ԫ�ز�����\n");
		}
	}
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	AddCapacity(ps);
	pos -= 1;               //ת��Ϊ��Ӧ���±�
	int end = ps->sz - 1;  
	while (pos <= end)   //һֱ���±�Ϊposλ�õ�Ԫ��Ų��
	{
		ps->data[end + 1] = ps->data[end];   //��Ԫ�شӺ�һ��һ������Ų
		end--;
	}
	ps->data[pos] = x;
	ps->sz++;
}

void SeqListErase(SL* ps, int pos)
{
	int end = pos - 1;      //��end���±����Ӧ��ָ���pos��Ԫ�ص��±�
	if (pos > ps->sz)
	{
		printf("��λ��û��Ԫ��\n");
	}
	if (pos > 0 && pos <= ps->sz)   //��֤˳�����Ҫ��Ԫ�أ�����ɾ����Ԫ��λ�ñ���С�����һ��Ԫ�ص�λ��
	{
		while (end < ps->sz - 1)      //������ǰ���ǣ���ȻҲ����һ��ʼ��ת��Ϊ�±꣬posָ����Ƕ�ӦԪ�ص���һ��Ԫ�أ�ֱ����ǰ����Ҳ����
		{
			ps->data[end] = ps->data[end + 1];
			end++;
		}
		ps->sz--;
	}
}

void SeqListDestory(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}


