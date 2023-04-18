#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void PrintArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	assert(a);
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = 3;
	int i = 0;
	int j = 0;
	//while (gap > 1)
	//{
	//	gap /= 2; //当gap为1时就直接插入排序
	//	for (j = 0; j < gap; j++) //通过j变量控制i变量，一次排序每个元素
	//	{
	//		for (i = j; i < n - gap; i += gap) // 排一组
	//		{
	//			int end = i;
	//			int tmp = a[end + gap];
	//			while (end >= 0)  // 排一个
	//			{
	//				if (a[end] > tmp)
	//				{
	//					a[end + gap] = a[end];
	//					end -= gap;
	//				}
	//				else
	//				{
	//					break;
	//				}
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	}
	//}


	while (gap > 1)
	{
		gap /= 2; //当gap为1时就直接插入排序
		for (i = 0; i < n - gap; i++) // 一个接一个排
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)  // 排一个
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}