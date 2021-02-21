#include <iostream>
#include <string.h>

void printNumber(char *number)
{
	int nLength = strlen(number);

	char *temp = nullptr;
	for (int i = 0; i < nLength; i++){
		if (number[i] != '0') {
			temp = &(number[i]);
			break;
		}
	}

	printf("%s\t", temp);
}

bool increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	
	for (int i = nLength - 1; i >= 0; i--) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10) {
			if (i == 0) {
				isOverflow = true;
			} else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		} else {
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

void print1ToMaxOfDigits(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while(!increment(number)) {
		printNumber(number);
	}

	delete [] number;
}

int main(int argc, char *argv[])
{
	print1ToMaxOfDigits(4);
	return 0;
}
