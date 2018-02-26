#include "NewObject.h"


NewObject::NewObject()
{
}


NewObject::~NewObject()
{
}

//c语言中
void test1()
{
	//创建一个整数
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	if (p != NULL){
		free(p);
		p = NULL;
	}

	//创建一个数组
	int *array_p = (int *)malloc(sizeof(int) * 10);

	for (size_t i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d",array_p[i]);
	}
	printf("\n");

	if (array_p != NULL){
		free(array_p);
		array_p = NULL;
	}
}
// malloc free是函数，标准库，stdlib.h
// new 在堆上初始化一个对象的时候，会触发对象的构造函数，malloc不能
//free并不能出发一个对象的析构函数
//C++中
void test2(){
	//创建一个整数
	int *p = new int;
	*p = 10;
	if (p != NULL){
		delete p;
		p = NULL;
	}

	//创建一个数组
	int *array_p = new int[10];
	for (size_t i = 0; i < 10; i++)
	{
		array_p[i] = i + 1;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << array_p[i];
	}
	cout << endl;

	if (array_p != NULL){
		delete[] array_p;
	}
}

void NewObject::run(){

}
