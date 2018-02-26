#pragma once
#include "Common.h"

typedef int DataType;

struct node
{
	DataType data;//数据域
	struct node* next;//指针域
};

typedef struct node ListNode;

//一个链表
typedef struct {
	int nLength;//记录链表长度
	ListNode* head;//记录链表首地址
}LinkList;

//链表初始化
void initLinkList(LinkList* list);
//求链表的长度
int listLength(LinkList list);
//插入一个节点
void insertNodeAtIndex(LinkList* list, DataType data, int index);
//删除一个节点 返回被删除的节点
ListNode deleteNodeAtIndex(LinkList list, int index);
//修改一个节点
void updateNodeAtIndex(LinkList list,ListNode newNode,int index);
//指定索引查找节点
ListNode* nodeAtIndex(LinkList list,int index);
//指定数据内容查找节点的位置
int indexOfNodeContent(LinkList list,DataType data);



//class LinkList
//{
//public:
//	LinkList(){}
//	~LinkList(){}
//};

