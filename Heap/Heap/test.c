#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test()
{
	Heap hp;
	HeapInit(&hp);
	int a[] = { 25,36,12,64,35,44,62,73,28,52 };
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	//升序 -- 小堆
	//降序 -- 大堆
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestory(&hp);
}

//堆排序
//升序 -- 大堆
//降序 -- 小堆
void HeapSort(int* a, int n)
{
	////1.建堆 O(N*logn)
	int i = 0;
	//for (i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//2.建堆 O(N)
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	
	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

//选取最大的前K个数，建小堆
void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆--用a中前k个元素建堆
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	if (KMinHeap == NULL)
	{
		return;
	}

	int i = 0;
	for (i = 0; i < k; i++)
	{
		KMinHeap[i] = a[i];
	}
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(KMinHeap, k, i);
	}

	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	int j = 0;
	for (j = k; j < n; j++)
	{
		if (KMinHeap[0] < a[j])
		{
			KMinHeap[0] = a[j];
			AdjustDown(KMinHeap, k, 0);
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", KMinHeap[i]);
	}

	free(KMinHeap);
	KMinHeap = NULL;
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);

	free(a);
	a = NULL;
}
int main()
{
	//tset();
	int a[] = { 25,36,12,64,35,44,62,73,28,52 };
	//HeapSort(a, sizeof(a) / sizeof(int));

	TestTopk();
	return 0;
}

