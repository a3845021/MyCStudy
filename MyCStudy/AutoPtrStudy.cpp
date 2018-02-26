#include "AutoPtrStudy.h"

class A{
public:
	A(int a){
		this->a = a;
	}
	void func(){
		cout << "a = " << this->a << endl;
	}
	~A(){
		cout << "~A........" << endl;
	}
private:
	int a;
};

AutoPtrStudy::AutoPtrStudy()
{
}


AutoPtrStudy::~AutoPtrStudy()
{
}

void AutoPtrStudy::test1(){
#if 0  //��ͨд��
	A* a = new A(10);
	a->func();
	(*a).func();
	delete a;
#endif
	auto_ptr<A> ptr(new A(10));
	ptr->func();
	(*ptr).func();
}

//�Զ���һ������ָ��
class MyAutoPtr
{
public:
	MyAutoPtr(A * ptr){
		this->ptr = ptr;
	}
	~MyAutoPtr(){
		if (this->ptr != NULL){
			delete ptr;
			this->ptr = NULL;
		}
	}
	A* operator->(){
		return this->ptr;
	}
	A& operator*(){
		return *ptr;
	}
private:
	A* ptr;

};

void AutoPtrStudy::test2(){
	MyAutoPtr my_p(new A(10));
	my_p->func();
	(*my_p).func();
}

void AutoPtrStudy::run(){
	//����ָ��Ķ���
	//int *p = new int;
	//auto_ptr<int> ptr(new int);
	//*ptr = 20;

	//test1();
	test2();
}