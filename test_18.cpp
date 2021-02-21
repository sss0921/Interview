#include <iostream>
#include <stdlib.h>

struct ListNode
{
	int nValue;
	ListNode *pNext;
};

struct ListNode *pHead = NULL;

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
		return;

	// 要删除的节点不是尾节点
	if (pToBeDeleted->pNext != NULL) {
		ListNode *pNext = pToBeDeleted->pNext;
		pToBeDeleted->nValue = pNext->pNext->nValue;
		pToBeDeleted->pNext = pNext->pNext;
		
		delete pNext;
		pNext = NULL;
	} else if (*pListHead == pToBeDeleted) {
		delete *pListHead;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	} else { // 尾部节点
		ListNode *pNode = *pListHead;
		while (pNode->pNext != pToBeDeleted) {
			pNode = pNode->pNext;
		}

		pNode->pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

void addNode(int n)
{
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	
	node->nValue = n;
	node->pNext = NULL;

	if (pHead == NULL) {
		pHead = node;
		return;
	} 

	ListNode *temp = pHead;

	while(temp->pNext != NULL) {
		temp = temp->pNext;
	}

	temp->pNext = node;
}

void traverseList(ListNode *pListHead)
{
	if (pListHead == NULL)
		return;
	
	ListNode *temp = pListHead;
	while (temp != NULL) {
		printf("%d ", temp->nValue);
		temp = temp->pNext;
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; i++) {
		addNode(i);
	}

	traverseList(pHead);
	return 0;
}
