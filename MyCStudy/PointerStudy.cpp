#include "PointerStudy.h"


PointerStudy::PointerStudy()
{
}


PointerStudy::~PointerStudy()
{
}
void  test(int a){
	printf("函数指针测试\n\n");
}

void PointerStudy::run(){

	//void类型的指针 ：可以指向任何类型的指针

	char temp = 'a';
	void * p2 = NULL;
	p2 = &temp;
	printf("void类型获得的值是-----%c\n\n",*(char *)p2);
	printf("void的地址 %p\n\n", p2);

	//指针大小 指针运算


	//用指针访问数组元素的几种方式
	/*
	1：数组名实际上就是一个指向该数组中第一个元素指针
	int arr[5]={1,2,3,4,5}; int *p=NULL;
	p=&arr[0];等同于 p=parr;
	
	2:在实际数组元素前面加一个&与使用变量相同    p=&arr[1]

	3:在数组名后面加偏移量改变指向的数组元素   p=&arr[1]; p++; //相当于p=&arr[2]
	*/

	int array[5] = {1,2,3,4,5};
	int *p = NULL;
	int *p1 = NULL;
	p = array;
	p1 = &array[0];
	printf("p---------%p\n",p);
	printf("p1-------%p\n",p1);

	*p = array[1];

	//访问数组的两种方式   下标访问  数组名【下标】  指针【下标】

	/*
	
	例如：   int array[5]={1,2,3,4,5};
			int nvalue1=array[0];
			int nvalue2=array[1];	
	
	例如   int *p =array;
			可以使用

			int nval1=*{array};
			int nval2=*(p+1);
	
	*/

	// const 修饰指针

	/*
	const int *p  //值不可改变
	int const *p  //同上
	int *const p  //指向不可改变
	const int * const p //指向和值均不可改变
	
	
	const 在星 的左边
	修饰的是指针的指向的内存
	1：指针不可以改变指向
	2：不可以通过指针改变其所指向内存的值

	const 在星的右边
	修饰的是指针变量的本身
	1：指针不可以改变指向
	2：可以通过指针改变其所指向内存的值

	注意：变量本身仍可以通过变量名去修改

	星号左右都有const 
	1：指针不可以改变指向
	2：不可以通过指针改变其所指向的内存的值
	*/


	//指针与字符串

	char *str = "hello";
	char str1[10] = "hello";

	str1[1] = 'E';
	printf("str1-----%s\n",str1);

	printf("str------%s\n\n", str);

	//指针与函数

	/*
	指针变量座位函数参数：将指针变量以实参的形式传递给函数，进行的是地址的传递。所以可以在函数中改变实参的值

	*/

	/*指向函数的指针  定义的格式为
	数据类型 （*指针变量名） （形参列表）

	例如 float （*p）（float x , float y）
	*/
	void (*ptest)(int a);

	ptest =test;
	ptest(1);
	//函数指针

	//指针的指针（多维指针）
	/* 例如
	int a;
	int *p = &a;
	int **p1 = &p;
	*/	 
	//二维指针
	int a = 10;
	int *p4 = &a;
	int **p3 = &p4;
	printf("a=%d  p4=%p  p1=%p\n", a, p4, p1);
	printf("*p4 = %d **p3= %d\n\n", *p4, **p3);

	//数组指针
	/*
	定义方式  类型名称  （*指针名）[数组长度]
	例如：
		int a[5]={1,2,3,4,5};
		int (*p)[5]=&a;
    定义时不能丢掉括号,因为[]优先级比*高，如果丢掉括号，会成为指针数组，

	数组指针定时的数组长度，元素类型，必须与 指向的数组给出的长度类型相同
	*/


	//指向数组长度为5的整型数组的指针
	//int (*p4)[5];

	//一个数组 类型为int* [10];
	int *p5[10];

	//数组指针指向的是整个数组  而不是数组元素  所以指针运算p+1相当于p+1*sizeof(数组名)

	//访问数组元素的方式：	a[0], *a, *(a + 1)  (*p)[0]

	int(*p6)[5];
	int array1[5] = {1,2,3,4,5};

	p6 = &array1;

	printf("(*p6)访问= %d   p[0]访问= %d\n\n",(*p6)[1],p6[0][3]);

	//指针数组 ： 一组类型相同的有序集合   类型名* 数组名[数组长度]

	/*
	例如：   int * ayyay_int[10]// 定义了一个数组由10个元素组成的，每个元素都是int* 指针 
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
