#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"

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

//挖坑法
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

//前后指针
int Partion3(int* a, int left, int right)
{
	int key = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[key] > a[cur])
		{
			Swap(&a[cur], &a[++prev]);
			cur++;
		}
		else
		{
			cur++;
		}
	}
	Swap(&a[key], &a[prev]);
	return prev;
}

//O(N*logN)
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int key = Partion3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);

		int begin = StackTop(&st);
		StackPop(&st);

		int key = Partion3(a, begin, end);
		//[begin,key - 1] key [key + 1,end]

		if (begin < key - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, key - 1);
		}

		if (key + 1 < end)
		{
			StackPush(&st, key + 1);
			StackPush(&st, end);
		}
	}

	StackDestroy(&st);
}

void _MergeSort(int* a,int left,int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	//[left,mid] [mid + 1,right] 有序
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left,end1 = mid;
	int begin2 = mid + 1,end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	int j = 0;
	for (j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("MergeSort:");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("MergeSort:");
		exit(-1);
	}

	int gap = 1, i = 0;  //类似层序
	while (gap < n)
	{
		for (i = 0; i < n; i = i + 2 * gap)
		{
			//[i,i+gap-1]  [i+gap, i+gap*2-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			int j = i;

			//end2 越界
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//begin2 越界 [begin2,end2]不存在,讲这个区间设置为不存在
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}

			//end1 越界，[begin2,end2]不存在
			if (end1 >= n)
			{
				end1 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}

		int j = 0;
		for (j = 0; j < n; j++)
		{
			a[j] = tmp[j];
		}
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("MergeSort:");
		exit(-1);
	}

	int gap = 1, i = 0;  //类似层序
	while (gap < n)
	{
		for (i = 0; i < n; i = i + 2 * gap)
		{
			//[i,i+gap-1]  [i+gap, i+gap*2-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			int j = i;

			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}

		int j = 0;
		for (j = 0; j < n; j++)
		{
			a[j] = tmp[j];
		}
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;

	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		printf("MergeSort:");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);
	//计数
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	//排序
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}


	free(count);
	count = NULL;
}