#include "MemoryStudy.h"

//molloc函数在这里面

void MemoryStudy::run(){

	/*  内存的组织方式  内存分为四个区   代码区（存储着程序代码）  数据区（存储静态、全局数据，常量 ）   堆区（存储着动态分配的内存，也是主要清理的区域 ）  栈区（主要存放局部变量  函数参数）
	
	*/

	//静态分配内存
	int a = 9;
	int *p1 = &a;

	/*  访问方式
	*p1;
	a;
	*/

	//动态分配4个字节 会把分配的内存首地址返回
	//分配整形变量
	int * pInt = (int*)malloc(sizeof(int));

	//分配一个字符变量
	char* pCh = (char*)malloc(sizeof(char));

	//分配一个字字符型数组
	char* pArray = (char*)malloc(sizeof(char) * 10);

	//分配一个double类型的变量
	double* pDouble = (double*)malloc(sizeof(double));


	//动态内存的使用

	*pInt = 9;
	printf("*pInt=%d\n", *pInt);
	*pCh = 'a';
	printf("*pCh=%d\n", *pCh);
	for (size_t i = 0; i < 10; i++)
	{
		pArray[i] = 'a' + i;
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("pArray + %d)=%c\n", i, *(pArray+i));
			
	}

	//释放内存
	free(pDouble);
	free(pArray);
	free(pCh);
	free(pInt);


	//野指针   内存泄露
	/*
	野指针产生原因 1：指针变量没有有效初始化   2：越界访问

	内存泄漏  1：动态分配内存时   如果分配的内存没有有效的释放  就会内存泄露
	
	*/


}
