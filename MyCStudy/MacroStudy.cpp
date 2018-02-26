#include "MacroStudy.h"

#define SUM(a,b) (a+b)

#define MUL(a,b) ((a)*(b))   //注意 参数只是简单的替换   比如  MUL(2+1,3+2)    计算的格式为  2+1*3+2   所以  在计算的时候 尽量用括号括起来参数

int mulFunc(int a, int b){   //函数和宏功能一样   但是宏是不分配内存的   一些简单的逻辑 可以直接使用带参数的宏  而不用定义函数
	return a*b;
}


//条件编译
#ifndef Test

#else

#endif



void MacroStudy::run(){
	/*  （主要是带参数的宏定义）
		宏定义指令： #define 用来定义一个标示符和一个字符串，以这个标示符来代替这个字符串

		不带参数的宏定义  #define 宏名  字符串

		1.#表示  这是一条预处理命令

		2，宏名  这是一个标识符  要符合标识符的命名规则，并要求大写

		3，字符串的位置可以是常量，表达式，格式字符串

		#undef:结束宏定义的作用域
	*/

	int sum = SUM(5, 6);
	printf("sun=%d\n",sum);

#if 1
	printf("第一段代码\n");
#else

#endif


}
