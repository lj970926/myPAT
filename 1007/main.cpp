#include <iostream>
using namespace std;
int num[10005], sum[10005];
int maxn = -1, mi, mj;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = num[i] + sum[i - 1];
    for (int i = 1; i <= n; i++){
        for (int j = i;j <= n; j++){
            int t  = sum[j] - sum[i - 1];
            if (t > maxn){
                maxn = t;
                mi = i;
                mj = j;
            }
        }
    }
    if (maxn < 0){
        printf("0 %d %d", num[1], num[n]);
    }
    else{
        printf("%d %d %d", maxn, num[mi], num[mj]);
    }

}
