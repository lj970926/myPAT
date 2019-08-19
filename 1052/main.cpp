#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int addr, key;
};
vector<Node> ori, l;

bool cmp(Node a, Node b){
    return a.key < b.key;
}

int main(){
    int n, h;
    ori.resize(100000);
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++){
        int a, k, n;
        scanf("%d %d %d", &a, &k, &n);
        ori[a].key = k;
        ori[a].addr = n;
    }
    for (int p = h; p != -1; p = ori[p].addr){
        Node t;
        t.addr = p;
        t.key = ori[p].key;
        l.push_back(t);
    }
    sort(l.begin(), l.end(), cmp);
    printf("%d ", l.size());
    for (int i = 0; i < l.size(); i++){
        printf("%05d\n%05d %d ", l[i].addr, l[i].addr, l[i].key);
    }
    printf("-1");
    return 0;
}
