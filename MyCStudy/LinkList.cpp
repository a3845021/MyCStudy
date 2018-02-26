#include "LinkList.h"


void initLinkList(LinkList* list){
	list->head = NULL;
	list->nLength = 0;
}
int listLength(LinkList list){
	return list.nLength;
}

void insertNodeAtIndex(LinkList* list, DataType data, int index){
	//����һ���½ڵ������
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//��Ҫ��ӵ����ݴ�ŵ�������
	newNode->data = data;

	//��������ǿ�����
	if (list->nLength == 0){
		list->head = newNode;
		newNode->next = NULL;
	}
	else
	{
		//�ҵ�ǰһ���ڵ�preNode ��λ������λ�õĽڵ�node
		ListNode* preNode = nodeAtIndex(*list, index - 1);
		ListNode* node = nodeAtIndex(*list,index);

		newNode->next = node;
		preNode->next = newNode;
	}

}

ListNode* nodeAtIndex(LinkList list, int index){
	//�ȶ���һ��ָ�룬����ָ������ĵ�һ���ڵ�
	ListNode * pNode = list.head;
	//Ȼ������˳������������
	for (size_t i = 0; i < index; i++)
	{
		pNode = pNode->next;
	}
	return pNode;
}