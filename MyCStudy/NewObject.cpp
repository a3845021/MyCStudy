#include "NewObject.h"


NewObject::NewObject()
{
}


NewObject::~NewObject()
{
}

//c������
void test1()
{
	//����һ������
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	if (p != NULL){
		free(p);
		p = NULL;
	}

	//����һ������
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
// malloc free�Ǻ�������׼�⣬stdlib.h
// new �ڶ��ϳ�ʼ��һ�������ʱ�򣬻ᴥ������Ĺ��캯����malloc����
//free�����ܳ���һ���������������
//C++��
void test2(){
	//����һ������
	int *p = new int;
	*p = 10;
	if (p != NULL){
		delete p;
		p = NULL;
	}

	//����һ������
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
