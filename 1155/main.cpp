#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
vector<int> tmppath;
bool flag;
int n;
void dfs(int index, int mode){
    if (index > n){
        if (index % 2 == 0){
            for (int i = 0; i < tmppath.size(); i++){
                if (i != 0)
                    printf(" ");
                printf("%d", tmppath[i]);
            }
            printf("\n");
        }
        return;
    }
    tmppath.push_back(tree[index]);
    if (mode == 0){
        if (index * 2 <= n && tree[index * 2] > tree[index])
            flag = false;
        if (index * 2 + 1 <= n && tree[index * 2 + 1] > tree[index])
            flag = false;
    }
    else{
        if (index * 2 <= n && tree[index * 2] < tree[index])
            flag = false;
        if (index * 2 + 1 <= n && tree[index * 2 + 1] < tree[index])
            flag = false;
    }
    dfs(index * 2 + 1, mode);
    dfs(index * 2, mode);
    tmppath.pop_back();
}

int main()
{
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tree[i]);
    flag = true;
    dfs(1, tree[1] > tree[2] ? 0 : 1);
    if (flag)
        printf(tree[1] > tree[2] ? "Max Heap\n" : "Min Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}
