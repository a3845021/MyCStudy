#include "ReLoadStudy.h"

int func(int a,int b){
	cout << "func1" << endl;
	return 0;
}
int func(int a ,char b){
	cout << "func2" << endl;
	return 0;
}
//����һ�к�������
typedef int(MY_FUNC)(int, int);

//����һ��ָ�������͵�ָ������
typedef int(*MY_FUNC_P)(int ,int  );
ReLoadStudy::ReLoadStudy()
{
}

ReLoadStudy::~ReLoadStudy()
{
}
void ReLoadStudy::run(){
	/*
	���صĹ���
	1����������ͬ
	2�������ĸ�����ͬ�����������Ͳ�ͬ��������˳��ͬ�����ɹ�������
	3������ֵ���Ͳ�ͬ�򲻿��Թ�������

	����׼��
	1���ϸ�ƥ�䣬�ҵ������
	2��ͨ����ʽת��Ѱ��һ��ƥ�䣬�ҵ������
	*/
	func(1,'c');

	//���غͺ���ָ��

	//1:
	MY_FUNC *fp = NULL;
	fp = func;
	fp(1,20);

	//2��
	MY_FUNC_P fp1 = NULL;
	fp1 = func;
	fp1(2,45);

	//3:
	int(*fp3)(int, int) = NULL;
	fp3 = func;
	fp3(10, 30);
}