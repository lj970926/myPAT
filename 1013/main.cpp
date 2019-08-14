#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
bool vis[maxn] = {false};
int G[maxn][maxn];
int n, m, k, t;

void dfs(int u){
    vis[u] = true;
    for (int v = 1; v <= n; v++){
        if (v != t && G[u][v] != 0 && !vis[v]){
            dfs(v);
        }
    }
}

void DFS(){
    fill(vis, vis + n + 1,false);
    int ans = 0;
    for (int i = 1; i <= n;i++){
        if (i != t && !vis[i]){
            ans++;
            dfs(i);
        }

    }
    printf("%d\n",ans - 1);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    for (int i = 0; i < k; i++){
        scanf("%d", &t);
        DFS();
    }
    return 0;
}
