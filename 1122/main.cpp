#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 20005;
int G[maxn][maxn];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        G[n1][n2] = G[n2][n1] = 1;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int q, fs;
        int que[maxn];
        bool res = true, h[maxn];
        fill(h, h + maxn, false);
        scanf("%d %d", &q, &fs);
        for (int j = 0; j < q - 1; j++)
            scanf("%d", &que[j]);
        if (q != n + 1)
            res = false;
        else{
            int tmp = fs;
            for (int j = 0; j < q - 1; j++){
                if (G[tmp][que[j]] != 1 || h[que[j]]){
                    res = false;
                    break;
                }
                tmp = que[j];
                h[que[j]] = true;

            }
            if (tmp != fs)
                res = false;
        }
        if (res)
            printf("YES\n");
        else
            printf("NO\n");


    }
    return 0;
}
