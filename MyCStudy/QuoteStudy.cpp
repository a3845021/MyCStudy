#include "QuoteStudy.h"


//引用的应用
void change_value(int *p){
	*p = 30;
}
void change_value1(int &p){
	p = 31;
}
void prints1(struct student *s){
	cout << s->id << "  " << s->name << endl;
}
void prints2(struct student &s){//传递进去的是引用  没有进行赋值操作
	cout << s.id << "  " << s.name << endl;
}
void QuoteStudy::run(){
	/*
	1:引用没有定义，是一种关系型声明，声明他和原有某一变量（实体）的关系，故而类型与原类型保持一致，且不分配内存，与被引用的变量有相同的地址
	2：声明的时候必须初始化，一经声明，不可改变
	3：可对引用再次引用，多次引用的结果是某一个变量具有多个别名
	4：&符号前有数据类型时是引用其他皆为地址
	
	*/
	int a = 20;
	int b = 30;
	int *p = &a;
	*p = 30;
	
	p = &b;
	*p = 20;

	int &re = a; //int & 使用引用数据类型  re就是a的别名
	re = 50;

	cout << a << endl;

	int &re1 = re;//多次引用
	cout << re1 << endl;

	change_value(&a);  //修改a地址的两种方式
	cout <<"a="<< a << endl;

	change_value1(a);  //修改a地址的两种方式
	cout << "a=" << a << endl;

	struct student s = {12,"zhangsan"};
	prints1(&s);

	cout << "------------------------" << endl;
	prints2(s);

	cout << "引用结构体的大小" << sizeof(struct typeA) << endl;
	cout << "指针结构体的大小" << sizeof(struct typeB) << endl;
	
}