#include "VariableStudy.h"


VariableStudy::VariableStudy()
{
}


VariableStudy::~VariableStudy()
{
}

void VariableStudy::run(){
	
	/*
	//C++�����ı���
	���� 
	long long 
	unsigned long long
	������
	long double
	��ʾ�ķ�Χ��� û�б��ʵ�����
	*/
	//wchar_t  ���ַ�
	/*
	ascll:  һ���ַ�
	���� �������ַ�
	*/
	//ʹ�ã�
	char *cnchs="����й�!";
	wchar_t wt[]=L"����й�!";//���ַ�

	cout << sizeof(cnchs) << endl;  //11
	cout << sizeof(wt) << endl;//12  ������\n  ͬ�����������ֽ�

	cout << strlen(cnchs) << endl;
	cout << wcslen(wt) << endl;
	//wchar_t ��windows������һ�ֱ�׼���ַ�������



}