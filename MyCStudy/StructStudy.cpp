#include "StructStudy.h"

//结构体的命名定义 和声明
struct Student{
	int age;
	char name[20];
	double mathScore;
	double chineseScore;
	double englishScore;
}xiaoming,xiaohong,doudou;

//联合体
union  MyDataType
{
	int a;
	double b;
	char c;

};

struct Date{
	int year;
	int month;
	int day;
};

struct Students{
	char * name;
	int age;
	struct Date birthday;
};

struct Student s1;
struct Student s2;

// 初始化(完全初始化)  :也可以部分初始化
struct Student s3 = {15,"xingxing",67,68,10};

//部分初始化
//struct Student s4 = { .name = "xingxing" };

struct  Student studentMakeWith(int age ,char * name ,double mathScore,double chineseScore,double englishScore){
	struct Student result;
	result.age = age;
	strcpy(result.name, name);
	result.mathScore = mathScore;
	result.englishScore = englishScore;
	result.chineseScore = chineseScore;
	return result;
}

void showMessageOfStudent(struct Student student){
	printf("age = %d\n", student.age);
	printf("name = %s\n", student.name);
	printf("math = %.2f\n", student.mathScore);
	printf("chinese = %.2f\n", student.chineseScore);	
	printf("english = %.2f\n", student.englishScore);
}

struct Date datewith(int year,int month,int date){
	struct Date reDate;
	reDate.year = year;
	reDate.month = month;
	reDate.day = date;
	return reDate;
}

//需求   设计一个函数  可以对结构体数组进行排序  要求排序规则由用户指定
int compareStudents(struct Student s1, struct Student s2){
	return s1.age > s2.age;
}

//冒泡排序
void sortArray(struct Student stuArr[], int nLength, int(*mCompare)(struct Student s1, struct Student s2)){
	for (size_t i = 1; i < nLength; i++)
	{
		bool flag = false;
		for (size_t j = 0; j < nLength-i; j++)
		{
			if (mCompare(stuArr[j], stuArr[j + 1])){
				flag = true;
				struct Student temp = stuArr[j];
				stuArr[j] = stuArr[j+1];
				stuArr[j + 1] = temp;
			}
		}
		if (!flag)break;
	}
}




void StructStudy::run(){

	//结构体之间的赋值
	xiaoming = xiaohong;

	//有问题
	//xiaoming.name = "xingxing";

	strcpy(xiaoming.name,"小华");

	struct Student xingxing = studentMakeWith(12,"xingxing",45,63,13);
	showMessageOfStudent(xingxing);
	//结构体的访问

	//:   结构体的初始化一般都封装函数


	struct Student stuArray[5];
	for (size_t i = 0; i < 5; i++)
	{
		int age = 10 + i;
		stuArray[i] = studentMakeWith(age,"xingxing",54,12,45);
	}
	printf("排序前\n");
	for (size_t i = 0; i < 5; i++)
	{
		showMessageOfStudent(stuArray[i]);
	}

	printf("排序后------------------\n");
	sortArray(stuArray, 5, compareStudents);
	for (size_t i = 0; i < 5; i++)
	{
		showMessageOfStudent(stuArray[i]);
	}

	//结构体指针
	/*
	//使用结构体指针访问结构体成员
	struct Student *s3;
	s3->age;
	//使用结构体变量访问结构体成员
	struct Student s4;
	s4.age;
	*/

	struct Student mStudent0;
	struct Student *mStudent = &mStudent0;
	strcpy(mStudent->name, "lalal");
	printf("s3->name= %s\n", mStudent->name);

	//联合体也是一种新的数据类型，他是一种特殊形式的变量 
	//联合说明和联合变量的定义与结构十分相似  其形式为
	/*
		union 联合名{
			数据类型成员名
			数据类型成员名
			...
			...
			...
		}联合变量名
	
	*/


	//结构体的嵌套

	struct Students xiaoming;
	xiaoming.age = 19;
	xiaoming.name = "xiaoming";
	xiaoming.birthday = datewith(1990, 12, 15);

}