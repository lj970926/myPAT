#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10005;
const int inf = 0x3fffffff;
struct Node{
    int next, line;
    Node(int n, int l):next(n), line(l){};
};
vector<vector<Node> >adj(maxn);
vector<int> ans;
bool vis[maxn];
int p[maxn], cr[maxn], n, k, ds[maxn], ln[maxn];

void dijkstra(int s, int d){
    fill(vis, vis + maxn, false);
    fill(p, p + maxn, -1);
    fill(cr, cr + maxn, inf);
    fill(ds, ds + maxn, inf);
    fill(ln, ln + maxn, 0);
    ds[s] = 0;
    cr[s] = 0;
    for (int i = 0; i < maxn; i++){
        int v = -1, mind = inf;
        for (int j = 0; j < maxn; j++){
            if (!vis[j] && ds[j] < mind){
                v = j;
                mind = ds[j];
            }
        }
        if (v == -1 || v == d)
            return;
        vis[v] = true;
        for (int j = 0; j < adj[v].size(); j++){
            int ne = adj[v][j].next, lin = adj[v][j].line;
            if (!vis[ne]){
                int crs = (lin == ln[v] ? cr[v] : cr[v] + 1);
                if (ds[v] + 1 < ds[ne]){
                    ds[ne] = ds[v] + 1;
                    ln[ne] = lin;
                    p[ne] = v;
                    cr[ne] = crs;
                }
                else if (ds[v] + 1 == ds[ne] && crs < cr[ne]){
                    ln[ne] = lin;
                    cr[ne] = crs;
                    p[ne] = v;
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

void showpath(int s, int d){
    printf("%d\n",ds[d]);
    cr[s] = 1;
    int p = s;
    for (int i = ans.size() - 3; i >= -1; i--){
        if (i == -1 || cr[ans[i]] != cr[ans[i + 1]]){
            printf("Take Line#%d from %04d to %04d.\n", ln[ans[i + 1]], p, ans[i + 1]);
            p = ans[i + 1];
        }
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int m, p;
        scanf("%d", &m);
        for (int j = 0; j < m; j++){
            int t;
            scanf("%d", &t);
            if (j != 0){
                adj[p].push_back(Node(t, i));
                adj[t].push_back(Node(p, i));
            }
            p = t;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int s, d;
        scanf("%d %d", &s, &d);
        dijkstra(s, d);
        findpath(d);
        showpath(s, d);
    }
}
