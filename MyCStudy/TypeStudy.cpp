#include "TypeStudy.h"


TypeStudy::TypeStudy()
{
}


TypeStudy::~TypeStudy()
{
}

void TypeStudy::run(){
	auto i=9;
	cout << i << endl;

	auto a="test";
	cout << a << endl;
	auto *z = "zxx";
	cout << typeid(z).name() << endl;//打印变量的类型名字

	//auto：匿名函数
	auto ptr = [](){
		cout << "zxq" << endl;
	};

	cout << typeid(ptr).name() << endl;
	//ptr();
}