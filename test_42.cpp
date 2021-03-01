#include <iostream>
#include <limits>

bool g_invalidInput = false;

int findGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == nullptr || nLength <= 0) {
		g_invalidInput = true;
		return 0;
	}

	int sum = 0;
	int maxSum = std::numeric_limits<int>::min();

	for (int index = 0; index < nLength; index++) {
		if (sum <= 0) 
			sum = pData[index];
		else 
			sum += pData[index];

		if (sum >= maxSum) 
			maxSum = sum;
	}

	return maxSum;
}

int main(int argc, char *argv[])
{
	int data[] = {1,-2,3,10,-4,7,2,-5};
	std::cout << findGreatestSumOfSubArray(data, sizeof(data)/sizeof(int)) << std::endl;
	return 0;
}
