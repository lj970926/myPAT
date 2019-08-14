#include <iostream>

using namespace std;
const int INF = 0x3fffffff;
const int maxn = 1005;
int n, m, s;
int G[maxn][maxn] = {0};
int d[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s){
    fill(d, d + n, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++){
        int u = -1, mind = INF;
        for (int j = 0; j < n; j++){
            if (!vis[j] && d[j] < mind){
                u = j;
                mind = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 0; j < n; j++){
            if (!vis[j] && G[u][j] != 0 && d[u] + G[u][j] < d[j])
                d[j] = d[u] + G[u][j];
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++){
        int u,v,w;
        scanf( "%d %d %d", &u, &v, &w);
        G[u][v] = w;
    }
    Dijkstra(s);
    for (int i = 0; i < n; i++){
        printf("%d\n", d[i]);
    }

    return 0;
}
