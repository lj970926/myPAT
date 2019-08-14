#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define M 1e-9
using namespace std;


vector<vector<int> > tree;
int n,root,num = 0;
double p,r,ans = 0.0;
void dfs(int t, double price){
    if (price > ans){
        ans = price;
        num = 1;
    }
    else if (abs(price - ans) < M){
        num++;
    }
    for (int i = 0; i < tree[t].size(); i++){
        dfs(tree[t][i],price + price * r *0.01);
    }
}

int main()
{

    scanf("%d %lf %lf",&n,&p,&r);
    tree.resize(n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d",&t);
        if (t != -1)
            tree[t].push_back(i);
        else
            root = i;
    }
    dfs(root,p);
    printf("%.2f %d",ans,num);
    return 0;
}
