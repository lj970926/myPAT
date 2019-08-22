#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int p[maxn];

int findF(int x){
    if (p[x] == x)
        return x;
    int fx = findF(p[x]);
    p[x] = fx;
    return fx;
}

void Union(int x, int y){
    int fx = findF(x), fy = findF(y);
    if (fx != fy)
        p[fy] = fx;
}

int main()
{
    int n, num = 0;
    scanf("%d", &n);
    for (int i = 1; i <= maxn; i++)
        p[i] = i;
    for (int i = 0; i < n; i++){
        int k, x;
        scanf("%d %d", &k, &x);
        num = max(num, x);
        for (int j = 1; j < k; j++){
            int t;
            scanf("%d", &t);
            num = max(num, t);
            Union(x, t);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= num; i++){
        if (p[i] == i)
            cnt++;
    }
    printf("%d %d\n", cnt, num);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if (findF(x) == findF(y))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
