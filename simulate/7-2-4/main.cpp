#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1050;
const int inf = 0x3fffffff;
struct Node{
    int next, time;
    Node(int n, int t):next(n), time(t){};
};
vector<int> car;
int ns, na, ti = 1;
int G[maxn][maxn], stn[maxn][maxn], p[maxn][maxn], ds[maxn][maxn];
vector<vector<int> > r(maxn);
vector<int> path;
bool vis[maxn];
int sti(string s){
    if (s[0] == 'A')
        return ns + stoi(s.substr(2));
    else
        return stoi(s);
}

void dijkstra(int s){
    fill(ds[s], ds[s] + maxn, inf);
    fill(vis, vis + maxn, false);
    ds[s][s] = 0;
    for (int i = 1; i <= ns + na; i++){
        int u = -1, mind = inf;
        for (int j = 1; j <= ns + na; j++){
            if (!vis[j] && ds[s][j] < mind){
                mind = ds[s][j];
                u = j;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 1; j <= ns + na; j++){
            if (!vis[j] && G[u][j] != 0){
                if (ds[s][u] + G[u][j] < ds[s][j]){
                    ds[s][j] = ds[s][u] + G[u][j];
                    p[s][j] = u;
                    stn[s][j] = stn[s][u] + 1;
                }
                else if (ds[s][u] + G[u][j] == ds[s][j] && stn[s][u] + 1 < stn[s][j]){
                    p[s][j] = u;
                    stn[s][j] = stn[s][u] + 1;
                }
            }
        }
    }
}
bool cmp(int a, int b){
    if (ds[a][ti] != ds[b][ti])
        return ds[a][ti] < ds[b][ti];
    if (car[a - ns] != car[b - ns])
        return car[a - ns] > car[b - ns];
    return stn[a][ti] < stn[b][ti];
}

void findpath(int s, int d){
    path.push_back(d);
    if (d == s){
        return;
    }
    findpath(s, p[s][d]);
}

string its(int x){
    if (x <= ns)
        return to_string(x);
    return ("A-" + to_string(x - ns));
}

void showpath(int s, int d){
    path.clear();
    findpath(s, d);
    for (int i = path.size() - 1; i >= 0; i--){
        if (i != path.size() - 1)
            printf(" ");
        printf(its(path[i]).c_str());
    }
    printf("\n");
}

int main()
{
    scanf("%d %d", &ns, &na);
    car.resize(na + 1);
    for (int i = 1; i <= na; i++){
        scanf("%d", &car[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        string s1, s2;
        int dis;
        cin >> s1 >> s2 >> dis;
        int a = sti(s1), b = sti(s2);
        G[a][b] = G[b][a] = dis;
    }
    for (int i = ns + 1; i <= ns + na; i++)
        dijkstra(i);
    for (int i = 1; i <= ns; i++){
        r[i].resize(na);
        for (int j = 0; j < na; j++)
            r[i][j] = ns + j + 1;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int t;
        scanf("%d", &t);
        ti = t;
        sort(r[t].begin(), r[t].end(), cmp);
        int j;
        for (j = 0; j < na; j++){
            int cen = r[t][j];
            if (car[cen - ns] > 0){
                car[cen - ns]--;
                showpath(cen, t);
                printf("%d\n", ds[cen][t]);
                break;
            }
        }
        if (j == na)
            printf("All Busy\n");
    }
    return 0;
}
