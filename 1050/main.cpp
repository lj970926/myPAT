#include <iostream>
#include <cstdio>
using namespace std;

char s[10005];
bool hashT[150] = {false};
int main()
{
    cin.getline(s,10005);
    char c;
    while ((c = getchar()) != '\n'){
        hashT[(int)c] = true;
    }
    for (int i = 0;s[i]!='\0';i++){
        if (!hashT[(int)s[i]])
            printf("%c",s[i]);
    }
    return 0;
}
