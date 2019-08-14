#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;
int c,n,sp,m;
vector<int> cbk;
int G[maxn][maxn] = {0};
int d[maxn], mins = INF,minre = INF;
bool vis[maxn] = {false};
vector<int> pre[maxn],temp,ans;
void Dijkstra(){
    fill(d, d+ maxn, INF);
    d[0] = 0;
    for (int i = 0; i < n+1; i++){
        int u = -1, mind = INF;
        for (int j = 0; j < n+1; j++)
        if (!vis[j] && d[j] < mind){
            mind = d[j];
            u = j;
        }
        if (u == -1 || u == sp)
            return;
        vis[u] = true;
        for (int v = 0; v < n + 1; v++){
            if (!vis[v] && G[u][v] != 0){
                if (d[u] + G[u][v] < d[v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v] = d[u] + G[u][v];
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int u){
    temp.push_back(u);
    if (u == 0){
        int tmaxs = 0, send = 0;
        for (int i = temp.size() - 2; i >= 0; i--){
            send += (cbk[temp[i]] - c / 2);
            tmaxs = max(tmaxs, -send);

        }
        int ret = send + tmaxs;
        if (tmaxs < mins){
            ans = temp;
            minre = ret;
            mins =tmaxs;

        }
        else if (tmaxs == mins && ret < minre){
            minre = ret;
            ans = temp;
        }
        temp.pop_back();
        return;
    }
    for (int i = 0; i < pre[u].size(); i++){
            DFS(pre[u][i]);
    }
    temp.pop_back();
}

int main(){
    scanf("%d %d %d %d", &c, &n, &sp, &m);
    cbk.resize(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &cbk[i]);
    for (int i = 0; i < m; i++){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }
    Dijkstra();
    DFS(sp);
    printf("%d ", mins);
    for (int i = ans.size() - 1; i >= 0; i--){
        if (ans[i] != 0)
            printf("->");
        printf("%d", ans[i]);
    }
    printf(" %d", minre);
    return 0;
}
