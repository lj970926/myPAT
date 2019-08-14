#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int hashTable[150]={0};
int hasinput[150] = {0};
int main()
{
    string origin,real;
    cin >> origin >> real;

    for (int i = 0;i < real.size();i++){
        if(islower(real[i]))
            real[i] = toupper(real[i]);
        hashTable[(int)real[i]]++;
    }
    for (int j = 0;j < origin.size();j++){
        if (islower(origin[j]))
            origin[j] = toupper(origin[j]);
        if(!hashTable[(int)origin[j]]&&!hasinput[(int)origin[j]]){
            printf("%c",origin[j]);
            hasinput[(int)origin[j]] = 1;
        }

    }
    return 0;
}
