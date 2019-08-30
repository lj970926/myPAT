#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
vector<int> ans;
bool flag;
int m, n;
void postorder(int index, int mode){
    if (2 * index <= n)
        postorder(index * 2, mode);
    if (index * 2 + 1 <= n)
        postorder(index * 2 + 1, mode);
    ans.push_back(tree[index]);
    if (mode == 0){
        if (index * 2 <= n && tree[index] < tree[index * 2])
            flag = false;
        if (index * 2 + 1 <= n && tree[index] < tree[index * 2 + 1])
            flag =false;
    }
    else{
        if (index * 2 <= n && tree[index] >= tree[index * 2])
            flag = false;
        if (index * 2 + 1 <= n && tree[index] >= tree[index * 2 + 1])
            flag = false;
    }
}

int main()
{
    scanf("%d %d", &m, &n);
    tree.resize(n + 1);
    for (int i = 0; i < m; i++){
        tree.clear();
        ans.clear();
        flag = true;
        for (int j = 1; j <= n; j++){
            scanf("%d", &tree[j]);
        }
        if (tree[1] >= tree[2]){
            postorder(1, 0);
            if (flag){
                printf("Max Heap\n");
            }
            else
                printf("Not Heap\n");
        }
        else{
            postorder(1, 1);
            if (flag){
                printf("Min Heap\n");
            }
            else
                printf("Not Heap\n");
        }
        for (int j = 0; j < ans.size(); j++){
            if (j != 0)
                printf(" ");
            printf("%d", ans[j]);
        }
        printf("\n");
    }
    return 0;
}
