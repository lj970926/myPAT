#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 205;
const int inf = 0x3fffffff;
map<string, int> sti;
vector<int> hap;
vector<string> its;
int G[maxn][maxn];
int n,k;
bool vis[maxn] = {false};
int d[maxn], p[maxn], h[maxn], num[maxn], pnum[maxn];
void dijkstra(int u){
    fill (d, d + maxn, inf);
    h[u] = 0;
    p[u] = -1;
    d[u] = 0;
    pnum[u] = 0;
    num[u] = 1;
    for (int i = 0; i < n; i++){
        int v = -1, md = inf;
        for (int j = 0; j < n; j++)
        if (!vis[j] && d[j] < md){
            md = d[j];
            v = j;
        }
        if (v == -1) return;
        vis[v] = true;
        for (int t = 0; t < n; t++){
            if (!vis[t] && G[v][t] != 0){
                if (d[v] + G[v][t] < d[t]){
                    d[t] = d[v] + G[v][t];
                    h[t] = h[v] + hap[t];
                    p[t] = v;
                    num[t] = num[v];
                    pnum[t] = pnum[v] + 1;
                }else if (d[v] + G[v][t] == d[t]){
                    num[t] += num[v];
                    if (h[v] + hap[t] > h[t]){
                        h[t] = h[v] + hap[t];
                        p[t] = v;
                        pnum[t] = pnum[v] + 1;
                    }else if (h[v] + hap[t] == h[t] && pnum[v] + 1 < pnum[t]){
                        p[t] = v;
                        pnum[t] = pnum[v] + 1;
                    }
                }

            }
        }
    }
}

int main()
{
    string start;
    cin >> n >> k >> start;
    hap.resize(n);
    its.resize(n);
    sti[start] = 0;
    hap[0] = 0;
    its[0] = start;
    for (int i = 1; i < n; i++){
        string s; int t;
        cin >> s >> t;
        sti[s] = i;
        hap[i] = t;
        its[i] = s;
    }
    for (int i = 0; i < k; i++){
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        G[sti[s1]][sti[s2]] = G[sti[s2]][sti[s1]] = w;
    }
    dijkstra(sti[start]);
    vector<int> ans;
    int i = sti["ROM"];
    while(i != -1){
        ans.push_back(i);
        i = p[i];
    }
    printf("%d %d %d %d\n", num[sti["ROM"]], d[sti["ROM"]], h[sti["ROM"]], h[sti["ROM"]] / pnum[sti["ROM"]]);
    for (int i = ans.size() - 1; i >= 0; i--){
        if (i != ans.size() - 1)
            printf("->");
        printf(its[ans[i]].c_str());
    }
    return 0;
}
