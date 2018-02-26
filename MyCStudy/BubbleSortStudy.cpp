#include "BubbleSortStudy.h"


BubbleSortStudy::BubbleSortStudy()
{
	/*	冒泡排序原理图
	次数	1	2	3	4	5
		21	21	21	21	21	21
		45	44	36	36	36	36
		44	45	44	44	44	37
		78	36	45	45	37	44
		36	45	45	37	45
		45	78	37	45
		86	37	78
		37	86
	*/
}


BubbleSortStudy::~BubbleSortStudy()
{
}

void BubbleSortStudy::sort(){
	//一个数组中取得最大的数
	int array[10] = { 10, 2, 45, 78, 90, 35, 54, 13, 36, 97 };
	int size = sizeof(array) / sizeof(int);
	int nub = 0;	//最大数的下标
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > array[nub]){
			nub = i;
		}
	}
	printf("最大的数是%d  ", array[nub]);
}

void BubbleSortStudy::run(){

	//
	sort();
	return;

	int array[10] = {10,2,45,78,56,35,54,13,36,97};
	int size = sizeof(array)/sizeof(int);
	for (size_t i = 0; i < size-1; i++)//只需要遍历  size-1 次
	{
		bool tag = false; 
		int count = 0;
		for (size_t j = 0; j < size - 1-i; j++)//  减去i  表示后面的数据已经固定了
		{
			count++;
			if (array[j] > array[j + 1]){
				tag = true;  //说明本次出现了交换
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
		if (!tag)
		{
			break;
		}
		printf("第几次%d---%d  ", i, count);
		count = 0;
		for (size_t i = 0; i < size; i++)
		{
			printf("  %d  ", array[i]);
		}
		printf("\n");
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "------shuzi----=" << array[i] << "--------" << i << endl;

	}

}