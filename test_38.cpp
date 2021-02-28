#include <iostream>

void permutation(char *pStr);
void permutation(char *pStr, char *pBegin);

void permutation(char *pStr)
{
	if (pStr == nullptr)
		return;

	permutation(pStr, pStr);
}

void permutation(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')	{
		printf("%s\n", pStr);
		return;
	}

	for (char *pCh = pBegin; *pCh != '\0'; pCh++) {
		char temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;
		
		permutation(pStr, pBegin + 1);

		temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;
	}
}

int main(int argc, char *argv[])
{
	char data[] = "abc";

	permutation(data);

	return 0;
}
