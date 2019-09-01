#include <iostream>
#include <string>
using namespace std;
struct Node{
    int left, right;
};
const int maxn = 25;
Node tree[maxn];
bool isroot[maxn];
int maxi = -1, last = -1;
void dfs(int index, int root){
    if (index > maxi){
        maxi = index;
        last = root;
    }
    if (tree[root].left != -1)
        dfs(index * 2, tree[root].left);
    if (tree[root].right != -1)
        dfs(index * 2 + 1, tree[root].right);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 != "-"){
            tree[i].left = stoi(s1);
            isroot[stoi(s1)] = true;
        }
        else
            tree[i].left = -1;
        if (s2 != "-"){
            tree[i].right = stoi(s2);
            isroot[stoi(s2)] = true;
        }
        else
            tree[i].right = -1;
    }
    int root;
    for (root = 0; isroot[root]; root++) ;
    dfs(1, root);
    if (maxi == n)
        printf("YES %d\n", last);
    else
        printf("NO %d\n", root);
}
