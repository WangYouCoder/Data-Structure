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

//交换函数
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//O(n*2)
void SelectSort(int* a, int n)
{
	int end = n - 1;
	int begin = 0;
	while (begin < end)
	{
		int mini = begin, maxi = end;
		int i = 0;
		for (i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;

			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[mini], &a[begin]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[maxi], &a[end]);

		begin++;
		end--;
	}
}

//向上调整
void AdjustUp(int* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (data[child] < data[parent]) // "<" 小堆
		{
			Swap(&data[child], &data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整
void AdjustDown(int* data, int size, int parent)
{
	int child = (parent * 2) + 1;
	while (child < size)
	{
		if (child + 1 < size && data[child] > data[child + 1])  // "<" 大堆
		{
			child++;
		}

		if (data[child] < data[parent]) // ">"大堆
		{
			Swap(&data[child], &data[parent]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
		{
			break;
		}
	}
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

//O(n*2)
void BubbleSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++) //趟数
	{
		int j = 0;
		for (j = 0; j < n - 1 - i; j++) //每个元素比较次数
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if(a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else  //a[left] < a[mid]
	{
		if (a[right] < a[left])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
}

int Partion1(int* a, int left, int right)
{
	int min = GetMidIndex(a, left, right);
	Swap(&a[left], &a[min]);

	int key = left;
	while (left < right)
	{
		//从右往左，找小的
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//从左往右，找大的
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	return left;
}

int Partion2(int* a, int left, int right)
{
	int min = GetMidIndex(a, left, right);
	Swap(&a[left], &a[min]);

	int pivot = left;
	int key = a[left];
	while (left < right)
	{
		//从右往左，找小的，放到左边的坑里
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//Swap(&a[pivot], &a[right]);
		a[pivot] = a[right];
		pivot = right;

		//从左往右，找大的,放到右边的坑里
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		//Swap(&a[pivot], &a[left]);
		a[pivot] = a[left];
		pivot = left;
	}
	a[pivot] = key;
	return pivot;
}

//O(N*logN)
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int key = Partion1(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}