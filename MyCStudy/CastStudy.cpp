#include "CastStudy.h"


CastStudy::CastStudy()
{
}


CastStudy::~CastStudy()
{
}

class Buiding{};
class Animal{};
class Cat :public Animal{};

//static_cast  静态类型转换
void testStatic(){
	/*
	static_cast		用于内置的数据类型
					还有具有继承关系的指针或者引用
	*/
	int a = 97;
	char c = static_cast<char>(a);
	cout << c << endl;

	//转换具有继承关系的对象指针
	//父类指针转换成子类指针
	Animal *ani = NULL;
	Cat *cat = static_cast<Cat*>(ani);

	//子类指针转成父类指针
	Cat *soncat = NULL;
	Animal *aniFather = static_cast<Animal*>(soncat);

	//引用的转换 (父类转子类)
	Animal aniobj;
	Animal &aniref = aniobj;
	Cat &cat1 = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat &catref = catobj;
	Animal & anifather2 = static_cast<Animal&>(catref);
}

 //dynamic_cast  
void testDynamic(){
	/*
		dynamic_cast	只能转换具有继承关系的指针或者引用
						并且只能由子类转成集类型			
	*/

	//具有继承关系的指针
	//Animal * ani = NULL;
	//Cat *cat = dynamic_cast<Cat*>(ani);
	//报错的原因在于dynamic做了安全检查

	Cat *cat = NULL;
	Animal *ani = dynamic_cast<Animal*>(cat);
}

//const_cast  指针 引用或者对象指针
void testConst(){

	//基础数据类型
	int a = 10;
	const int& b = a;
	//b = 10;
	int & c = const_cast<int&>(b);
	c = 20;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	//指针
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);

	int *p3 = NULL;
	const int* p4 = const_cast<const int *>(p3);
	//增加或者去除变量的const性
}

//reinterpret_const  强制类型转换  无关的指针类型 ，包括函数指针都可以进行转换
typedef void(*FUNC1)(int,int);
typedef int(*FUNC2)(int , char *);
void testReinterpret(){
	//无关的指针类型都可以进行转换
	Buiding * buiding = NULL;
	Animal *ani = reinterpret_cast<Animal*>(buiding);

	//函数指针转换
	FUNC1 func1 = NULL;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
	
}



void CastStudy::run(){
	
	testStatic();
	testDynamic();
	testConst();
}
