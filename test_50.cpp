#include <iostream>

char findNotRepeattingChar(char *pString)
{
    if (pString == nullptr)
        return '\0';

    const int tableSize = 256;

    unsigned int hashTable[tableSize];
    for (int index = 0; index < tableSize; index++)
        hashTable[index] = 0;

    char *pHashKey = pString;

    while (*pHashKey != '\0') 
        hashTable[*(pHashKey++)]++;
    
    pHashKey = pString;

    while (*pHashKey != '\0') {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey++;
    }
    
    return '\0';
}

int main(int argc, char *argv[])
{
    char data[] = "abaccdeff";
    std::cout << findNotRepeattingChar(data) << std::endl;
    return 0;    
}