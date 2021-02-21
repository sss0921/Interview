#include <iostream>

struct ListNode
{
	int nValue;
	ListNode *pNext;
};

ListNode *meettingNode(ListNode *pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode *pFast = pHead->pNext;
	ListNode *pSlow = pHead->pNext;
	if (pFast == nullptr || pSlow == nullptr)
		return nullptr;

	while (pFast != nullptr && pSlow != nullptr) {
		if (pFast == pSlow)
			return pFast;

		pSlow = pSlow->pNext;

		pFast = pFast->pNext;
		if (pFast != nullptr)
			pFast = pFast->pNext;
	}

	return nullptr;
}

ListNode *entryNodeOfLoop(ListNode *pHead)
{
	ListNode *meetingNode = meettingNode(pHead);
	if (meetingNode == nullptr)
		return nullptr;

	int nodesInLoop = 1;
	ListNode *pNode1 = meetingNode;
	while(pNode1->pNext != meetingNode) {
		pNode1 = pNode1->pNext;
		++nodesInLoop;
	}

	// 先移动pNode1,次数为环中节点的数目
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; ++i) 
		pNode1 = pNode1->pNext;

	// 在移动pNode1和pNode2
	ListNode *pNode2 = pHead;
	while (pNode1 != pNode2) {
		pNode1 = pNode1->pNext;
		pNode2 = pNode2->pNext;
	}

	return pNode1;
}

int main(int argc, char *argv[])
{
	return 0;
}
