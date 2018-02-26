#include "PolymorphicStudy.h"


PolymorphicStudy::PolymorphicStudy()
{
}


PolymorphicStudy::~PolymorphicStudy()
{
}

//岳不群
class  Yuebuqun
{
public:
	Yuebuqun(){
	
	}
	Yuebuqun(string kongfu){
		this->kongfu = kongfu;
	}
	virtual void fight(){  //标识修饰一个成员方法是一个虚函数
		cout << "岳不群" << "使出了" << kongfu.c_str() << "打人" << endl;
	}
	string kongfu;
};

//林平之 继承了岳不群
class Linpingzhi :public Yuebuqun
{
public:
	Linpingzhi(){
	
	}
	Linpingzhi(string kongfu) :Yuebuqun(kongfu)
	{
	}
	//如果说父亲中有一个虚函数是fight（），子类如果去重写这个虚函数
	void fight()
	{
		cout << "林平之" << "使出了" << kongfu.c_str() << "打人" << endl;
	}
};

void fightPeople(Yuebuqun *hero){
	hero->fight();  //希望传递进来的如果是子类，调用子类的fight
					//如果传递进来的父亲类，调用父类的fight
					//这种行为都是多态行为
}





void PolymorphicStudy::run(){
	/*
	多态发生的三个 必要条件
		1：要有继承
		2：要有虚函数重写
		3： 父类指针或引用指向子类对象
	*/


	Yuebuqun *xiaoyy = new Yuebuqun("葵花宝典");
	//xiaoyy->fight();

	Linpingzhi *xiaopp = new Linpingzhi("辟邪剑谱");
	//xiaopp->fight();

	fightPeople(xiaoyy);
	fightPeople(xiaopp);

	Linpingzhi xiaop("lalal");
	fightPeople(&xiaop);
	//编译器默认做了一个安全的处理，编译器认为不管传递是子类对象还是父类对象
	//如果统一执行父类d方法那么一定是可以被成功执行 


	delete xiaoyy;
	delete xiaopp;

	//虚析构函数的学习
	/*
		如果B类继承A     当B类被delete的时候   A类的析构函数必须是virtual B的析构才会执行
	*/

	//重载  重写 重定义
	/*
	重载：一定是在同一个作用域下
	重定义：是发生在两个不用的类中，  一个是父类 一个是子类
	重写：虚函数重写
	*/

	//-----------多态的实现原理------------
	//虚函数表和vptr指针
	/*
	1：当在类中声明虚函数时，编译器会在类中声明一个虚函数表
	虚函数表时一个存储类成员函数指针的数据结构
	虚函数表时由编译器自动生成与维护的
	virtral成员函数会被编译器放入虚函数表中
	存在虚函数时，每个对象中都有一个指向虚函数表的vptr指针
	
	*/


}
