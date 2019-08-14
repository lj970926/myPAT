#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Node{
    int v,w;
    Node(int v_, int w_):v(v_), w(w_){};
};
const int maxn = 1020;
const int inf = 0x3fffffff;
map<string, int> sti;
vector<Node> adj[maxn];
int n, m, k, ds;
int minn = -1;
double mind = 0, avgd = inf;
bool vis[maxn];
int d[maxn];

void dijkstra(int u){
    double avgdis = 0.0;
    int mdis = inf;
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
    d[u] = 0;
    for (int i = 0; i < n + m; i++){
        int v = -1, mindis = inf;
        for (int j = 1; j <= n + m; j++)
        if (!vis[j] && d[j] < mindis){
            mindis = d[j];
            v = j;
        }
        if (v == -1 || d[v] > ds)
            return;
        vis[v] = true;
        if (v <= n){
            avgdis += (1.0 * d[v] / n);
            if (d[v] < mdis)
                mdis = d[v];
        }
        for (int j = 0; j < adj[v].size(); j++){
            int nv = adj[v][j].v;
            int w = adj[v][j].w;
            if (!vis[nv] && d[v] + w < d[nv]){
                d[nv] = d[v] + w;
            }

        }
    }
    if (mdis > mind){
        mind = mdis;
        avgd = avgdis;
        minn = u - n;
    }
    else if (mdis == mind && avgdis < avgd){
        avgd = avgdis;
        minn = u - n;
    }
}

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    for (int i = 1; i <= n; i++)
        sti[to_string(i)] = i;
    for (int i = 1; i <= m; i++)
        sti["G" + to_string(i)] = i + n;
    for (int i = 0; i < k; i++){
        char p1[3], p2[3];
        int dist;
        scanf("%s %s %d", p1, p2, &dist);
        int u = sti[p1], v = sti[p2];
        adj[u].push_back(Node(v, dist));
        adj[v].push_back(Node(u, dist));
    }
    for (int i = 1; i <= m; i++){
        dijkstra(i + n);
    }
    if (minn == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", minn, mind, avgd);
    return 0;
}
