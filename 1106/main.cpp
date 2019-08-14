#include <iostream>
#include <vector>
#define M 1e-5
#include <cmath>
using namespace std;

int n,num = 0;
double p,r,minp = 10e10;
vector<vector<int> > tree;

void dfs(int t, double price){
    if (tree[t].size() == 0){
        if (abs(price - minp) < M)
            num++;
        else if(price < minp){
            minp = price;
            num = 1;
        }
        return;
    }
    for (int i = 0; i< tree[t].size();i++)
        dfs(tree[t][i], price + price * r * 0.01);
}

int main()
{
    scanf("%d %lf %lf",&n,&p,&r);
    tree.resize(n);
    for (int i = 0; i < n;i++){
        int k;
        scanf("%d",&k);
        tree[i].resize(k);
        for (int j =0; j < k; j++)
            scanf("%d",&tree[i][j]);
    }
    dfs(0,p);
    printf("%.4f %d",minp, num);
    return 0;
}
