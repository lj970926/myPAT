#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > tree;
int n, m;
int numl[105] = {0};
int maxl = 0;
void dfs(int t, int l){
    numl[l]++;
    if (l != maxl &&numl[l] > numl[maxl]){
        maxl = l;
    }
    for (int i = 0; i < tree[t].size();i++)
        dfs(tree[t][i],l+1);
}

int main()
{
    scanf("%d %d", &n, &m);
    tree.resize(n+1);
    for (int i = 0; i < m; i++){
        int t,k;
        scanf("%d %d",&t,&k);
        tree[t].resize(k);
        for (int j = 0;j < k; j++)
            scanf("%d",&tree[t][j]);
    }
    dfs(1,1);
    printf("%d %d",numl[maxl],maxl);
    return 0;
}
