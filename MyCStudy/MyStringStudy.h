#pragma once
#include "Common.h"

class  MyString
{
public:
	 MyString();
	~ MyString();

private:

};
 
 MyString:: MyString()
{
}

 MyString::~ MyString()
{
}
//自定义string类
class MyStringStudy:public Root
{
public:
	MyStringStudy();
	~MyStringStudy();
	//void run();
};

