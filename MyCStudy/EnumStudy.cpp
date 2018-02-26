#include "EnumStudy.h"

//枚举定义
enum GCZColor{
	//枚举成员变量只能是整数
	Red,
	Blue=19,
	White
};


void showMyFavoriteColor(enum GCZColor color){
	switch (color)
	{
	case Red:
		printf("我喜欢红色\n");
		break;
	case Blue:
		printf("我喜欢蓝色\n");
		break;
	case White:
		printf("我喜欢白色\n");
		break;
	default:
		break;
	}

}

struct Staff{
	char name[20];
	int years;
	int age;
};

void scanfStaff(struct Staff *mStaff){
	printf("请输入姓名\n");
	scanf("%s", mStaff->name);
	printf("请输入工龄\n");
	scanf("%d", &mStaff->years);
	printf("请输入年龄\n");
	scanf("%d", &mStaff->age);
}
void scanfMessage(struct Staff mArray[], int nLength){
	for (size_t i = 0; i < nLength; i++)
	{
		printf("请输入第 %d 个员工的信息\n", i + 1);
		scanfStaff(&mArray[i]);
	}
}

int compareWithYears(struct Staff s1, struct Staff s2){
	return s1.years > s2.years;
}

int compareWithAge(struct Staff s1, struct Staff s2){
	return s1.age > s2.age;
}

void sortArray(struct Staff mStaff[], int nlength, int(*pCompare)(struct Staff s1, struct Staff s2)){

	for (size_t i = 1; i <= nlength; i++)
	{
		for (size_t j = 0; j < nlength - i; j++)
		{
			printf("j--------------%d",j);
			if (pCompare(mStaff[j], mStaff[j + 1])){
				struct Staff temp = mStaff[j + 1];
				mStaff[j + 1] = mStaff[j];
				mStaff[j] = temp;
			}
		}
	}
}
void printStaff(struct Staff mStaff){
	printf("name= %s\n", mStaff.name);
	printf("years= %d", mStaff.years);
	printf("age= %d", mStaff.age);
	printf("--------------------------\n");
}

void printArray(struct Staff pArray[], int nLength){
	for (size_t i = 0; i < nLength; i++)
	{
		printStaff(pArray[i]);

	}
}

void EnumStudy::run(){

	enum GCZColor myColor;

	//枚举的使用
	myColor = Red;
	printf("red的值----------%d\n", myColor);
	myColor = Blue;
	printf("Blue的值----------%d\n", myColor);
	myColor = White;
	printf("White的值----------%d\n", myColor);



	//练习：员工管理设计

	struct Staff mArray[5];
	scanfMessage(mArray, 5);

	//排序  :按照工龄
	sortArray(mArray, 5, compareWithYears);
	printf("按照工龄的排序结果\n");
	printArray(mArray, 5);

	//排序  :按照年龄
	sortArray(mArray, 5, compareWithAge);
	printf("按照年龄的排序结果\n");
	printArray(mArray, 5);
}