#include <iostream>

using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node(int k, Node* l, Node* r):key(k), left(l), right(r){};
};
int h[1010], maxl = -1;
void ins(Node *&r, int l, int x){
    if (r == nullptr){
        r = new Node(x, nullptr, nullptr);
        h[l]++;
        if (l > maxl)
            maxl = l;
        return;
    }
    if (x <= r -> key)
        ins(r -> left, l + 1, x);
    else
        ins(r -> right, l + 1, x);
}

int main()
{
    Node *root = nullptr;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        ins(root, 0, t);
    }
    printf("%d + %d = %d", h[maxl], h[maxl - 1], h[maxl] + h[maxl - 1]);
    return 0;
}
