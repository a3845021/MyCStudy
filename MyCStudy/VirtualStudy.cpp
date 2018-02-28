#include "VirtualStudy.h"


VirtualStudy::VirtualStudy()
{
}


VirtualStudy::~VirtualStudy()
{
}
//ͼ����
/*
���˵һ����  ӵ��һ�����麯��
�ͳ�������ǳ�����
�������������û�г�Ա���ԣ�ֻҪ������д��麯��   ����һ�������࣬�������ǲ���ʵ������
*/
class Shap{
public:
	//��ͼ������ķ���
	//��ʾͼ����������һ���뷽��getArea()������һ�����麯����û�к�����ʵ��
	virtual double getArea() = 0;
	Shap(){}
	virtual ~Shap(){}
};

//������
/*
	���˵һ����ͨ�࣬�̳�ӵ�д��麯�����࣬�������д���麯����Ȼ��һ��������
	��Ȼ���ܱ�ʵ�����������ʵ������������д������������еĴ��麯��
*/
class Rect :public Shap{
public:
	Rect(int a){
		this->a = a;
	}
	virtual double getArea(){
		cout << "������" << endl;
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
		cout << "������" << endl;
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

//ҵ���  �����������
void VirtualStudy::run(){

	//run ������ʹ�õı������Ͷ��ǳ�����shap������
	Shap *sp1 = new Rect(10);
	sp1->getArea();

	Shap *sp2 = new Circle(20);
	sp2->getArea();
	//���麯���Ͷ�̳�

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
