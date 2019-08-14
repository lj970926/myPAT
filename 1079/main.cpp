#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int weight;
    vector<int> child;
};

int n;
double p, r, ans = 0.0;
vector<Node> tree;

void dfs(int num,double price){
    if (tree[num].child.size() == 0){
        ans += (price*tree[num].weight);
        return;
    }
    for (int i = 0; i < tree[num].child.size();i++){
        dfs(tree[num].child[i],price+price*r*0.01);
    }
}

int main()
{
    scanf("%d %lf %lf",&n,&p,&r);
    tree.resize(n);
    for (int i = 0; i < n;i++){
        int k;
        scanf("%d",&k);
        if (k == 0){
            scanf("%d",&tree[i].weight);
            tree[i].child.clear();
        }

        else{
            tree[i].child.resize(k);
            for (int j = 0; j < k;j++){
                scanf("%d",&tree[i].child[j]);
            }
        }
    }
    dfs(0,p);
    printf("%.1f",ans);
    return 0;
}
