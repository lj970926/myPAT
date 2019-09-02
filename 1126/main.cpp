#include <iostream>
using namespace std;
const int maxn = 510;
int G[maxn][maxn], degree[maxn];
int cnt;
bool vis[maxn];
int n, m;
void dfs(int index){
    vis[index] = true;
    cnt++;
    for (int i = 1; i <= n; i++){
        if (!vis[i] && G[index][i] != 0)
            dfs(i);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }
    int odd = 0;
    for (int i = 1; i <= n; i++){
        if (degree[i] % 2 != 0)
            odd++;
        if (i != 1)
            printf(" ");
        printf("%d", degree[i]);

    }
    dfs(1);
    if (odd == 0 && cnt == n)
        printf("\nEulerian\n");
    else if (odd == 2 && cnt == n)
        printf("\nSemi-Eulerian\n");
    else
        printf("\nNon-Eulerian\n");
    return 0;
}
