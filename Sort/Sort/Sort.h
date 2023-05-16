#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<string.h>
//打印数组
void PrintArr(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a, int left, int right);

//非递归快排
void QuickSortNonR(int* a, int left, int right);

//归并排序
void MergeSort(int* a, int n);

//非递归归并
void MergeSortNonR1(int* a, int n);
void MergeSortNonR2(int* a, int n);

//计数排序
void CountSort(int* a, int n);

