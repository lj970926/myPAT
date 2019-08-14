#include <iostream>
#include <queue>
using namespace std;
queue<int> ltravel;
int n;
int inorder[maxn];
int postorder[maxn];
int main()
{
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> postorder[i];
    for (int i = 0;i < n;i++)
        cin >> inorder[i];
    level_order();

    return 0;
}
void level_order(){
    int p = 0,r = n;
}
