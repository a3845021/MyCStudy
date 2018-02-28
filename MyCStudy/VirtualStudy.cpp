#include "VirtualStudy.h"


VirtualStudy::VirtualStudy()
{
}


VirtualStudy::~VirtualStudy()
{
}
//图形类
/*
如果说一个类  拥有一个纯虚函数
就称这个类是抽象类
不管这个类中有没有成员属性，只要这个类有纯虚函数   就是一个抽象类，抽象类是不能实例化的
*/
class Shap{
public:
	//求图形面积的方法
	//表示图形类声明的一个冯方法getArea()，他是一个纯虚函数，没有函数的实现
	virtual double getArea() = 0;
	Shap(){}
	virtual ~Shap(){}
};

//正方形
/*
	如果说一个普通类，继承拥有纯虚函数的类，如果不重写纯虚函数依然是一个抽象类
	依然不能被实例化，如果想实例化，必须重写这个父类中所有的纯虚函数
*/
class Rect :public Shap{
public:
	Rect(int a){
		this->a = a;
	}
	virtual double getArea(){
		cout << "正方形" << endl;
		return a*a;
	}
private:
	int a;

};

class Circle:public Shap
{
public:
	Circle(int r){
		this->r = r;
	}
	~Circle(){
		cout << "~Circle().........." << endl;
	}
	virtual double getArea(){
		cout << "三角形" << endl;
		return 3.14*r*r;
	}

private:
	int r;
};

class Interface1{
public:
	virtual void func1(int a, int b) = 0;
	virtual void func3(int a) = 0;
	Interface1(){}
	virtual ~Interface1(){}
};

class Interface2{
public:
	virtual void func2(int a) = 0;
	virtual ~Interface2(){}
};

class Child :public Interface1,public Interface2{
public:
	Child(int a){
	
	}
	~Child(){
		cout << "~Child()...." << endl;
	}
	virtual void func1(int a, int b){
		cout << "func1" << endl;
	}
	virtual void func3(int a){
		cout << "func3" << endl;
	}

	virtual void func2(int a) {
		cout << "func2" << endl;
	}
};

//业务层  面向抽象类编程
void VirtualStudy::run(){

	//run 中所有使用的变量类型都是抽象类shap的类型
	Shap *sp1 = new Rect(10);
	sp1->getArea();

	Shap *sp2 = new Circle(20);
	sp2->getArea();
	//纯虚函数和多继承

	delete sp2;
	delete sp1;

	Interface1 *if1 = new Child(10);
	if1->func1(1,1);
	if1->func3(2);
	delete if1;

	Interface2 *if2 = new Child(20);
	if2->func2(2);
	delete if2;
}
