#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;
struct Node{
    int dis, next;
    Node(int d, int n):dis(d), next(n){};
};
const int maxn = 1050;
const int inf = 0x3fffffff;
vector<Node> adj[maxn];
int n, k, m, ds, ans = -1;
double mind = 0, avgd = inf;
bool vis[maxn];
int d[maxn];
int sti(string s){
    return isdigit(s[0]) ? stoi(s) : stoi(s.substr(1)) + n;
}

void dijkstra(int s){
    fill(vis, vis + maxn, false);
    fill(d, d + maxn, inf);
    d[s] = 0;
    double tmd;
    bool flag = true;
    for (int i = 1; i <= n + m; i++){
        int v = -1, maxd = inf;
        for (int j = 1; j <= n + m; j++){
            if (!vis[j] && d[j] < maxd){
                maxd = d[j];
                v = j;
            }
        }
        if (v == -1 ||(v <= n && d[v] > ds))
            return;
        vis[v] = true;
        if (v <= n && flag){
            tmd = d[v];
            flag = false;
        }
        for (int j = 0; j < adj[v].size(); j++){
            int t = adj[v][j].next, w = adj[v][j].dis;
            if (!vis[t] && d[v] + w < d[t])
                d[t] = d[v] + w;
        }
    }
    double avg = 0;
    for (int i = 1; i <= n; i++)
        avg += d[i];
    avg /= n;
    if (tmd > mind){
        ans = s;
        mind = tmd;
        avgd = avg;
    }
    else if (tmd == mind && avg < avgd){
        ans = s;
        avgd = avg;
    }
}

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++){
        string sp1, sp2;
        int dis;
        cin >> sp1 >> sp2 >> dis;
        int p1 = sti(sp1), p2 = sti(sp2);
        adj[p1].push_back(Node(dis, p2));
        adj[p2].push_back(Node(dis, p1));
    }
    for (int i = n + 1; i <= n + m; i++){
        dijkstra(i);
    }
    if (ans == -1)
        printf("No Solution");
    else{
        string s = "G" + to_string(ans - n);
        printf("%s\n%.1f %.1f", s.c_str(), mind, avgd);
    }
    return 0;
}
