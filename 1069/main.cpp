#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
    return a > b;
}

int main()
{
    string tre;
    cin >> tre;
    while(1){
        while (tre.length() < 4){
            tre.push_back('0');
        }
        sort(tre.begin(), tre.end());
        int b = stoi(tre);
        sort(tre.begin(), tre.end(), cmp);
        int a = stoi(tre);
        int r = a - b;
        printf("%04d - %04d = %04d\n", a, b, r);
        if (r == 6174 || r == 0)
            break;
        tre = to_string(r);
    }
    return 0;
}
