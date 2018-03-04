#include "StreamStudy.h"
#include <fstream>

StreamStudy::StreamStudy()
{
}


StreamStudy::~StreamStudy()
{
}
//�������ļ�����  �������л�
class Person
{
public:
	Person(){}
	Person(int age,int id){
		this->age = age;
		this->id = id;
	}
	~Person(){}
	void show(){
		cout << "age=" << age << ",id=" << id << endl;
	}

private:
	int age;
	int id;

};

void StreamStudy::run(){
	//�ļ���д����
	char * fileName = "C:\\MyWork\\SVN\\reource\\Code\\MyCStudy\\MyCStudy\\source.txt";
	char * targetName = "C:\\MyWork\\SVN\\reource\\Code\\MyCStudy\\MyCStudy\\target.txt";
	ifstream ism(fileName, ios::in);//ֻ����ʽ���ļ�
	ofstream osm(targetName, ios::out | ios::app);

	if (!ism){
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	//���ļ�
	char ch;
	while (ism.get(ch)){
		cout << ch;
		osm.put(ch);
	}

	//�ļ��ر�
	ism.close();
	osm.close();

	//�������ļ����� �������л�
	Person p1(10, 20), p2(30, 40);//������
	ofstream osm1(targetName,ios::out|ios::binary);
	osm1.write((char*)&p1, sizeof(Person));//�����Ʒ�ʽд�ļ�
	osm1.write((char*)&p2, sizeof(Person));//�����Ʒ�ʽд�ļ�
	osm1.close();

	ifstream ism1(targetName, ios::in | ios::binary);
	Person p3, p4;
	ism1.read((char*)&p3, sizeof(Person));//���ļ���ȡ����
	ism1.read((char*)&p4, sizeof(Person));//���ļ���ȡ����

	p3.show();
	p4.show();
}