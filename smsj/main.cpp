#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> father;

int fr(int x){
    if (x == father[x])
        return x;
    return fr(father[x]);
}

void u(int a, int b){
    int fa = fr(a),fb = fr(b);
    if (fa != fb)
        father[fa] = fb;
}

int main()
{
    scanf("%d %d",&n, &m);
    father.resize(n+1);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        u(a,b);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++)
        if (father[i] == i)
            ans++;
    printf("%d",ans);

    return 0;
}
