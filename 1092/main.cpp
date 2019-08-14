#include <iostream>
#include <cstring>
using namespace std;

char c1[1005],c2[1005];
int hashTable[150] = {0};

int main()
{
    scanf("%s %s",c1,c2);
    int len1 = strlen(c1),len2 = strlen(c2);
    for (int i = 0;i < len1;i++)
        hashTable[(int)c1[i]]++;
        int miss = 0;
    for (int j = 0;j < len2;j++){
        if (!hashTable[(int)c2[j]])
            miss++;
        else{
            hashTable[(int)c2[j]]--;
        }
    }
    if (miss)
        printf("No %d",miss);
    else{
        int extra = 0;
        for (int i = 0;i < 128;i++){
            extra += hashTable[i];
        }
        printf("Yes %d",extra);
    }

    return 0;
}
