#include "EnumStudy.h"

//ö�ٶ���
enum GCZColor{
	//ö�ٳ�Ա����ֻ��������
	Red,
	Blue=19,
	White
};


void showMyFavoriteColor(enum GCZColor color){
	switch (color)
	{
	case Red:
		printf("��ϲ����ɫ\n");
		break;
	case Blue:
		printf("��ϲ����ɫ\n");
		break;
	case White:
		printf("��ϲ����ɫ\n");
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
	printf("����������\n");
	scanf("%s", mStaff->name);
	printf("�����빤��\n");
	scanf("%d", &mStaff->years);
	printf("����������\n");
	scanf("%d", &mStaff->age);
}
void scanfMessage(struct Staff mArray[], int nLength){
	for (size_t i = 0; i < nLength; i++)
	{
		printf("������� %d ��Ա������Ϣ\n", i + 1);
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

	//ö�ٵ�ʹ��
	myColor = Red;
	printf("red��ֵ----------%d\n", myColor);
	myColor = Blue;
	printf("Blue��ֵ----------%d\n", myColor);
	myColor = White;
	printf("White��ֵ----------%d\n", myColor);



	//��ϰ��Ա���������

	struct Staff mArray[5];
	scanfMessage(mArray, 5);

	//����  :���չ���
	sortArray(mArray, 5, compareWithYears);
	printf("���չ����������\n");
	printArray(mArray, 5);

	//����  :��������
	sortArray(mArray, 5, compareWithAge);
	printf("���������������\n");
	printArray(mArray, 5);
}