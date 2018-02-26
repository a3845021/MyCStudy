#include "VariableStudy.h"


VariableStudy::VariableStudy()
{
}


VariableStudy::~VariableStudy()
{
}

void VariableStudy::run(){
	
	/*
	//C++新增的变量
	整数 
	long long 
	unsigned long long
	浮点数
	long double
	表示的范围变大 没有本质的区别
	*/
	//wchar_t  宽字符
	/*
	ascll:  一个字符
	中文 ：两个字符
	*/
	//使用：
	char *cnchs="你好中国!";
	wchar_t wt[]=L"你好中国!";//宽字符

	cout << sizeof(cnchs) << endl;  //11
	cout << sizeof(wt) << endl;//12  结束符\n  同样暂用两个字节

	cout << strlen(cnchs) << endl;
	cout << wcslen(wt) << endl;
	//wchar_t 在windows里面是一种标准的字符串类型



}