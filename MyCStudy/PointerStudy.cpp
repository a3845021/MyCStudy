#include "PointerStudy.h"


PointerStudy::PointerStudy()
{
}


PointerStudy::~PointerStudy()
{
}
void  test(int a){
	printf("����ָ�����\n\n");
}

void PointerStudy::run(){

	//void���͵�ָ�� ������ָ���κ����͵�ָ��

	char temp = 'a';
	void * p2 = NULL;
	p2 = &temp;
	printf("void���ͻ�õ�ֵ��-----%c\n\n",*(char *)p2);
	printf("void�ĵ�ַ %p\n\n", p2);

	//ָ���С ָ������


	//��ָ���������Ԫ�صļ��ַ�ʽ
	/*
	1��������ʵ���Ͼ���һ��ָ��������е�һ��Ԫ��ָ��
	int arr[5]={1,2,3,4,5}; int *p=NULL;
	p=&arr[0];��ͬ�� p=parr;
	
	2:��ʵ������Ԫ��ǰ���һ��&��ʹ�ñ�����ͬ    p=&arr[1]

	3:�������������ƫ�����ı�ָ�������Ԫ��   p=&arr[1]; p++; //�൱��p=&arr[2]
	*/

	int array[5] = {1,2,3,4,5};
	int *p = NULL;
	int *p1 = NULL;
	p = array;
	p1 = &array[0];
	printf("p---------%p\n",p);
	printf("p1-------%p\n",p1);

	*p = array[1];

	//������������ַ�ʽ   �±����  ���������±꡿  ָ�롾�±꡿

	/*
	
	���磺   int array[5]={1,2,3,4,5};
			int nvalue1=array[0];
			int nvalue2=array[1];	
	
	����   int *p =array;
			����ʹ��

			int nval1=*{array};
			int nval2=*(p+1);
	
	*/

	// const ����ָ��

	/*
	const int *p  //ֵ���ɸı�
	int const *p  //ͬ��
	int *const p  //ָ�򲻿ɸı�
	const int * const p //ָ���ֵ�����ɸı�
	
	
	const ���� �����
	���ε���ָ���ָ����ڴ�
	1��ָ�벻���Ըı�ָ��
	2��������ͨ��ָ��ı�����ָ���ڴ��ֵ

	const ���ǵ��ұ�
	���ε���ָ������ı���
	1��ָ�벻���Ըı�ָ��
	2������ͨ��ָ��ı�����ָ���ڴ��ֵ

	ע�⣺���������Կ���ͨ��������ȥ�޸�

	�Ǻ����Ҷ���const 
	1��ָ�벻���Ըı�ָ��
	2��������ͨ��ָ��ı�����ָ����ڴ��ֵ
	*/


	//ָ�����ַ���

	char *str = "hello";
	char str1[10] = "hello";

	str1[1] = 'E';
	printf("str1-----%s\n",str1);

	printf("str------%s\n\n", str);

	//ָ���뺯��

	/*
	ָ�������λ������������ָ�������ʵ�ε���ʽ���ݸ����������е��ǵ�ַ�Ĵ��ݡ����Կ����ں����иı�ʵ�ε�ֵ

	*/

	/*ָ������ָ��  ����ĸ�ʽΪ
	�������� ��*ָ��������� ���β��б�

	���� float ��*p����float x , float y��
	*/
	void (*ptest)(int a);

	ptest =test;
	ptest(1);
	//����ָ��

	//ָ���ָ�루��άָ�룩
	/* ����
	int a;
	int *p = &a;
	int **p1 = &p;
	*/	 
	//��άָ��
	int a = 10;
	int *p4 = &a;
	int **p3 = &p4;
	printf("a=%d  p4=%p  p1=%p\n", a, p4, p1);
	printf("*p4 = %d **p3= %d\n\n", *p4, **p3);

	//����ָ��
	/*
	���巽ʽ  ��������  ��*ָ������[���鳤��]
	���磺
		int a[5]={1,2,3,4,5};
		int (*p)[5]=&a;
    ����ʱ���ܶ�������,��Ϊ[]���ȼ���*�ߣ�����������ţ����Ϊָ�����飬

	����ָ�붨ʱ�����鳤�ȣ�Ԫ�����ͣ������� ָ�����������ĳ���������ͬ
	*/


	//ָ�����鳤��Ϊ5�����������ָ��
	//int (*p4)[5];

	//һ������ ����Ϊint* [10];
	int *p5[10];

	//����ָ��ָ�������������  ����������Ԫ��  ����ָ������p+1�൱��p+1*sizeof(������)

	//��������Ԫ�صķ�ʽ��	a[0], *a, *(a + 1)  (*p)[0]

	int(*p6)[5];
	int array1[5] = {1,2,3,4,5};

	p6 = &array1;

	printf("(*p6)����= %d   p[0]����= %d\n\n",(*p6)[1],p6[0][3]);

	//ָ������ �� һ��������ͬ�����򼯺�   ������* ������[���鳤��]

	/*
	���磺   int * ayyay_int[10]// ������һ��������10��Ԫ����ɵģ�ÿ��Ԫ�ض���int* ָ�� 
	*/

	char * pArray[3] = {0};

	char arrchar1[] = "how";
	char arrchar2[] = "are";
	char *arrstr = "are";

	pArray[0] = arrchar1;
	pArray[1] = arrchar2;
	pArray[2] = arrstr;

	for (size_t i = 0; i < 3; i++)
	{
		printf("%s\n", pArray[i]);
	}


}
