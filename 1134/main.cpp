#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
vector<vector<int> > adj(maxn);
bool vis[maxn];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        fill(vis, vis + maxn, false);
        int nv, num = 0;
        scanf("%d", &nv);
        for (int j = 0; j < nv; j++){
            int v;
            scanf("%d", &v);
            for (int d = 0; d < adj[v].size(); d++){
                if (!vis[adj[v][d]])
                    num++;
            }
            vis[v] = true;
        }
        if (num == m)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
