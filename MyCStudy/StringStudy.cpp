#include "StringStudy.h"


StringStudy::StringStudy()
{
}


StringStudy::~StringStudy()
{
}

void StringStudy::run(){

	
	//求字符串的长度
	char str[] = "asjkdfhs";

	char temp = str[0];
	int index = 0;
	while (temp!='\0')
	{
		temp = str[++index];
	}
	printf("字符串的长度是  %d  \n",index);
	
	//系统提供的方法
	long  size =	strlen(str);
	printf("字符串的长度是----  %d  \n", size);


	//   在一个特定的字符串中打印指定的字符串
	char str1[] = "its a computer";
	int j = 0;
	for (size_t i = 0; i < strlen("computer"); i++)
	{
		j = i + 6;
		printf("%c",str1[j]);
	}
	printf("\n");
	/*
		字符串赋值函数
		strcpy()
	*/

	char strTo[20];
	char strFrom[]="dkjfhsdkjfhk";
	strcpy_s(strTo, strFrom);

	//strncpy()

	printf(strTo);
	printf("\n");

	//字符串拼接函数  strcty

	char cstr[20] = "hello";
	char cstr1[] = "world";

	strcat(cstr, cstr1);
	printf("cstr-----%s\n",cstr);
	printf("\n");

	//字符串拼接手动实现

	char cstr2[20] = "abcd";
	char cstr3[] = "123";
	int cstr2len = strlen(cstr2);
	for (size_t i = 0; i <= strlen(cstr3); i++)
	{
		cstr2[i + cstr2len] = cstr3[i];
	}
	printf("cstr2---%s \n", cstr2);
	printf("\n");


	//判断字符串中英文的个数

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

	printf("英文的个数是-----%d \n",count);
	printf("\n");

	//给定一个支付数组，这个支付数组中元素全是数字字符，把该数组转化成一个对应的整数，比如数组的数组的内容是{‘2’，‘3’，'4'},转化为整数为234

	char cstr5[] = {'2','3','1','5','6','2'};
	int clen = sizeof(cstr5);
	int sum = 0;
	for (size_t i = 0; i < clen; i++)
	{
		int temp=cstr5[i] - '0';
		sum = sum * 10 + temp;
	}
	printf("得到的整数是------%d  \n",sum);
	printf("\n");

	//给定一个完全由因为字母构成的字符数组，将数组中的小写转成的大写，大写转成小写 例如“aBcdDD”转化成“AbCDdd”
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
	printf("转换大小写的结果是------%s \n",cstr6);
	printf("\n");

	//给定一个完全由英文字母构成的数组，将数组中小标为偶数的元素转化成大写(若原来是大写则不变，其他元素不变)
	char cstr7[] = "sdfFjkhJHJHgnb";
	int csize7 = strlen(cstr7);
	for (size_t i = 0; i < csize7; i=i + 2)
	{
		if (i >= csize7)break;
		if (cstr7[i] >= 'a'&&cstr7[i] <= 'z'){
			cstr7[i] -= 32;
		}
	}
	printf("转换偶数位的结果是------%s \n\n",cstr7);

	//给一个完全由英文字母构成的字符数组加密，加密原则：除了“z”和"Z"之外，每个字母的ascii码值都加1，即 D变成E Z加密为A  z加密为a
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
	printf("加密之后的结果是------%s \n\n", password);

	//输入两个字符串,从第一个字符串中删除第二个字符串中所有的字符，例如输入的第一个字符串为“they are students”和第二个字符串“aeiou”则删除之后的第一个字符串变为“thy a stdnts”
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
	printf("删除字符串之后的数据是----------%s \n\n",cstr8);

	//给定一个字符数组，判断某个字符串是否在这个支付数组中，比如“abdefghj78”中包含defg
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
			printf("包含里面的字符 \n\n");
			break;
		}
	}

}