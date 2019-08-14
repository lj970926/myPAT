#include <iostream>
#include <vector>
using namespace std;

int order[205];
int stripes[10005];
int longest[10005];
int main()
{
    int n,m,l;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i = 1;i <= m;i++){
        int temp;
        scanf("%d",&temp);
        order[temp] = i;
    }
    scanf("%d",&l);
    for (int i = 0;i < l;i++)
        scanf("%d",&stripes[i]);
    longest[0] = order[stripes[0]] == 0? 0 : 1;
    for (int i = 1;i < l;i++){
        if (order[stripes[i]] == 0){
            longest[i] = longest[i-1];
        }
        else{
            int tempmax = 0;
            for (int j = 0;j < i;j++){
                if (order[stripes[j]]!= 0 && order[stripes[j]] <= order[stripes[i]]&&longest[j]>tempmax)
                    tempmax = longest[j];
            }
            longest[i] = tempmax + 1;
        }
    }
    int maxlen = 0;
    for (int i = 0;i < l;i++){
        if(longest[i] > maxlen){
            maxlen = longest[i];
        }
    }
    printf("%d",maxlen);
    return 0;
}
