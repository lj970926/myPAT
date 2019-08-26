#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10005;
const int inf = 0x3fffffff;
int G[maxn][maxn], n, k, ds[maxn], p[maxn], cr[maxn], deg[maxn];
bool vis[maxn];
vector<int> ans;
void dijkstra(int s){
    fill(vis, vis + maxn, false);
    fill(ds, ds + maxn, inf);
    fill(p, p + maxn, -1);
    fill(cr, cr + maxn, 0);
    ds[s] = 0;
    for (int i = 0; i < maxn; i++){
        int v = -1, mind = inf;
        for (int j = 0; j < maxn; j++){
            if (!vis[j] && ds[j] < mind){
                v = j;
                mind = ds[j];
            }
        }
        if (v == -1)
            return;
        vis[v] = true;
        for (int j = 0; j < maxn; j++){
            if (!vis[j] && G[v][j] != 0){
                if (ds[v] + 1 < ds[j]){
                    ds[j] = ds[v] + 1;
                    p[j] = v;
                    cr[j] = (deg[j] > 2 ? cr[v] + 1 : cr[v]);
                }
                else if (ds[v] + 1 == ds[j]){
                    int num = (deg[j] > 2 ? cr[v] + 1 : cr[v]);
                    if (num < cr[j]){
                        cr[j] = num;
                        p[j] = v;
                    }
                }
            }
        }
    }
}

void findpath(int d){
    ans.clear();
    while (d != -1){
        ans.push_back(d);
        d = p[d];
    }

}

void showpath(int d){
    printf("%d\n", ds[d]);
    int p, line = -1;
    for (int i = ans.size() - 1; i >= 0; i--){
        if (i == 0 || G[ans[i]][ans[i - 1]] != line){
            if (line != -1){
                printf("Take Line#%d from %04d to %04d\n", line, p, ans[i]);
            }
            if (i != 0){
                line = G[ans[i]][ans[i - 1]];
                p = ans[i];
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int m, p;
        scanf("%d %d", &m, &p);
        for (int j = 1; j < m; j++){
            int t;
            scanf("%d", &t);
            G[t][p] = G[p][t] = i;
            deg[t]++; deg[p]++;
            p = t;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int s, d;
        scanf("%d %d", &s, &d);
        dijkstra(s);
        findpath(d);
        showpath(d);
    }
    return 0;
}
