#pragma once
#include "Common.h"
//内联函数学习
class InLineStudy:Root
{
public:
	InLineStudy();
	~InLineStudy();
	inline void printAB(int a, int b);    //函数声明和函数体都必须写上关键字inline  否则不是内联函数
	void func(int a=21);
	void run();
};

