#pragma once
#include "Common.h"
//引用的学习
struct student{
	int id;
	char name[64];
};
struct typeA{
	int &a;
};
struct typeB{
	int *a;
};
class QuoteStudy:public Root
{
public:
	void run();
};

