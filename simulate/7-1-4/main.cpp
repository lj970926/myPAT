#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
vector<int> path;
bool flag = true;
int n;
void dfs(int index, int mode){
    if (index > n){
        if (index % 2 == 0){
             for (int i = 0; i < path.size(); i++){
                if (i != 0)
                    printf(" ");
                printf("%d", path[i]);
            }
            printf("\n");
        }
        return;
    }
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
    path.push_back(tree[index]);
    dfs(index * 2 + 1, mode);
    dfs(index * 2, mode);
    path.pop_back();

}

int main()
{
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++){
        scanf("%d", &tree[i]);
    }
    int mode;
    if (tree[1] >= tree[n])
        mode = 0;
    else
        mode = 1;
    dfs(1, mode);
    if (flag)
        printf(mode == 0 ? "Max Heap\n" : "Min Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}
