#include "QuoteStudy.h"


//���õ�Ӧ��
void change_value(int *p){
	*p = 30;
}
void change_value1(int &p){
	p = 31;
}
void prints1(struct student *s){
	cout << s->id << "  " << s->name << endl;
}
void prints2(struct student &s){//���ݽ�ȥ��������  û�н��и�ֵ����
	cout << s.id << "  " << s.name << endl;
}
void QuoteStudy::run(){
	/*
	1:����û�ж��壬��һ�ֹ�ϵ����������������ԭ��ĳһ������ʵ�壩�Ĺ�ϵ���ʶ�������ԭ���ͱ���һ�£��Ҳ������ڴ棬�뱻���õı�������ͬ�ĵ�ַ
	2��������ʱ������ʼ����һ�����������ɸı�
	3���ɶ������ٴ����ã�������õĽ����ĳһ���������ж������
	4��&����ǰ����������ʱ������������Ϊ��ַ
	
	*/
	int a = 20;
	int b = 30;
	int *p = &a;
	*p = 30;
	
	p = &b;
	*p = 20;

	int &re = a; //int & ʹ��������������  re����a�ı���
	re = 50;

	cout << a << endl;

	int &re1 = re;//�������
	cout << re1 << endl;

	change_value(&a);  //�޸�a��ַ�����ַ�ʽ
	cout <<"a="<< a << endl;

	change_value1(a);  //�޸�a��ַ�����ַ�ʽ
	cout << "a=" << a << endl;

	struct student s = {12,"zhangsan"};
	prints1(&s);

	cout << "------------------------" << endl;
	prints2(s);

	cout << "���ýṹ��Ĵ�С" << sizeof(struct typeA) << endl;
	cout << "ָ��ṹ��Ĵ�С" << sizeof(struct typeB) << endl;
	
}