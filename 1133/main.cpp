#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100000;
struct Node{
    int key, next;
};
Node link[maxn];
vector<Node> cl[3];
int main()
{
    int n, h, k;
    scanf("%d %d %d", &h, &n, &k);
    for (int i = 0; i < n; i++){
        int a, ke, ne;
        scanf("%d %d %d", &a, &ke, &ne);
        link[a].key = ke;
        link[a].next = ne;
    }
    for (int p = h; p != -1; p = link[p].next){
        Node tmp;
        tmp.key = link[p].key;
        tmp.next = p;
        if (link[p].key < 0)
            cl[0].push_back(tmp);
        else if (link[p].key > k)
            cl[2].push_back(tmp);
        else
            cl[1].push_back(tmp);
    }
    bool flag = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < cl[i].size(); j++){
            if (flag){
                printf("%05d %d ", cl[i][j].next, cl[i][j].key);
                flag = false;
            }
            else
                printf("%05d\n%05d %d ", cl[i][j].next, cl[i][j].next, cl[i][j].key);
        }
    }
    printf("-1\n");
    return 0;
}
