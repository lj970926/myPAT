#include <iostream>
#include <algorithm>
using namespace std;
int n;
int father[1005];
int hobby[1005] = {0};
int num[1005] = {0};
int fr(int x){
    if (father[x] == x)
        return x;
    int r = fr(father[x]);
    father[x] = r;
    return r;
}

void u(int a, int b){
    int fa = fr(a), fb = fr(b);
    if (fa != fb)
        father[fa] = fb;
}

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        father[i] = i;
        int k;
        scanf("%d: ",&k);
        for (int j = 0; j < k; j++){
            int t;
            scanf("%d",&t);
            if (hobby[t] != 0)
                u(i,hobby[t]);
            else
                hobby[t] = i;
        }

    }
    for (int i = 1; i <= n;i++)
        num[fr(i)]++;
    sort(num, num +n+1,cmp);
    int ans = 0;
    for (int i = 0;i < n && num[i]!= 0;i++) ans++;
    printf("%d\n",ans);
    for (int i = 0;num[i] != 0;i++){
        if (i != 0)
            printf(" ");
        printf("%d",num[i]);
    }
    return 0;
}
