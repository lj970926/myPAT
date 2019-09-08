#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Node{
    int addr, key, next;
};
Node link[maxn];
vector<Node> ans;

bool cmp(Node a, Node b){
    return a.key < b.key;
}

int main(){
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++){
        int addr, key, next;
        scanf("%d %d %d", &addr, &key, &next);
        link[addr].addr = addr;
        link[addr].key = key;
        link[addr].next = next;
    }
    for (int p = h; p != -1; p = link[p].next){
        ans.push_back(link[p]);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d ", int(ans.size()));
    for (int i = 0; i < ans.size(); i++){
        printf("%05d\n%05d %d ", ans[i].addr, ans[i].addr, ans[i].key);
    }
    printf("-1\n");
    return 0;
}
