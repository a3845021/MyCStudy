#include "CoutCinStudy.h"


CoutCinStudy::CoutCinStudy()
{
}


CoutCinStudy::~CoutCinStudy()
{
}

struct person{
	int age;
	char name[20];
};


void CoutCinStudy::run(){
	//int i1,i2,i3;
	//cin >> i1>>i2>>i3;
	//cout << "i=" << i1 << "i2=" <<i2 << "i3=" <<i3<< endl;//endl相当于换行


	//输出格式
	int x = 30, y = 300, z = 1024;
	cout << x << ";" << y << ";" << z << ";" << endl;  //标准的按照十进制的方式输出
	cout.setf(ios::hex,ios::basefield); //以十六进制的方式输出
	cout << x << ";" << y << ";" << z << ";" << endl;
	cout.unsetf(ios::hex);
	cout << x << ";" << y << ";" << z << ";" << endl;
	cout.setf(ios::oct); //以八进制的方式输出，此设置不取消一直有效
	cout <<"八进制。。。"<< x << ";" << y << ";" << z << ";" << endl;
	cout.unsetf(ios::oct);



}
