#include "ExceptionStudy.h"


ExceptionStudy::ExceptionStudy()
{
}


ExceptionStudy::~ExceptionStudy()
{
}

int divide(int x,int y){
	if (y == 0)
	{
		throw y;//�׳��쳣
	}
	return x / y;
}

//�������ֻ���׳� int float char �������͵��쳣  �׳������ľͻᱨ����Щ�����������
void func() throw(int,float,char){
	throw "abc";
}

//�����׳��κ��쳣
void func1() throw(){

}

class MyException{
public:
	MyException(char * str){
		error = new char[strlen(str)+1];
		strcpy(error,str);
	}
	~MyException(){
		if (error != NULL){
			//delete[] error;
			error = NULL;
		}
	}
	void what(){
		cout << error << endl;
	}
	char * error;
};

void func2(){
	throw MyException("���׳����쳣");
}

void ExceptionStudy::run(){
	/*
		1��C++�е��쳣ʱ�纯����    �쳣���봦��
		2���쳣���׳��󣬴ӽ���try�𣬵��쳣���׳�ǰ�����ڼ���ջ�Ϲ�������ж��󣬶��ᱻ�Զ�������������˳���빹���˳���෴��������̳�Ϊջ�Ľ���
			
	*/
	//���� ȥ�����쳣
	try{
		divide(10, 0);
	}
	catch(int e){
		cout << "����Ϊ��" << e << endl;
	}

	try{
		func();
	}
	catch (int e){//����int���͵Ĵ���
	
	}
	catch (char e){//����char���͵Ĵ���
	
	}
	catch (...){//�����κ����͵Ĵ���
		
	}

	try{
		func2();
	}
	catch(MyException e){
		e.what();
	}
}