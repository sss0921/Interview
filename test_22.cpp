#include <iostream>

struct ListNode {
	int nValue;
	ListNode *pNext;
};

ListNode *findKthToTail(ListNode *pListHead, unsigned int k)
{
	ListNode *pAhead = pListHead;
	ListNode *pBehind = nullptr;

	for (unsigned int i = 0; i < k - 1; i++) {
		if (pAhead->pNext != nullptr) { 
			pAhead = pAhead->pNext;
		} else {
			return nullptr;
		}
	}

	pBehind = pListHead;

	while (pAhead->pNext != nullptr) {
		pAhead = pAhead->pNext;
		pBehind = pBehind->pNext;
	}
	
	return pBehind;
}

int main(int argc, char *argv[])
{
	return 0;
}
