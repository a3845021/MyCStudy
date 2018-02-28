#include "TemplateStudy.h"


TemplateStudy::TemplateStudy()
{
}


TemplateStudy::~TemplateStudy()
{
}
//ģ��Ķ���
//ģ�弼�� ���Ͳ�����  ��д������Ժ�������
//Ϊ���ñ�������������ͨ���� ģ�庯��
template <class T> //template <typename T>��������Ҳ�� //���߱�����  ������Ҫдģ�庯��  ������ֵĶ�����Ҫ��㱨��
void MySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

/*  ģ��ͺ���������

	1��	��ͨ�������Խ����Զ����͵�ת��
		����ģ�岻�ܽ���ת��=��
	2�� ����ģ���������ͨ��������������
		C++���������ȿ�����ͨ����
		�������ģ����Բ���һ�����õ�ƥ�䣬��ô����ѡ��ģ��
		����ͨ����ģ��ʵ���б���﷨�޶�������ֻ��ͨ��ģ��ƥ��   ���磺MySwap<>(a,b)


*/

//����ģ��ʹ��
void test01(){

	//�Զ������Ƶ�
	int a = 10;
	int b = 20;
	MySwap(a,b);
	cout << "a:" << a << "b:" << b << endl;

	double da = 1.13;
	double db = 1.14;
	MySwap(da, db);
	cout << "da:" << da << "db:" << db << endl;

	//��ʾ�� ָ������    ����ȥ��a��b  ����ת����int
	MySwap<int>(a, b);
}


//��ģ��
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

//�̳���ģ��(��ģ��������ͨ��)
//�����������  ��������ǲ���Ҫ��������ڴ�
class SubPerson :public Person < int > {
};

//��ģ��������ģ��  
template<class T>
class Sub1Person :public Person < T > {

};
void test02(){
	//����ģ���ڵ��õ�ʱ��  �����Զ������Ƶ�
	//��ģ�������ʽָ������
	Person<int> p(10, 30);
	p.show();
}


void TemplateStudy::run(){
	test01();
	test02();
}