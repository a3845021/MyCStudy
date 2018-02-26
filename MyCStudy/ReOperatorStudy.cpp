#include "ReOperatorStudy.h"



//操作符重载
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

//操作符重载定义格式
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

//三目操作运算符
Complex & operator+=(Complex& c1, Complex & c2)
{
	c1.a += c2.a;
	c1.b += c2.b;
	return c1;
}
//++运算符  (前++   比如++a)
Complex & operator++(Complex& c1){
	c1.a++;
	c1.b++;
	return c1;
}
//重载的是后++运算符  后++  不能连续的相加  所以加上const

const Complex operator++(Complex &c1, int)
{
	Complex temp(c1.a,c1.b);
	c1.a++;
	c1.b++;
	return temp;
}

//左移右移操作符重载   <<操作符只能写在全局，不能够写在成员方法中，否则调用顺序就会变反  从《《cout
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
	规则
	1：C++不允许用户自定义新的运算符，只能对已有的C++运算符进行重载

	2：不能被重载得操作符
	.         成员选择符
	.*        成员对象选择符
	::        域解析操作符
	?:        条件操作符
	
	3： 重载不能改变运算符运算对象得个数
	4：重载不能 改变运算符的优先级别
	5：重载不能改变运算符的结合性
	6：重载运算符的函数不能有默认的参数
	7：重载必须要有一个自定义的数据类型
	8：“=”和 “&”用户不必重载
	9：+法运算就应该写加法   不要去写减法
	10：运算符重载函数可以是类的成员函数，也可以是类的友元函数，还可以是既非类的成员函数也不是友元函数的普通函数
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
//	++c1;                //前++
	c1++;				 //后++	
	c1.printComplex();


	Complex c2(2, 4);
	cout << c2 << endl;

}
