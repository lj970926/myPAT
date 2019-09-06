#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1005;
struct Node{
    int left = -1, right = -1;
};
vector<int> post, in;
Node tree[maxn];
int parent[maxn];
int level[maxn];
int n;
bool flag = true;
void create(int i, int j, int p, int q, int l){
    if (i == j){
        return;
    }
    int deg = 0;
    int mid, r = post[q];
    for (mid = i; in[mid] != post[q]; mid++) ;
    if (mid != i){
        int left = post[p + mid - i - 1];
        tree[r].left = left;
        level[left] = l + 1;
        parent[left] = r;
        create(i, mid - 1, p, p + mid - i - 1, l + 1);
        deg++;
    }
    if (mid != j){
        int right = post[q - 1];
        tree[r].right = right;
        level[right] = l + 1;
        parent[right] = r;
        create(mid + 1, j, p + mid - i, q - 1, l + 1);
        deg++;
    }
    if (deg == 1)
        flag = false;
}

int main()
{
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    create(0, n - 1, 0, n - 1, 0);
    int m;
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++){
        int a;
        scanf("%d", &a);
        string s1;
        cin >> s1;
        if (s1 == "and"){
            int b;
            scanf("%d", &b);
            string s2;
            getline(cin, s2);
            if (s2[s2.size() - 1] == 's'){
                printf(parent[a] == parent[b] ? "Yes\n":"No\n");
            }
            else{
                printf(level[a] == level[b] ? "Yes\n":"No\n");
            }
        }
        else{
            string s2;
            getline(cin, s2);
            if (s2[s2.size() - 1] == 't'){
                printf(post[n - 1] == a ? "Yes\n":"No\n");
            }
            else if (s2[s2.size() - 1] == 'e'){
                printf(flag ? "Yes\n":"No\n");
            }
            else{
                int p = s2.find_last_of(" ");
                int b = stoi(s2.substr(p + 1));
                if (s2[5] == 'p'){
                    printf(parent[b] == a ? "Yes\n":"No\n");
                }
                else if (s2[5] == 'l'){
                    printf(tree[b].left == a ? "Yes\n":"No\n");
                }
                else
                    printf(tree[b].right == a ? "Yes\n":"No\n");
            }
        }
    }
    return 0;
}
