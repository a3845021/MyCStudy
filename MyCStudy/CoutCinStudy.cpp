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
	//cout << "i=" << i1 << "i2=" <<i2 << "i3=" <<i3<< endl;//endl�൱�ڻ���


	//�����ʽ
	int x = 30, y = 300, z = 1024;
	cout << x << ";" << y << ";" << z << ";" << endl;  //��׼�İ���ʮ���Ƶķ�ʽ���
	cout.setf(ios::hex,ios::basefield); //��ʮ�����Ƶķ�ʽ���
	cout << x << ";" << y << ";" << z << ";" << endl;
	cout.unsetf(ios::hex);
	cout << x << ";" << y << ";" << z << ";" << endl;
	cout.setf(ios::oct); //�԰˽��Ƶķ�ʽ����������ò�ȡ��һֱ��Ч
	cout <<"�˽��ơ�����"<< x << ";" << y << ";" << z << ";" << endl;
	cout.unsetf(ios::oct);



}
