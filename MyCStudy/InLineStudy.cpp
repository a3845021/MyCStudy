#include "InLineStudy.h"

inline void printAB(int a ,int b){
	cout << a << b << endl;
}
void InLineStudy::func(int a){
	cout << "a = "<<a << endl;
}
InLineStudy::InLineStudy()
{
}


InLineStudy::~InLineStudy()
{
}
void InLineStudy::run(){
	/*
	特点：
	1：内联函数声明时 inline关键字必须和函数定义结合在一起否则编译器会忽略内联请求
	2：C++编译器直接将函数数体插入在函数调用的地方
	3：内联函数没有普通函数调用时的额外开销（压栈，跳转，返回）
	4：内联函数是一种特殊的函数，具有普通函数的特征（参数检查，返回类型等）
	5：内联函数由编译器处理，直接将编译后的函数体插入调用的地方
		宏代码片段 由编译器处理  进行简单的文本替换，有没有任何便宜过程
    6:C++中内联编译的限制
		1：不能存在任何形式的循环语句
		2：不能存在过多的条件判断语句
		3：函数体不能过于的庞大
		4：不能对函数进行取址操作
		5：内联函数声明必须在调用语句之前
	*/
	func(1);
}