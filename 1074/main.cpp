#include <iostream>

using namespace std;
struct Node{
    int key, next;
};
Node l[100005];
int n, k, h;
bool reversable(int h){
    int p = l[h].next;
    int i = 0;
    while(p != -1 && i < k){
        i++;
        p = l[p].next;
    }
    return i == k;
}

int main(){
    scanf("%d %d %d", &h, &n, &k);
    for (int i = 0; i < n; i++){
        int a,k,ne;
        scanf("%d %d %d", &a, &k, &ne);
        l[a].key = k;
        l[a].next = ne;
    }
    l[100000].next = h;
    int th = 100000;
    while (l[th].next != -1){
        if (!reversable(th))
            break;
        int p = l[th].next;
        int q = l[p].next;
        for (int i = 0; i < k - 1; i++){
            int r = l[q].next;
            l[q].next = p;
            p = q;
            q = r;
        }
        int t = l[th].next;
        l[t].next = q;
        l[th].next = p;
        th = t;
    }
    int p = l[100000].next;
    while (p != -1){
        if (l[p].next == -1)
            printf("%05d %d %d\n", p, l[p].key, -1);
        else
            printf("%05d %d %05d\n", p, l[p].key, l[p].next);
        p = l[p].next;
    }
    return 0;
}
