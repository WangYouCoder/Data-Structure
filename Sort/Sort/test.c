#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 5,2,9,4,3,8,6,1,7,0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));
}

TestShellSort()
{
	int a[] = { 5,2,9,4,3,8,6,1,7,0 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArr(a, sizeof(a) / sizeof(int));

}
int main()
{
	//TestInsertSort();
	TestShellSort();
	return 0;
}