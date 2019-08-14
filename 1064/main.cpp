#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int key,level;
    Node(int k, int l):key(k),level(l){};
};
int n;
vector<int> key;
vector<Node> lorder;
void createBST(int l, int r, int lev){
    if (l > r)
        return;
    int num = r - l + 1;
    int cap = 1;
    while (cap - 1 < num) cap = cap << 1;
    int numleft = (cap/2) - (cap - 1 - num);
    numleft = min(numleft, cap >> 2);
    numleft += ((cap/2  - 2)/2);
    int mid = l + numleft;
    lorder.push_back(Node(key[mid],lev));
    createBST(l,mid - 1,lev+1);
    createBST(mid+1,r,lev+1);

}

bool cmp(Node &a, Node &b){
    return (a.level < b.level||(a.level == b.level && a.key < b.key));
}

int main()
{
    scanf("%d", &n);
    key.resize(n);
    for (int i = 0; i < n;i++)
        scanf("%d",&key[i]);
    sort(key.begin(),key.end());
    createBST(0,n-1,1);
    sort(lorder.begin(),lorder.end(),cmp);
    for (int i = 0; i < n;i++){
        if (i != 0)
            printf(" ");
        printf("%d",lorder[i].key);
    }
    return 0;
}
