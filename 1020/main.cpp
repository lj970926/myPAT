#include <iostream>
#include <vector>
using namespace std;
const int maxn = 35;
int inorder[maxn];
int postorder[maxn];

vector<vector<int> > lorder(maxn);
void level_order(int p,int r,int level,int n);
int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> postorder[i];
    for (int i = 0;i < n;i++)
        cin >> inorder[i];
    level_order(0,n,0,n);
    bool first = true;
    for (int i = 0;i < lorder.size();i++)
        for (int j = 0;j<lorder[i].size();j++){
            if (first)
                first = false;
            else
                cout << ' ';
            cout << lorder[i][j];
        }
    return 0;
}
void level_order(int p,int r,int level,int n){
    if (p == r)
        return;
    int root;
    for (int i = 0;i < n;i++){
        for (int j = p;j < r;j++){
            if (postorder[i] == inorder[j])
                    root = i;
        }
    }
    int i;
    for(i = p;inorder[i]!=postorder[root];i++);
    lorder[level].push_back(inorder[i]);
    level_order(p,i,level+1,n);
    level_order(i+1,r,level+1,n);
}
