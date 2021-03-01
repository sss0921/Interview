#include <iostream>
#include <cstring>

int numberOf1AndN(int n);
int numberOf1AndN(char *str);

int powerBase10(unsigned int n)
{
	unsigned int result = 1;

	for (unsigned int index = 0; index < n; index++)
		result *= 10;
	
	return result;
}

int numberOf1AndN(int n)
{
	if (n <= 0)
		return 0;

	char str[50];
	sprintf(str, "%d", n);

	return numberOf1AndN(str);
}

int numberOf1AndN(char *str)
{
	if (!str || *str < '0' || *str > '9' || *str == '\n')
		return 0;

	int first = (*str - '0');
	unsigned int length = static_cast<unsigned int>(strlen(str));

	if (length == 1 && first == 0)
		return 0;

	if (length == 1 && first > 0)
		return 1;

	// 假设str是“21345”
	int numFirstDigit = 0;
	
	if (first > 0) 
		numFirstDigit = powerBase10(length - 1);
	else
		numFirstDigit = atoi(str + 1) + 1;
	
	int numOtherDigits = first * (length - 1) * powerBase10(length - 2);

	int numRecursive = numberOf1AndN(str + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int main(int argc, char *argv[])
{
	std::cout << numberOf1AndN(21345) << std::endl;
	return 0;
}
