#include "STLStudy.h"
#include <vector>//动态数组  可变数组
#include <algorithm> //算法

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
		STL从广义上分为 容器，算法，迭代器
	*/
	//数组容器
	int arr[] = {0,7,4,6,2,0};
	int * pBengin = arr;//指向 容器的第一个地址
	int * pEnd = &(arr[sizeof(arr) / sizeof(int)]);

	int num = mycount(pBengin,pEnd,0);
	cout << "num:" << num << endl;
#if 0
	//STL 基本语法
	vector<int> v;//定义一个容器，并且制定这个容器的存放的元素类型是int
	v.push_back(10);
	v.push_back(47);
	v.push_back(23);
	v.push_back(56);
	v.push_back(13);

	//遍历
	//通过STL提供的for_each算法
	//容器提供的迭代器
	//vector<int>::iterator 迭代器类型
	vector<int>::iterator pBengin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//容器中可能存放基础的数据类型  也可能存放自定义数据类型
	for_each(pBengin, pEnd, PrintVector);
#endif
	vector<Person> v;
	Person p1(10, 20), p2(1, 45), p3(23,66);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历
	for (vector<Person>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << (*it).age << "  " << (*it).id << endl;
	}
	
}
