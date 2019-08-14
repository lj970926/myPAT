#include <iostream>

using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;
int n,m,s,t;
int G[maxn][maxn] = {0};
bool vis[maxn] = {false};
int mnum[maxn] = {0};
int d[maxn];
int teams[maxn];
int num[maxn] = {0};
void Dijkstra(){
    fill(d,d+n,INF);
    d[s] = 0;
    mnum[s] = teams[s];
    num[s] = 1;
    for (int i = 0; i < n; i++){
        int u = -1, mind = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && d[j] < mind){
                mind = d[j];
                u = j;
            }
        if (u == -1 || u == t)
            return;
        vis[u] = true;
        for (int j = 0; j < n; j++){
            if (!vis[j] && G[u][j] != 0){
                if (d[u] + G[u][j] < d[j]){
                    mnum[j] = mnum[u] + teams[j];
                    d[j] = d[u] + G[u][j];
                    num[j] = num[u];
                } else if (d[u] + G[u][j] == d[j]) {
                    if ( mnum[u] + teams[j] > mnum[j])
                        mnum[j] = mnum[u] + teams[j];
                    num[j] += num[u];
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &teams[i]);
    for (int i = 0; i < m; i++){
        int c1, c2, w;
        scanf("%d %d %d", &c1, &c2, &w);
        G[c1][c2] = G[c2][c1] = w;
    }
    Dijkstra();
    printf("%d %d", num[t], mnum[t]);
    return 0;
}
