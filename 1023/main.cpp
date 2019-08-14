#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    char a[25];
    int total[10]={0};
    vector<int> da;
    scanf("%s",a);
    for (int i = 0;i < strlen(a);i++) total[a[i]-'0']++;
    int cnt = 0;
    for (int i = strlen(a) - 1;i >= 0;i--){
        int result = (a[i] - '0')*2 + cnt;
        cnt = result/10;
        total[result%10]--;
        da.push_back(result%10);
    }
    bool yes = true;
    for(int i = 0;i < 10;i++)
        if (total[i]!=0)
            yes = false;
    if (cnt == 1){
        da.push_back(1);
        yes = false;
    }
    printf(yes?"Yes\n":"No\n");
    for (int i = da.size()-1;i >= 0;i--)
        cout << da[i];
    return 0;
}
