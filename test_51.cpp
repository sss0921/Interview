#include <iostream>

int inversePairs(int *data, int length);
int inversePairsCore(int* data, int* copy, int start, int end);

int inversePairs(int* data, int length)
{
	if (data == nullptr || length < 0)
		return 0;

	int* copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = inversePairsCore(data, copy, 0, length - 1);
	delete [] copy;
	
	return count;
}

int inversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end) {
		data[start] = copy[end];
		return 0;
	}

	int length = (end - start) / 2;

	int left = inversePairsCore(data, copy, start,  start + length);
	int right = inversePairsCore(data, copy, start + length + 1, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while(i >= start && j >= start + length + 1) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		} else {
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
		copy[indexCopy--] = data[i];

	for (; j >= start + length + 1; --j)
		copy[indexCopy++] = data[j];

	return left + right + count;
}

int main(int argc, char *argv[])
{
	int data[] = {7, 5, 6, 4};
	std::cout << inversePairs(data, sizeof(data) / sizeof(int)) << std::endl;
	return 0;
}
