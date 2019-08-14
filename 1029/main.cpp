#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

int main()
{
    int n1,n2;
    int s[200005];
    cin >> n1;
    for (int i = 0;i < n1;i++)
        scanf("%d",&s[i]);
    s[n1] = 0x7fffffff;
    cin >> n2;
    int pos1 = 0,pos2 = 0;
    int temp;
    cin >> temp;
    for (int i = 1;i < (n1 + n2 + 1)/2;i++){
        if (s[pos1] < temp)
            pos1++;
        else if (pos2 < n2){
            cin >> temp;
            pos2++;
        }
        else
            temp = 0x7fffffff;
    }
    printf("%d",min(temp,s[pos1]));
    return 0;
}
