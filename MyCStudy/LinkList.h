#pragma once
#include "Common.h"

typedef int DataType;

struct node
{
	DataType data;//������
	struct node* next;//ָ����
};

typedef struct node ListNode;

//һ������
typedef struct {
	int nLength;//��¼������
	ListNode* head;//��¼�����׵�ַ
}LinkList;

//�����ʼ��
void initLinkList(LinkList* list);
//������ĳ���
int listLength(LinkList list);
//����һ���ڵ�
void insertNodeAtIndex(LinkList* list, DataType data, int index);
//ɾ��һ���ڵ� ���ر�ɾ���Ľڵ�
ListNode deleteNodeAtIndex(LinkList list, int index);
//�޸�һ���ڵ�
void updateNodeAtIndex(LinkList list,ListNode newNode,int index);
//ָ���������ҽڵ�
ListNode* nodeAtIndex(LinkList list,int index);
//ָ���������ݲ��ҽڵ��λ��
int indexOfNodeContent(LinkList list,DataType data);



//class LinkList
//{
//public:
//	LinkList(){}
//	~LinkList(){}
//};

