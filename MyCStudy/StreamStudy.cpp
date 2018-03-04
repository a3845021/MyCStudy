#include "StreamStudy.h"
#include <fstream>

StreamStudy::StreamStudy()
{
}


StreamStudy::~StreamStudy()
{
}
//二进制文件操作  对象序列化
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
	//文件读写操作
	char * fileName = "C:\\MyWork\\SVN\\reource\\Code\\MyCStudy\\MyCStudy\\source.txt";
	char * targetName = "C:\\MyWork\\SVN\\reource\\Code\\MyCStudy\\MyCStudy\\target.txt";
	ifstream ism(fileName, ios::in);//只读方式打开文件
	ofstream osm(targetName, ios::out | ios::app);

	if (!ism){
		cout << "打开文件失败" << endl;
		return;
	}

	//读文件
	char ch;
	while (ism.get(ch)){
		cout << ch;
		osm.put(ch);
	}

	//文件关闭
	ism.close();
	osm.close();

	//二进制文件操作 对象序列化
	Person p1(10, 20), p2(30, 40);//二进制
	ofstream osm1(targetName,ios::out|ios::binary);
	osm1.write((char*)&p1, sizeof(Person));//二进制方式写文件
	osm1.write((char*)&p2, sizeof(Person));//二进制方式写文件
	osm1.close();

	ifstream ism1(targetName, ios::in | ios::binary);
	Person p3, p4;
	ism1.read((char*)&p3, sizeof(Person));//从文件读取数据
	ism1.read((char*)&p4, sizeof(Person));//从文件读取数据

	p3.show();
	p4.show();
}