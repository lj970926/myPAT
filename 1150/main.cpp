#include <iostream>
#include <vector>
using namespace std;
const int maxn = 210;
int G[maxn][maxn];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b, dst;
        scanf("%d %d %d", &a, &b, &dst);
        G[a][b] = G[b][a] = dst;
    }
    int k, mind = 0x3fffffff, ans = -1;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        vector<int> tmp;
        vector<bool> vis(n + 1, false);
        int q;
        scanf("%d", &q);
        tmp.resize(q);
        for (int j = 0; j < q; j++)
            scanf("%d", &tmp[j]);
        int dis = 0, num = 0;
        bool flag = true;
        for (int j = 0; j < q - 1; j++){
            int a = tmp[j], b = tmp[j + 1];
            if (G[a][b] == 0){
                printf("Path %d: NA (Not a TS cycle)\n", i + 1);
                flag = false;
                break;
            }
            dis += G[a][b];
            if (!vis[a]){
                num++;
                vis[a] = true;
            }
        }
        if (!flag)
            continue;
        if (tmp[0] == tmp[q - 1] && num == n){
            if (q == n + 1)
                printf("Path %d: %d (TS simple cycle)\n", i + 1, dis);
            else
                printf("Path %d: %d (TS cycle)\n", i + 1, dis);
            if (dis  < mind){
                mind = dis;
                ans = i + 1;
            }
        }
        else{
            printf("Path %d: %d (Not a TS cycle)\n", i + 1, dis);
        }
    }
    printf("Shortest Dist(%d) = %d\n", ans, mind);
    return 0;
}
