#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int w[3];
    int next;
    Node(int l, int t, int n){
        w[0] = l; w[1] = t; w[2] = 1; next = n;
    };
};
const int maxn = 505;
const int inf = 0x3fffffff;
int n,m;
vector<Node> adj[maxn];
int d[maxn], f[maxn], p[maxn];
bool vis[maxn];
void dijkstra(int s, int i, int j){
    fill(d, d + maxn, inf);
    fill(f, f + maxn, inf);
    fill(p, p + maxn, inf);
    fill(vis, vis + maxn, false);
    d[s] = 0;
    f[s] = 0;
    p[s] = -1;
    for (int t = 0; t < n; t++){
        int v = -1, mind = inf;
        for (int i = 0; i < n; i++){
            if (!vis[i] && d[i] < mind){
                mind = d[i];
                v = i;
            }
        }
        if (v == -1)
            return;
        vis[v] = true;
        for (int m = 0; m < adj[v].size(); m++){
            int n = adj[v][m].next, w1 = adj[v][m].w[i], w2 = adj[v][m].w[j];
            if (!vis[n]){
                if (d[v] + w1 < d[n]){
                    d[n] = d[v] + w1;
                    f[n] = f[v] + w2;
                    p[n] = v;
                }
                else if (d[v] + w1 == d[n] && f[v] + w2 < f[n]){
                    f[n] = f[v] + w2;
                    p[n] = v;
                }
            }
        }
    }
}

vector<int> finda(int d){
    vector<int> ans;
    int v = d;
    while (v != -1){
        ans.push_back(v);
        v = p[v];
    }
    return ans;
}

void show(vector<int> ans){
    for (int i = ans.size() - 1; i >= 0; i--){
        if (i != ans.size() - 1)
            printf(" -> ");
        printf("%d", ans[i]);

    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int v1, v2, one, len, time;
        scanf("%d %d %d %d %d", &v1, &v2, &one, &len, &time);
        adj[v1].push_back(Node(len, time, v2));
        if (one == 0)
            adj[v2].push_back(Node(len, time, v1));
    }
    int s, d1;
    scanf("%d %d", &s, &d1);
    dijkstra(s, 0, 1);

    vector<int> ans1 = finda(d1);
    int minl = d[d1];
    dijkstra(s, 1, 2);
    vector<int> ans2 = finda(d1);
    int mint = d[d1];
    if (ans1 == ans2){
        printf("Distance = %d; Time = %d: ", minl, mint);
        show(ans1);
    }
    else{
        printf("Distance = %d: ", minl);
        show(ans1);
        printf("\nTime = %d: ", mint);
        show(ans2);
    }
    return 0;
}
