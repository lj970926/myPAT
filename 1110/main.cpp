#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int left, right;
};
bool h[25] = {false};
vector<Node> tree;
int n;

int lorder(int r){
    int total = 1, last = r;
    queue<int> q;
    q.push(r);
    while (!q.empty()){
        int t = q.front();
        q.pop();
        if (tree[t].left != -1){
            q.push(tree[t].left);
            total++;
            last = tree[t].left;
        }
        else if (total == n) return last;
        else return -1;
        if (tree[t].right != -1){
            q.push(tree[t].right);
            total++;
            last = tree[t].right;
        }
        else if (total == n) return last;
        else return -1;
    }
}

int main()
{

    scanf("%d", &n);
    tree.resize(n);
    for (int i = 0; i < n; i++){
        getchar();
        char c1, c2;
        scanf("%c %c", &c1, &c2);
        if (c1 == '-')
            tree[i].left = -1;
        else{
            int nc = c1 - '0';
            tree[i].left = nc;
            h[nc] = true;
        }
        if (c2 == '-')
            tree[i].right = -1;
        else{
            int nc = c2 - '0';
            tree[i].right = nc;
            h[nc] = true;
        }
    }
    int root;
    for (int i = 0; i < n; i++)
        if (!h[i]){
            root = i;
            break;
        }
    int res = lorder(root);
    if (res == -1){
        printf("NO %d", root);
    }
    else{
        printf("YES %d", res);
    }
    return 0;
}
