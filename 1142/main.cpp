#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 210;
int G[maxn][maxn];
bool h[maxn];
bool canins(vector<int>& a, int k){
    for (int i = 0; i < a.size(); i++){
        if (G[a[i]][k] == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        int k;
        scanf("%d", &k);
        vector<int> tmp;
        fill(h, h + maxn, false);
        bool flag = true;
        for (int j = 0; j < k; j++){
            int t;
            scanf("%d", &t);
            if (flag && canins(tmp, t)){
                tmp.push_back(t);
                h[t] = true;
            }
            else
                flag = false;
        }
        if (flag){
            int j;
            for (j = 1; j <= n; j++){
                if (!h[j] && canins(tmp, j)){
                    printf("Not Maximal\n");
                    break;
                }
            }
            if (j == n + 1)
                printf("Yes\n");
        }
        else
            printf("Not a Clique\n");
    }
    return 0;
}
