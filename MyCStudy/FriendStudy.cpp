#include "FriendStudy.h"

//友元方法
class Point{
public:
	friend double PointDistance(Point &p1, Point &p2);  //友元的定义
	Point(int x,int y){
		this->x = x;
		this->y = y;
	}
	int getX(){
		return this->x;
	}

	int getY(){
		return this->y;
	}
 
private:
	int x;
	int y;
};

double PointDistance(Point &p1,Point &p2){
	double dis;
	int dd_x = p1.x - p2.x;
	int dd_y = p1.y - p2.y;

	dis = sqrt(dd_x*dd_x + dd_y*dd_y);
	return dis;
}

//--------------------------------------
//友元类
class B;
class A{
public:
	friend class B;
	A(int a){
		this->a = a;
	}
	int getA(){
		return this->a;
	}

	void printA();

private :
	int a;
};

class B{

public:
	B(int b){
		this->b = b;
	}

	void printB(){
		cout << "b = " << b << endl;

		A a(10);
		cout << a.a << endl;
	}
	friend class A;
private:
	int b;
};

void A::printA(){
	cout << "a = " << a << endl;
	B b(30);
	cout << b.b << endl;
}

FriendStudy::FriendStudy()
{
}


FriendStudy::~FriendStudy()
{
}

void FriendStudy::run(){

	/*
		1：友元关系不能被继承
		2：友元关系是单向的，不具有交换性，若B是类A的友元，类A不一定是类B的友元，要看类中是否有相应的声明
		3：友元关系不具有传递性，若类B是类A的友元，类C是B的友元，那么类C不一定是类A的友元，同样要看类中是否有相应的声明
	*/

	Point p1(1,2);
	Point p2(2,2);

	cout << PointDistance(p1, p2) << endl;

	A a(30);
	B b(40);
	a.printA();
	b.printB();
}