#include "MemoryStudy.h"

//molloc������������

void MemoryStudy::run(){

	/*  �ڴ����֯��ʽ  �ڴ��Ϊ�ĸ���   ���������洢�ų�����룩  ���������洢��̬��ȫ�����ݣ����� ��   �������洢�Ŷ�̬������ڴ棬Ҳ����Ҫ��������� ��  ջ������Ҫ��žֲ�����  ����������
	
	*/

	//��̬�����ڴ�
	int a = 9;
	int *p1 = &a;

	/*  ���ʷ�ʽ
	*p1;
	a;
	*/

	//��̬����4���ֽ� ��ѷ�����ڴ��׵�ַ����
	//�������α���
	int * pInt = (int*)malloc(sizeof(int));

	//����һ���ַ�����
	char* pCh = (char*)malloc(sizeof(char));

	//����һ�����ַ�������
	char* pArray = (char*)malloc(sizeof(char) * 10);

	//����һ��double���͵ı���
	double* pDouble = (double*)malloc(sizeof(double));


	//��̬�ڴ��ʹ��

	*pInt = 9;
	printf("*pInt=%d\n", *pInt);
	*pCh = 'a';
	printf("*pCh=%d\n", *pCh);
	for (size_t i = 0; i < 10; i++)
	{
		pArray[i] = 'a' + i;
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("pArray + %d)=%c\n", i, *(pArray+i));
			
	}

	//�ͷ��ڴ�
	free(pDouble);
	free(pArray);
	free(pCh);
	free(pInt);


	//Ұָ��   �ڴ�й¶
	/*
	Ұָ�����ԭ�� 1��ָ�����û����Ч��ʼ��   2��Խ�����

	�ڴ�й©  1����̬�����ڴ�ʱ   ���������ڴ�û����Ч���ͷ�  �ͻ��ڴ�й¶
	
	*/


}
