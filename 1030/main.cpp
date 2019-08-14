#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;

int e[510][510],cost[510][510],dis[510];
vector<int> pre[510];
bool visited[510];
int n,m,s,d;
vector<int> path,temppath;
int mincost = INT_MAX;
void dfs(int d){
    temppath.push_back(d);
    if (d == s){
            int temp = 0;
        for (int i = 0;i < temppath.size()-1;i++)
            temp += cost[temppath[i]][temppath[i+1]];
        if (temp < mincost){
            mincost = temp;
            path = temppath;
        }
        temppath.pop_back();
        return;

    }
    for (int i = 0;i < pre[d].size();i++)
        dfs(pre[d][i]);
    temppath.pop_back();
    return;
}

int main()
{
    fill(e[0],e[0]+510*510,INT_MAX);
    fill(cost[0],cost[0]+510*510,INT_MAX);
    fill(dis,dis+510,INT_MAX);
    fill(visited,visited + 510,false);
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for (int i = 0;i < m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        scanf("%d %d",&e[u][v],&cost[u][v]);
        e[v][u] = e[u][v];
        cost[v][u] = cost[u][v];
    }
    dis[s] = 0;
    for (int i = 0;i < n;i++){
        int u = -1,mindis = INT_MAX;
        for (int v = 0;v < n;v++)
        if (!visited[v]&&dis[v] < mindis){
            mindis = dis[v];
            u = v;
        }
        visited[u] = true;
        for (int v = 0;v < n;v++){
            if (!visited[v]&&(e[u][v] < INT_MAX)){
                if (dis[u] + e[u][v] < dis[v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                    dis[v] = dis[u] + e[u][v];
                }
                else if (dis[u] + e[u][v]==dis[v])
                    pre[v].push_back(u);
            }

        }
    }
    dfs(d);
    for (int i = path.size()-1;i>=0;i--)
        printf("%d ",path[i]);
    printf("%d %d",dis[d],mincost);
    return 0;
}
