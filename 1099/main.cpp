#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    int data,left,right,level;
};

int n,i = 0;
vector<int> key;
vector<Node> tree;
bool first = true;
void inorder(int root){
    if (root == -1)
        return;
    inorder(tree[root].left);
    tree[root].data = key[i++];
    inorder(tree[root].right);
}

void lorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        first?first = false:printf(" ");
        printf("%d",tree[t].data);
        if (tree[t].left != -1)
            q.push(tree[t].left);
        if (tree[t].right != -1)
            q.push(tree[t].right);
    }
}

int main()
{
    scanf("%d", &n);
    key.resize(n);
    tree.resize(n);
    for (int i = 0; i < n;i++)
        scanf("%d %d",&tree[i].left,&tree[i].right);
    for (int i = 0; i < n;i++)
        scanf("%d",&key[i]);
    sort(key.begin(),key.end());
    inorder(0);
    lorder(0);
    return 0;
}
