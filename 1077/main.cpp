#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    string result;
    getline(cin, result);
    for (int i = 1; i < n; i++){
        string temp;
        getline(cin, temp);
        if (result.size() == 0)
            continue;
        int k = result.size() - 1, j = temp.size() - 1;
        while(k >= 0 && j >=0 && result[k] == temp[j]){
            k--;
            j--;
        }
        result = result.substr(k + 1);
    }
    if (result.size() != 0)
        printf("%s", result.c_str());
    else
        printf("nai");
    return 0;
}
