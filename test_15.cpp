#include <iostream>

int numberOf1(int n)
{
	int count = 0;
	while(n) {
		if (n & 1)
			count++;
		n >>= 1;
	}

	return count;
}

int numberOf2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while(flag) {
		if (n & flag)
			count++;
		flag >>= 1;
	}
	return count;
}

int numberOf3(int n)
{
	int count = 0;
	while (n) {
		++count;
		n = (n - 1) & n;
	}
	return count;
}

int main(int argc, char *argv[])
{
	std::cout << numberOf1(0x8000000) << std::endl;
#	//	std::cout << numberOf1(-1);
	std::cout << numberOf2(-1) << std::endl;
	std::cout << numberOf3(0x8800000) << std::endl;
	std::cout << numberOf3(-1) << std::endl;
	return 0;
}
