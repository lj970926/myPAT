#include <iostream>
#include <cstring>
using namespace std;
char s[100005];

int main()
{
    scanf("%s",s);
    int len = strlen(s);
    int tpa = 0,ans = 0,tp = 0;
    for (int i = 0;i < len;i++){
        switch(s[i]){
            case 'P':tp++;break;
            case 'A':tpa += tp;break;
            case 'T':ans  = (ans + tpa) % 1000000007;break;
        }
    }
    printf("%d",ans);
    return 0;
}
