#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<string.h>
//��ӡ����
void PrintArr(int* a, int n);

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);

//�ǵݹ����
void QuickSortNonR(int* a, int left, int right);

//�鲢����
void MergeSort(int* a, int n);

//�ǵݹ�鲢
void MergeSortNonR1(int* a, int n);
void MergeSortNonR2(int* a, int n);

//��������
void CountSort(int* a, int n);

