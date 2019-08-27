#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tre;
int dfs(int li, int ri){
    if (li == ri)
        return 1;
    int m;
    for (m = li + 1; m < ri && abs(tre[m]) < abs(tre[li]); m++) ;
    if (tre[li] < 0){
        int a = (li + 1 < ri ? tre[li + 1] : 1), b = (m < ri ? tre[m] : 1);
        if (a < 0 || b < 0)
            return -1;
    }
    int nl = dfs(li + 1, m), nr = dfs(m, ri);
    if (nl == -1 || nr == -1 || nl != nr)
        return -1;
    if (tre[li] < 0)
        return nl;
    else
        return nl + 1;
}

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int n;
        scanf("%d", &n);
        tre.clear();
        tre.resize(n);
        bool flag = true;
        for (int j = 0; j < n; j++)
            scanf("%d", &tre[j]);
        if (tre[0] < 0)
            flag = false;
        else{
            int res = dfs(0, n);
            if (res == -1)
                flag = false;
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
