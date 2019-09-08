#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100005;
struct Node{
    int addr, key;
};
Node link[maxn];
vector<Node> rev;
int main()
{
    int h, n, k;
    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &h, &n, &k);
    for (int i = 0; i < n; i++){
        int addr, key, ne;
        scanf("%d %d %d", &addr, &key, &ne);
        link[addr].key = key;
        link[addr].addr = ne;
    }
    int cnt = 0;
    Node first, second, third;
    for (int p = h; p != -1; p = link[p].addr){
        cnt++;
        Node t;
        t.addr = p;
        t.key = link[p].key;
        if (cnt == k - 1)
            third = t;
        else if (cnt == k)
            first = t;
        else if (link[p].addr == -1)
            second = t;
        else
            rev.push_back(t);
    }
    if (k != 1)
        rev.push_back(third);
    else{
        rev.clear();
    }
    rev.push_back(second);
    printf("%05d %d ", first.addr, first.key);
    for (int i = rev.size() - 1; i >= 0; i--){
        printf("%05d\n%05d %d ", rev[i].addr, rev[i].addr, rev[i].key);
    }
    printf("-1");
    return 0;
}
