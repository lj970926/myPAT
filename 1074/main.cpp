#include <iostream>
#include <map>
using namespace std;
struct Node{
    int data, next;
};
map<int, Node> l;
int cnt = 0, lim;
int head, n, k;
int rev(int h){
    if (k == 0||cnt >= lim)
        return -1;
    int ne = l[h].next, p = ne, q = l[ne].next, r = l[q].next;
    for (int i = 0; i < k - 1; i++){
        l[q].next = p;
        p = q;
        q = r;
        r = l[q].next;
    }
    l[ne].next = q;
    l[h].next = p;
    cnt++;
    return ne;
}

int main()
{
    scanf("%d %d %d", &head, &n, &k);
    lim = n / k;
    for (int i = 0; i < n; i++){
        int a, d, ne;
        scanf("%d %d %d", &a, &d, &ne);
        l[a].data = d; l[a].next = ne;
    }
    l[-2].next = head;
    int p = -2;
    while(p != -1) p = rev(p);
    p = l[-2].next;
    while(p != -1){
        if (l[p].next == -1)
            printf("%05d %d %d\n", p, l[p].data, l[p].next);
        else
            printf("%05d %d %05d\n", p, l[p].data, l[p].next);
        p = l[p].next;
    }
    return 0;
}
