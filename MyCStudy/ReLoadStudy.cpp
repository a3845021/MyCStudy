#include "ReLoadStudy.h"

int func(int a,int b){
	cout << "func1" << endl;
	return 0;
}
int func(int a ,char b){
	cout << "func2" << endl;
	return 0;
}
//定义一中函数类型
typedef int(MY_FUNC)(int, int);

//定义一个指向函数类型的指针类型
typedef int(*MY_FUNC_P)(int ,int  );
ReLoadStudy::ReLoadStudy()
{
}

ReLoadStudy::~ReLoadStudy()
{
}
void ReLoadStudy::run(){
	/*
	重载的规则
	1：函数名相同
	2：参数的个数不同，参数的类型不同，参数的顺序不同，均可构成重载
	3：返回值类型不同则不可以构成重载

	调用准则：
	1：严格匹配，找到则调用
	2：通过隐式转换寻求一个匹配，找到则调用
	*/
	func(1,'c');

	//重载和函数指针

	//1:
	MY_FUNC *fp = NULL;
	fp = func;
	fp(1,20);

	//2：
	MY_FUNC_P fp1 = NULL;
	fp1 = func;
	fp1(2,45);

	//3:
	int(*fp3)(int, int) = NULL;
	fp3 = func;
	fp3(10, 30);
}