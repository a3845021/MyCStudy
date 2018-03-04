#include "STLStudy.h"
#include <vector>//��̬����  �ɱ�����
#include <algorithm> //�㷨

STLStudy::STLStudy()
{
}


STLStudy::~STLStudy()
{
}
int mycount(int* start,int* end,int val){
	int num = 0;
	while (start != end)
	{
		if (*start == val){
			num++;
		}
		start++;
	}
	return num;
}
void PrintVector(int val){
	cout << val << "  ";
}

class Person
{
public:
	Person(int age,int id){
		this->age = age;
		this->id = id;
	}
	~Person(){}
	int age;
	int id;

};

void STLStudy::run(){
	/*
		STL�ӹ����Ϸ�Ϊ �������㷨��������
	*/
	//��������
	int arr[] = {0,7,4,6,2,0};
	int * pBengin = arr;//ָ�� �����ĵ�һ����ַ
	int * pEnd = &(arr[sizeof(arr) / sizeof(int)]);

	int num = mycount(pBengin,pEnd,0);
	cout << "num:" << num << endl;
#if 0
	//STL �����﷨
	vector<int> v;//����һ�������������ƶ���������Ĵ�ŵ�Ԫ��������int
	v.push_back(10);
	v.push_back(47);
	v.push_back(23);
	v.push_back(56);
	v.push_back(13);

	//����
	//ͨ��STL�ṩ��for_each�㷨
	//�����ṩ�ĵ�����
	//vector<int>::iterator ����������
	vector<int>::iterator pBengin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//�����п��ܴ�Ż�������������  Ҳ���ܴ���Զ�����������
	for_each(pBengin, pEnd, PrintVector);
#endif
	vector<Person> v;
	Person p1(10, 20), p2(1, 45), p3(23,66);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//����
	for (vector<Person>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << (*it).age << "  " << (*it).id << endl;
	}
	
}
