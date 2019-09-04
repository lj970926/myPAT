#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 0x3fffffff;
struct Node{
    int v, cost, dis;
    Node(int v_, int c, int d):v(v_), cost(c), dis(d){};
};
int G[maxn][maxn], C[maxn][maxn];
vector<vector<int> > pre(maxn);
vector<int> path, tmp;
bool vis[maxn];
int d[maxn];
int n, m, s, dt, minc = inf;

void dijkstra(int u){
    fill(d, d + maxn, inf);
    d[u] = 0;
    for (int i = 0; i < n; i++){
        int v = -1, mind = inf;
        for (int j = 0; j < n; j++){
            if (!vis[j]&& d[j] < mind){
                mind = d[j];
                v = j;
            }
        }
        if (v == -1 || v == dt)
            return;
        vis[v] = true;
        for (int j = 0; j < n; j++){
            int w = G[v][j];
            if (!vis[j] && G[v][j] != 0){
                if (d[v] + w < d[j]){
                    pre[j].clear();
                    d[j] = d[v] + w;
                    pre[j].push_back(v);
                }
                else if (d[v] + w == d[j]){
                    pre[j].push_back(v);
                }
            }
        }
    }
}

void dfs(int u, int cost){
    if (u == s){
        if (cost < minc){
            minc = cost;
            tmp.push_back(u);
            path = tmp;
            tmp.pop_back();
        }
        return;
    }
    tmp.push_back(u);
    for (int i = 0; i < pre[u].size(); i++){
        int v = pre[u][i];
        dfs(v, cost + C[u][v]);
    }
    tmp.pop_back();
}

int main(){
    scanf("%d %d %d %d", &n, &m, &s, &dt);
    for (int i = 0; i < m; i++){
        int a, b, ds, cs;
        scanf("%d %d %d %d", &a, &b, &ds, &cs);
        G[a][b] = G[b][a] = ds;
        C[a][b] = C[b][a] = cs;
    }
    dijkstra(s);
    dfs(dt, 0);
    for (int i = path.size() - 1; i >= 0; i--){
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[dt], minc);
    return 0;
}
