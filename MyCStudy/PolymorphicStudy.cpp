#include "PolymorphicStudy.h"


PolymorphicStudy::PolymorphicStudy()
{
}


PolymorphicStudy::~PolymorphicStudy()
{
}

//����Ⱥ
class  Yuebuqun
{
public:
	Yuebuqun(){
	
	}
	Yuebuqun(string kongfu){
		this->kongfu = kongfu;
	}
	virtual void fight(){  //��ʶ����һ����Ա������һ���麯��
		cout << "����Ⱥ" << "ʹ����" << kongfu.c_str() << "����" << endl;
	}
	string kongfu;
};

//��ƽ֮ �̳�������Ⱥ
class Linpingzhi :public Yuebuqun
{
public:
	Linpingzhi(){
	
	}
	Linpingzhi(string kongfu) :Yuebuqun(kongfu)
	{
	}
	//���˵��������һ���麯����fight�������������ȥ��д����麯��
	void fight()
	{
		cout << "��ƽ֮" << "ʹ����" << kongfu.c_str() << "����" << endl;
	}
};

void fightPeople(Yuebuqun *hero){
	hero->fight();  //ϣ�����ݽ�������������࣬���������fight
					//������ݽ����ĸ����࣬���ø����fight
					//������Ϊ���Ƕ�̬��Ϊ
}





void PolymorphicStudy::run(){
	/*
	��̬���������� ��Ҫ����
		1��Ҫ�м̳�
		2��Ҫ���麯����д
		3�� ����ָ�������ָ���������
	*/


	Yuebuqun *xiaoyy = new Yuebuqun("��������");
	//xiaoyy->fight();

	Linpingzhi *xiaopp = new Linpingzhi("��а����");
	//xiaopp->fight();

	fightPeople(xiaoyy);
	fightPeople(xiaopp);

	Linpingzhi xiaop("lalal");
	fightPeople(&xiaop);
	//������Ĭ������һ����ȫ�Ĵ�����������Ϊ���ܴ�������������Ǹ������
	//���ͳһִ�и���d������ôһ���ǿ��Ա��ɹ�ִ�� 


	delete xiaoyy;
	delete xiaopp;

	//������������ѧϰ
	/*
		���B��̳�A     ��B�౻delete��ʱ��   A�����������������virtual B�������Ż�ִ��
	*/

	//����  ��д �ض���
	/*
	���أ�һ������ͬһ����������
	�ض��壺�Ƿ������������õ����У�  һ���Ǹ��� һ��������
	��д���麯����д
	*/

	//-----------��̬��ʵ��ԭ��------------
	//�麯�����vptrָ��
	/*
	1���������������麯��ʱ��������������������һ���麯����
	�麯����ʱһ���洢���Ա����ָ������ݽṹ
	�麯����ʱ�ɱ������Զ�������ά����
	virtral��Ա�����ᱻ�����������麯������
	�����麯��ʱ��ÿ�������ж���һ��ָ���麯�����vptrָ��
	
	*/


}
