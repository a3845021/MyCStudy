#include "StringStudy.h"


StringStudy::StringStudy()
{
}


StringStudy::~StringStudy()
{
}

void StringStudy::run(){

	
	//���ַ����ĳ���
	char str[] = "asjkdfhs";

	char temp = str[0];
	int index = 0;
	while (temp!='\0')
	{
		temp = str[++index];
	}
	printf("�ַ����ĳ�����  %d  \n",index);
	
	//ϵͳ�ṩ�ķ���
	long  size =	strlen(str);
	printf("�ַ����ĳ�����----  %d  \n", size);


	//   ��һ���ض����ַ����д�ӡָ�����ַ���
	char str1[] = "its a computer";
	int j = 0;
	for (size_t i = 0; i < strlen("computer"); i++)
	{
		j = i + 6;
		printf("%c",str1[j]);
	}
	printf("\n");
	/*
		�ַ�����ֵ����
		strcpy()
	*/

	char strTo[20];
	char strFrom[]="dkjfhsdkjfhk";
	strcpy_s(strTo, strFrom);

	//strncpy()

	printf(strTo);
	printf("\n");

	//�ַ���ƴ�Ӻ���  strcty

	char cstr[20] = "hello";
	char cstr1[] = "world";

	strcat(cstr, cstr1);
	printf("cstr-----%s\n",cstr);
	printf("\n");

	//�ַ���ƴ���ֶ�ʵ��

	char cstr2[20] = "abcd";
	char cstr3[] = "123";
	int cstr2len = strlen(cstr2);
	for (size_t i = 0; i <= strlen(cstr3); i++)
	{
		cstr2[i + cstr2len] = cstr3[i];
	}
	printf("cstr2---%s \n", cstr2);
	printf("\n");


	//�ж��ַ�����Ӣ�ĵĸ���

	char cstr4[20] = "125adctgfhfghfg";

	char ctemp = cstr4[0];
	int cindex = 0;
	int count = 0;
	while (ctemp != '\0')
	{
		if ((ctemp <= 'z'&&ctemp >= 'a') || (ctemp <= 'Z'&&ctemp >= 'A')){
			count++;
		}
		ctemp = cstr4[cindex++];
	}

	printf("Ӣ�ĵĸ�����-----%d \n",count);
	printf("\n");

	//����һ��֧�����飬���֧��������Ԫ��ȫ�������ַ����Ѹ�����ת����һ����Ӧ����������������������������{��2������3����'4'},ת��Ϊ����Ϊ234

	char cstr5[] = {'2','3','1','5','6','2'};
	int clen = sizeof(cstr5);
	int sum = 0;
	for (size_t i = 0; i < clen; i++)
	{
		int temp=cstr5[i] - '0';
		sum = sum * 10 + temp;
	}
	printf("�õ���������------%d  \n",sum);
	printf("\n");

	//����һ����ȫ����Ϊ��ĸ���ɵ��ַ����飬�������е�Сдת�ɵĴ�д����дת��Сд ���硰aBcdDD��ת���ɡ�AbCDdd��
	char cstr6[] = "ABhdD";
	for (size_t i = 0; i < strlen(cstr6); i++)
	{
		if (cstr6[i] >= 'a' && cstr6[i] <= 'z'){
			cstr6[i] -= 32;
		}
		else if (cstr6[i] >= 'A' && cstr6[i] <= 'Z'){
			cstr6[i] += 32;
		}
	}
	printf("ת����Сд�Ľ����------%s \n",cstr6);
	printf("\n");

	//����һ����ȫ��Ӣ����ĸ���ɵ����飬��������С��Ϊż����Ԫ��ת���ɴ�д(��ԭ���Ǵ�д�򲻱䣬����Ԫ�ز���)
	char cstr7[] = "sdfFjkhJHJHgnb";
	int csize7 = strlen(cstr7);
	for (size_t i = 0; i < csize7; i=i + 2)
	{
		if (i >= csize7)break;
		if (cstr7[i] >= 'a'&&cstr7[i] <= 'z'){
			cstr7[i] -= 32;
		}
	}
	printf("ת��ż��λ�Ľ����------%s \n\n",cstr7);

	//��һ����ȫ��Ӣ����ĸ���ɵ��ַ�������ܣ�����ԭ�򣺳��ˡ�z����"Z"֮�⣬ÿ����ĸ��ascii��ֵ����1���� D���E Z����ΪA  z����Ϊa
	char password[] = "abczeFZbF";
	for (size_t i = 0; i < strlen(password); i++)
	{
		if (password[i] == 'z' || password[i] == 'Z'){
			password[i] -= 25;
		}
		else
		{
			password[i] += 1;
		}
	}
	printf("����֮��Ľ����------%s \n\n", password);

	//���������ַ���,�ӵ�һ���ַ�����ɾ���ڶ����ַ��������е��ַ�����������ĵ�һ���ַ���Ϊ��they are students���͵ڶ����ַ�����aeiou����ɾ��֮��ĵ�һ���ַ�����Ϊ��thy a stdnts��
	char cstr8[] = "they are students";
	char cstr9[] = "aeiou";
	for (size_t i = 0; i < strlen(cstr9); i++)
	{
		char childChar = cstr9[i];
		for (size_t j = 0; j < strlen(cstr8); j++)
		{
			if (childChar == cstr8[j]){
				for (size_t k = j; k < strlen(cstr8); k++)
				{
					cstr8[k] = cstr8[k + 1];
				}
			}
		}
	}
	printf("ɾ���ַ���֮���������----------%s \n\n",cstr8);

	//����һ���ַ����飬�ж�ĳ���ַ����Ƿ������֧�������У����硰abdefghj78���а���defg
	char cstr10[] = "abdefghj78";
	char cstr11[] = "defg";
	for (size_t i = 0; i < strlen(cstr10); i++)
	{
		char tempstr[100] = "";
		for (size_t j = 0; j < strlen(cstr11); j++)
		{
			tempstr[j] = cstr10[j + i];
		}
		if (strcmp(tempstr, cstr11) == 0){
			printf("����������ַ� \n\n");
			break;
		}
	}

}