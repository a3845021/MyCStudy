#include "CastStudy.h"


CastStudy::CastStudy()
{
}


CastStudy::~CastStudy()
{
}

class Buiding{};
class Animal{};
class Cat :public Animal{};

//static_cast  ��̬����ת��
void testStatic(){
	/*
	static_cast		�������õ���������
					���о��м̳й�ϵ��ָ���������
	*/
	int a = 97;
	char c = static_cast<char>(a);
	cout << c << endl;

	//ת�����м̳й�ϵ�Ķ���ָ��
	//����ָ��ת��������ָ��
	Animal *ani = NULL;
	Cat *cat = static_cast<Cat*>(ani);

	//����ָ��ת�ɸ���ָ��
	Cat *soncat = NULL;
	Animal *aniFather = static_cast<Animal*>(soncat);

	//���õ�ת�� (����ת����)
	Animal aniobj;
	Animal &aniref = aniobj;
	Cat &cat1 = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat &catref = catobj;
	Animal & anifather2 = static_cast<Animal&>(catref);
}

 //dynamic_cast  
void testDynamic(){
	/*
		dynamic_cast	ֻ��ת�����м̳й�ϵ��ָ���������
						����ֻ��������ת�ɼ�����			
	*/

	//���м̳й�ϵ��ָ��
	//Animal * ani = NULL;
	//Cat *cat = dynamic_cast<Cat*>(ani);
	//�����ԭ������dynamic���˰�ȫ���

	Cat *cat = NULL;
	Animal *ani = dynamic_cast<Animal*>(cat);
}

//const_cast  ָ�� ���û��߶���ָ��
void testConst(){

	//������������
	int a = 10;
	const int& b = a;
	//b = 10;
	int & c = const_cast<int&>(b);
	c = 20;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	//ָ��
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);

	int *p3 = NULL;
	const int* p4 = const_cast<const int *>(p3);
	//���ӻ���ȥ��������const��
}

//reinterpret_const  ǿ������ת��  �޹ص�ָ������ ����������ָ�붼���Խ���ת��
typedef void(*FUNC1)(int,int);
typedef int(*FUNC2)(int , char *);
void testReinterpret(){
	//�޹ص�ָ�����Ͷ����Խ���ת��
	Buiding * buiding = NULL;
	Animal *ani = reinterpret_cast<Animal*>(buiding);

	//����ָ��ת��
	FUNC1 func1 = NULL;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
	
}



void CastStudy::run(){
	
	testStatic();
	testDynamic();
	testConst();
}
