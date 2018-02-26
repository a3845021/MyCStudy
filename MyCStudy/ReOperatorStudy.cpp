#include "ReOperatorStudy.h"



//����������
ReOperatorStudy::ReOperatorStudy()
{
}


ReOperatorStudy::~ReOperatorStudy()
{
}

class Complex{
public :
	Complex(int a,int b){
		this->a = a;
		this->b = b;
	}
	void printComplex(){
		cout << "(" << this->a << "," << this->b << ")" << endl;
	}
	friend Complex complexAdd(Complex &com1, Complex &com2);
	friend Complex operator+(Complex &com1, Complex &com2);
	friend Complex & operator+=(Complex& c1, Complex & c2);
	friend Complex & operator++(Complex& c1);
	friend const Complex operator++(Complex &c1, int);
	friend ostream& operator<<(ostream& os, Complex &c);
	friend istream& operator>>(istream &is, Complex &c);
private:
	int a;
	int b;
};

Complex complexAdd(Complex &com1,Complex &com2){
	Complex temp(com1.a + com2.a, com1.b + com2.b);
	return temp;
}

//���������ض����ʽ
Complex operator+(Complex &com1, Complex &com2){
	Complex temp(com1.a + com2.a, com1.b + com2.b);
	return temp;
}

class ComplexTest{
public:
	ComplexTest(int a){
		this->a = a;
	}
	void printA(){
		cout << "a = " << this->a << endl;
	}
	friend ComplexTest operator+(ComplexTest &com1, ComplexTest &com2);
private:
	int a;
};

ComplexTest operator+(ComplexTest &com1, ComplexTest &com2){
	ComplexTest temp(com1.a + com2.a);
	return temp;
}

//��Ŀ���������
Complex & operator+=(Complex& c1, Complex & c2)
{
	c1.a += c2.a;
	c1.b += c2.b;
	return c1;
}
//++�����  (ǰ++   ����++a)
Complex & operator++(Complex& c1){
	c1.a++;
	c1.b++;
	return c1;
}
//���ص��Ǻ�++�����  ��++  �������������  ���Լ���const

const Complex operator++(Complex &c1, int)
{
	Complex temp(c1.a,c1.b);
	c1.a++;
	c1.b++;
	return temp;
}

//�������Ʋ���������   <<������ֻ��д��ȫ�֣����ܹ�д�ڳ�Ա�����У��������˳��ͻ�䷴  �ӡ���cout
ostream& operator<<(ostream& os,Complex &c){
	os << "(" << c.a << "," << c.b << ")";
	return os;
}
 
istream& operator>>(istream &is ,Complex &c){
	cout << "a:";
	is >> c.a;
	cout << "b:";
	is >> c.b;
	return is;
}




void ReOperatorStudy::run(){
	/*
	����
	1��C++�������û��Զ����µ��������ֻ�ܶ����е�C++�������������

	2�����ܱ����صò�����
	.         ��Աѡ���
	.*        ��Ա����ѡ���
	::        �����������
	?:        ����������
	
	3�� ���ز��ܸı�������������ø���
	4�����ز��� �ı�����������ȼ���
	5�����ز��ܸı�������Ľ����
	6������������ĺ���������Ĭ�ϵĲ���
	7�����ر���Ҫ��һ���Զ������������
	8����=���� ��&���û���������
	9��+�������Ӧ��д�ӷ�   ��Ҫȥд����
	10����������غ�����������ĳ�Ա������Ҳ�����������Ԫ�������������Ǽȷ���ĳ�Ա����Ҳ������Ԫ��������ͨ����
	*/
	Complex com1(10,90);
	Complex com2(20, 20);
	Complex com3 = complexAdd(com1, com2);
	com3.printComplex();

	Complex com4 = com1 +  com2;
	com4.printComplex();

	ComplexTest comt1(20);
	ComplexTest comt2(30);

	ComplexTest comt3 = comt1 + comt2;
	comt3.printA();

	Complex c1(1,2);
//	++c1;                //ǰ++
	c1++;				 //��++	
	c1.printComplex();


	Complex c2(2, 4);
	cout << c2 << endl;

}
