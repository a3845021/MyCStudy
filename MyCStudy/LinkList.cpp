#include "LinkList.h"


void initLinkList(LinkList* list){
	list->head = NULL;
	list->nLength = 0;
}
int listLength(LinkList list){
	return list.nLength;
}

void insertNodeAtIndex(LinkList* list, DataType data, int index){
	//分配一个新节点的内容
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//把要添加的数据存放到数据域
	newNode->data = data;

	//如果链表是空链表
	if (list->nLength == 0){
		list->head = newNode;
		newNode->next = NULL;
	}
	else
	{
		//找到前一个节点preNode 和位于索引位置的节点node
		ListNode* preNode = nodeAtIndex(*list, index - 1);
		ListNode* node = nodeAtIndex(*list,index);

		newNode->next = node;
		preNode->next = newNode;
	}

}

ListNode* nodeAtIndex(LinkList list, int index){
	//先定义一个指针，让其指向链表的第一个节点
	ListNode * pNode = list.head;
	//然后依次顺着链表向后遍历
	for (size_t i = 0; i < index; i++)
	{
		pNode = pNode->next;
	}
	return pNode;
}