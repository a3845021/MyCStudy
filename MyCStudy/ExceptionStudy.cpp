#include "ExceptionStudy.h"


ExceptionStudy::ExceptionStudy()
{
}


ExceptionStudy::~ExceptionStudy()
{
}

int divide(int x,int y){
	if (y == 0)
	{
		throw y;//抛出异常
	}
	return x / y;
}

//这个函数只能抛出 int float char 三种类型的异常  抛出其他的就会报错，有些编译器会忽略
void func() throw(int,float,char){
	throw "abc";
}

//不能抛出任何异常
void func1() throw(){

}

class MyException{
public:
	MyException(char * str){
		error = new char[strlen(str)+1];
		strcpy(error,str);
	}
	~MyException(){
		if (error != NULL){
			//delete[] error;
			error = NULL;
		}
	}
	void what(){
		cout << error << endl;
	}
	char * error;
};

void func2(){
	throw MyException("我抛出的异常");
}

void ExceptionStudy::run(){
	/*
		1：C++中的异常时跨函数的    异常必须处理
		2：异常被抛出后，从进入try起，到异常被抛出前，这期间在栈上构造的所有对象，都会被自动析构，析构的顺序与构造的顺序相反，这个过程称为栈的解旋
			
	*/
	//试着 去捕获异常
	try{
		divide(10, 0);
	}
	catch(int e){
		cout << "除数为：" << e << endl;
	}

	try{
		func();
	}
	catch (int e){//捕获int类型的错误
	
	}
	catch (char e){//捕获char类型的错误
	
	}
	catch (...){//捕获任何类型的错误
		
	}

	try{
		func2();
	}
	catch(MyException e){
		e.what();
	}
}