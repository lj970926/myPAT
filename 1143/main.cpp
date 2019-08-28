#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
unordered_map<int, long long> tre;
vector<int> pre;
const long long root = 0x3ffffffff;
void create(int i, int j){
    if (j - i <= 1)
        return;
    int mid;
    for (mid = i + 1; mid < j && pre[mid] < pre[i]; mid++) ;
    if (mid - i != 1){
        tre[pre[i + 1]] = pre[i];
        create(i + 1, mid);
    }
    if (mid != j){
        tre[pre[mid]] = pre[i];
        create(mid, j);
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    pre.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    tre[pre[0]] = root;
    create(0, n);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        bool fda = true, fdb = true;
        if (tre.find(a) == tre.end())
            fda = false;
        if (tre.find(b) == tre.end())
            fdb = false;
        if (!fda && !fdb){
            printf("ERROR: %d and %d are not found.\n", a, b);
            continue;
        }
        if (!fda){
            printf("ERROR: %d is not found.\n", a);
            continue;
        }
        if (!fdb){
            printf("ERROR: %d is not found.\n", b);
            continue;
        }
        unordered_set<int> path;
        long long key = a;
        while (key != root){
            path.insert(key);
            key = tre[key];
        }
        key = b;
        while (path.find(key) == path.end()){
            key = tre[key];
        }
        if (key == a)
            printf("%d is an ancestor of %d.\n", a, b);
        else if (key == b)
            printf("%d is an ancestor of %d.\n", b, a);
        else
            printf("LCA of %d and %d is %d.\n", a, b, key);
    }
    return 0;
}
