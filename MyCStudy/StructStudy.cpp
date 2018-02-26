#include "StructStudy.h"

//�ṹ����������� ������
struct Student{
	int age;
	char name[20];
	double mathScore;
	double chineseScore;
	double englishScore;
}xiaoming,xiaohong,doudou;

//������
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

// ��ʼ��(��ȫ��ʼ��)  :Ҳ���Բ��ֳ�ʼ��
struct Student s3 = {15,"xingxing",67,68,10};

//���ֳ�ʼ��
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

//����   ���һ������  ���ԶԽṹ�������������  Ҫ������������û�ָ��
int compareStudents(struct Student s1, struct Student s2){
	return s1.age > s2.age;
}

//ð������
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

	//�ṹ��֮��ĸ�ֵ
	xiaoming = xiaohong;

	//������
	//xiaoming.name = "xingxing";

	strcpy(xiaoming.name,"С��");

	struct Student xingxing = studentMakeWith(12,"xingxing",45,63,13);
	showMessageOfStudent(xingxing);
	//�ṹ��ķ���

	//:   �ṹ��ĳ�ʼ��һ�㶼��װ����


	struct Student stuArray[5];
	for (size_t i = 0; i < 5; i++)
	{
		int age = 10 + i;
		stuArray[i] = studentMakeWith(age,"xingxing",54,12,45);
	}
	printf("����ǰ\n");
	for (size_t i = 0; i < 5; i++)
	{
		showMessageOfStudent(stuArray[i]);
	}

	printf("�����------------------\n");
	sortArray(stuArray, 5, compareStudents);
	for (size_t i = 0; i < 5; i++)
	{
		showMessageOfStudent(stuArray[i]);
	}

	//�ṹ��ָ��
	/*
	//ʹ�ýṹ��ָ����ʽṹ���Ա
	struct Student *s3;
	s3->age;
	//ʹ�ýṹ��������ʽṹ���Ա
	struct Student s4;
	s4.age;
	*/

	struct Student mStudent0;
	struct Student *mStudent = &mStudent0;
	strcpy(mStudent->name, "lalal");
	printf("s3->name= %s\n", mStudent->name);

	//������Ҳ��һ���µ��������ͣ�����һ��������ʽ�ı��� 
	//����˵�������ϱ����Ķ�����ṹʮ������  ����ʽΪ
	/*
		union ������{
			�������ͳ�Ա��
			�������ͳ�Ա��
			...
			...
			...
		}���ϱ�����
	
	*/


	//�ṹ���Ƕ��

	struct Students xiaoming;
	xiaoming.age = 19;
	xiaoming.name = "xiaoming";
	xiaoming.birthday = datewith(1990, 12, 15);

}