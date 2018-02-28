#include "TemplateStudy.h"


TemplateStudy::TemplateStudy()
{
}


TemplateStudy::~TemplateStudy()
{
}
//模板的定义
//模板技术 类型参数化  编写代码可以忽略类型
//为了让编译器区分是普通函数 模板函数
template <class T> //template <typename T>这样定义也行 //告诉编译器  我下面要写模板函数  看到奇怪的东西不要随便报错
void MySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

/*  模板和函数的区别

	1：	普通函数可以进行自动类型的转换
		函数模板不能进行转化=换
	2： 函数模板可以像普通函数那样被重载
		C++编译器优先考虑普通函数
		如果函数模板可以产生一个更好的匹配，那么优先选择模板
		可以通过空模板实参列表的语法限定编译器只能通过模板匹配   例如：MySwap<>(a,b)


*/

//函数模板使用
void test01(){

	//自动类型推导
	int a = 10;
	int b = 20;
	MySwap(a,b);
	cout << "a:" << a << "b:" << b << endl;

	double da = 1.13;
	double db = 1.14;
	MySwap(da, db);
	cout << "da:" << da << "db:" << db << endl;

	//显示的 指定类型    传进去的a和b  都会转化成int
	MySwap<int>(a, b);
}


//类模板
template <class T>
class  Person
{
public:
	Person(T id,T age){
		this->id = id;
		this->age = age;
	}
	~Person(){}

	void show(){
		cout << "id:" << id << "age:" << age << endl;
	}

public:
	T id;
	T age;
};

//继承类模板(类模板派生普通类)
//类区定义对象  这个对象是不需要编译分配内存
class SubPerson :public Person < int > {
};

//类模板派生类模板  
template<class T>
class Sub1Person :public Person < T > {

};
void test02(){
	//函数模板在调用的时候  可以自动类型推导
	//类模板必须显式指定类型
	Person<int> p(10, 30);
	p.show();
}


void TemplateStudy::run(){
	test01();
	test02();
}