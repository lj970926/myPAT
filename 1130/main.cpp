#include <iostream>
#include <string>
using namespace std;
struct Node{
    string data;
    int left, right;
};
Node tree[25];
bool h[25] = {false};

string getex(int r){
    if (r == -1)
        return "";
    if (tree[r].left == -1 && tree[r].right == -1)
        return tree[r].data;
    string e1 = getex(tree[r].left), e2 = getex(tree[r].right);
    return "(" + e1 + tree[r].data + e2 + ")";
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cin >> tree[i].data >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1)
            h[tree[i].left] = true;
        if (tree[i].right != -1)
            h[tree[i].right] = true;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (!h[i]){
            root = i;
            break;
        }
    string ans =getex(root);
    if (ans[0] == '(')
        ans = ans.substr(1, ans.length() - 2);
    printf("%s", ans.c_str());
    return 0;
}
