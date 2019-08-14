#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int weight;
    vector<int> child;
};

int n,m,s;
vector<Node> tree;
vector<int> temppath;
bool first = true;

bool cmp(int a, int b){
    return tree[a].weight > tree[b].weight;
}

void dfs(int root,int tempweight){
    if (tempweight == s&&tree[root].child.size() == 0){
        first?first = false:printf("\n");
        for (int i = 0; i < temppath.size();i++){
            if (i != 0)
                printf(" ");
            printf("%d",temppath[i]);
        }
    }
    if (tempweight < s){
        for (int i = 0; i < tree[root].child.size();i++){
            int next = tree[root].child[i];
            temppath.push_back(tree[next].weight);
            dfs(next,tempweight + tree[next].weight);
            temppath.pop_back();
        }
    }
}

int main()
{
    scanf("%d %d %d",&n,&m,&s);
    tree.resize(n);
    for (int i = 0; i<n; i++)
        scanf("%d",&tree[i].weight);
    for (int i = 0; i < m; i++){
        int temp,num;
        scanf("%d %d",&temp,&num);
        for (int j = 0; j < num; j++){
            int k;
            scanf("%d",&k);
            tree[temp].child.push_back(k);
        }
    }
    for (int i = 0;i < n;i++)
        sort(tree[i].child.begin(),tree[i].child.end(),cmp);
    temppath.push_back(tree[0].weight);
    dfs(0,tree[0].weight);
    return 0;
}
