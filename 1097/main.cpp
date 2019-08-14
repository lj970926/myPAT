#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct Node{
    int key, next;
};
Node li[100005];
set<int> dup;
int main()
{
    int n, lhead, rhead = -1;
    scanf("%d %d", &lhead, &n);
    for (int i =0; i < n; i++){
        int a,k,ne;
        scanf("%d %d %d", &a, &k, &ne);
        li[a].key = k;
        li[a].next = ne;
    }
    int p = lhead, q, r = -1;
    while(p != -1){
        int k = li[p].key;
        if (dup.find(abs(k)) != dup.end()){
            li[q].next = li[p].next;
            li[p].next = -1;
            if (r == -1){
                rhead = p;
            }else
                li[r].next = p;
            r = p;
            p = li[q].next;
        }
        else{
            dup.insert(abs(k));
            q = p;
            p = li[p].next;
        }
    }
    for (int i = lhead; i != -1; i = li[i].next){
        if (li[i].next != -1)
            printf("%05d %d %05d\n", i, li[i].key, li[i].next);
        else
            printf("%05d %d %d\n", i, li[i].key, li[i].next);
    }
    for (int i = rhead; i != -1; i = li[i].next){
        if (li[i].next != -1)
            printf("%05d %d %05d\n", i, li[i].key, li[i].next);
        else
            printf("%05d %d %d\n", i, li[i].key, li[i].next);
    }
    return 0;
}
