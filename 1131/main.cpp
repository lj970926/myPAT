#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000;
int line[maxn][maxn];
vector<vector<int> > adj(maxn);
vector<int> tmp, ans;
int s, d, mincnt, mintrans;
bool vis[maxn];
const int inf = 0x3fffffff;
void dfs(int u, int preline, int numtrans){
    if (u == d){
        int cnt = tmp.size();
        if (cnt < mincnt ||(cnt == mincnt && numtrans < mintrans)){
            ans = tmp;
            mincnt = cnt;
            mintrans = numtrans;
        }
        return;
    }
    for (int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if (!vis[v]){
            int temp = numtrans;
            if (line[u][v] != preline) temp++;
            vis[v] = true;
            tmp.push_back(v);
            dfs(v, line[u][v], temp);
            tmp.pop_back();
            vis[v] = false;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int m, pre;
        scanf("%d %d", &m, &pre);
        for (int j = 1; j < m; j++){
            int t;
            scanf("%d", &t);
            line[pre][t] = line[t][pre] = i + 1;
            adj[pre].push_back(t);
            adj[t].push_back(pre);
            pre = t;
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d %d", &s, &d);
        mincnt = inf;
        mintrans = inf;
        ans.clear();
        vis[s] = true;
        tmp.push_back(s);
        dfs(s, 0, -1);
        tmp.pop_back();
        vis[s] = false;
        printf("%d\n", mincnt - 1);
        int preline = 0, pretrans = s;
        for (int j = 1; j < ans.size(); j++){
            if (line[ans[j - 1]][ans[j]] != preline){
                if (preline != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preline, pretrans, ans[j - 1]);
                preline = line[ans[j - 1]][ans[j]];
                pretrans = ans[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, pretrans, d);
    }
}
