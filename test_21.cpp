#include <iostream>

bool isEven(int data)
{
	return (data & 0x01) == 0;
}

void recorderOddEven(int *pData, unsigned int length, bool (*func)(int))
{
	if (pData == nullptr || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		// 向后移动pBegin，直到它指向偶数
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		// 向前移动pEnd, 直到它指向奇数
		while (pEnd > pBegin && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd) {
			int temp = *pEnd;
			*pEnd = *pBegin;
			*pBegin = temp;
		}
	}
}

void printfNum(int *pData, unsigned int length)
{
	for (int index = 0; index < length; index++) {
		printf("%d ", pData[index]);
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3, 4, 5};
	printfNum(a, sizeof(a)/sizeof(int));
	recorderOddEven(a, sizeof(a)/sizeof(int), isEven);
	printfNum(a, sizeof(a)/sizeof(int));
}
