#include "FriendStudy.h"

//��Ԫ����
class Point{
public:
	friend double PointDistance(Point &p1, Point &p2);  //��Ԫ�Ķ���
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
//��Ԫ��
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
		1����Ԫ��ϵ���ܱ��̳�
		2����Ԫ��ϵ�ǵ���ģ������н����ԣ���B����A����Ԫ����A��һ������B����Ԫ��Ҫ�������Ƿ�����Ӧ������
		3����Ԫ��ϵ�����д����ԣ�����B����A����Ԫ����C��B����Ԫ����ô��C��һ������A����Ԫ��ͬ��Ҫ�������Ƿ�����Ӧ������
	*/

	Point p1(1,2);
	Point p2(2,2);

	cout << PointDistance(p1, p2) << endl;

	A a(30);
	B b(40);
	a.printA();
	b.printB();
}