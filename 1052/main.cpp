#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int p,k;
    Node(int p_, int k_):p(p_), k(k_){};
};

bool cmp(Node &a, Node &b){
    return a.k < b.k;
}
vector<Node> l;
int main()
{
    int n, head;
    scanf("%d %d", &n, &head);
    for (int i = 0; i < n; i++){
        int p, k, ne;
        scanf("%d %d %d", &p, &k, &ne);
        l.push_back(Node(p,k));
    }
    printf("%d ", n);
    sort(l.begin(), l.end(), cmp);
    for (int i = 0; i < l.size();i++){
        printf("%05d\n%05d", l[i].p, l[i].p);
        printf(" %d ", l[i].k);
    }
    printf("-1");
    return 0;
}
