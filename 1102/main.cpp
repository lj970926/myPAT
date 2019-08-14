#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int l = -1,r = -1;
};
Node tree[15];
bool hashT[15] = {false};
int root = -1;
bool first = true;
void leveltr(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int t = q.front();
        q.pop();
        first?first = false:printf(" ");
        printf("%d",t);
        if (tree[t].r != -1)
            q.push(tree[t].r);
        if (tree[t].l != -1)
            q.push(tree[t].l);
    }
    printf("\n");
    first = true;
}

void inorder(int root){
    if (root == -1)
        return;
    inorder(tree[root].r);
    first?first = false:printf(" ");
    printf("%d",root);
    inorder(tree[root].l);
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2;j++){
            char c = getchar();
            if (c != '-'){
                j == 0? tree[i].l = c - '0':tree[i].r = c-'0';
                hashT[c-'0'] = true;
            }
            getchar();
        }
    while(hashT[++root]) ;
    leveltr(root);
    inorder(root);
    return 0;
}
