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
	//	gap /= 2; //��gapΪ1ʱ��ֱ�Ӳ�������
	//	for (j = 0; j < gap; j++) //ͨ��j��������i������һ������ÿ��Ԫ��
	//	{
	//		for (i = j; i < n - gap; i += gap) // ��һ��
	//		{
	//			int end = i;
	//			int tmp = a[end + gap];
	//			while (end >= 0)  // ��һ��
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
		gap /= 2; //��gapΪ1ʱ��ֱ�Ӳ�������
		for (i = 0; i < n - gap; i++) // һ����һ����
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)  // ��һ��
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

//��������
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

//���ϵ���
void AdjustUp(int* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (data[child] < data[parent]) // "<" С��
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

//���µ���
void AdjustDown(int* data, int size, int parent)
{
	int child = (parent * 2) + 1;
	while (child < size)
	{
		if (child + 1 < size && data[child] > data[child + 1])  // "<" ���
		{
			child++;
		}

		if (data[child] < data[parent]) // ">"���
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

//������
//���� -- ���
//���� -- С��
void HeapSort(int* a, int n)
{
	////1.���� O(N*logn)
	int i = 0;
	//for (i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//2.���� O(N)
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
	for (i = 0; i < n - 1; i++) //����
	{
		int j = 0;
		for (j = 0; j < n - 1 - i; j++) //ÿ��Ԫ�رȽϴ���
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
		//����������С��
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//�������ң��Ҵ��
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	return left;
}

//�ڿӷ�
int Partion2(int* a, int left, int right)
{
	int min = GetMidIndex(a, left, right);
	Swap(&a[left], &a[min]);

	int pivot = left;
	int key = a[left];
	while (left < right)
	{
		//����������С�ģ��ŵ���ߵĿ���
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		//Swap(&a[pivot], &a[right]);
		a[pivot] = a[right];
		pivot = right;

		//�������ң��Ҵ��,�ŵ��ұߵĿ���
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

//ǰ��ָ��
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
	//[left,mid] [mid + 1,right] ����
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

	int gap = 1, i = 0;  //���Ʋ���
	while (gap < n)
	{
		for (i = 0; i < n; i = i + 2 * gap)
		{
			//[i,i+gap-1]  [i+gap, i+gap*2-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			int j = i;

			//end2 Խ��
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//begin2 Խ�� [begin2,end2]������,�������������Ϊ������
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}

			//end1 Խ�磬[begin2,end2]������
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

	int gap = 1, i = 0;  //���Ʋ���
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
	//����
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	//����
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