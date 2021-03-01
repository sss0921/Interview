#include <iostream>

bool isUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;

	return (number == 1);
}

int getUglyNumber(int index)
{
	if (index <= 0)
		return 0;

	int number = 0;

	int uglyFound = 0;

	while (uglyFound < index) {
		++number;

		if (isUgly(number)) {
			++uglyFound;
		}
	}

	return number;
}

int getMin(int num1, int num2, int num3)
{
	int min = num1 > num2 ? num2 : num1;
	return min > num3 ? num3 : min;
}

int getUglyNumber2(int index)
{
	if (index <= 0)
		return 0;

	int *pUglyNumbers = new int[index];

	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index) {
		int min = getMin(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);

		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;
	}

	return pUglyNumbers[index - 1];
	delete [] pUglyNumbers;
}

int main(int argc, char *argv[])
{
	std::cout << getUglyNumber(1500) << std::endl;
	std::cout << getUglyNumber2(1500) << std::endl;
	return 0;
}
