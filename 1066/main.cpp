#include <iostream>

using namespace std;

struct Node {
    int height,v;
    Node *left, *right;
};

int n;
Node *root = nullptr;

int geth(Node *t){
    if (t == nullptr)
        return 0;
    return t->height;
}

void updateh(Node *t){
    t->height = max(geth(t -> left),geth(t->right)) + 1;
}

int getF(Node *t){
    return (geth(t->left) - geth(t->right));
}

void R(Node* &t){
    Node *tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    updateh(t);
    updateh(tmp);
    t = tmp;
}

void L(Node* &t){
    Node *tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    updateh(t);
    updateh(tmp);
    t = tmp;
}

void insert(int v, Node* &root){
    if (root == nullptr){
        root = (Node *)malloc(sizeof(Node));
        root->height = 1;
        root->v = v;
        root->right = root->left = nullptr;
        return;
    }
    else if (root-> v > v){
        insert(v,root->left);
        updateh(root);
        if (getF(root) == 2){
            if (getF(root -> left)== 1)
                R(root);
            else{
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(v,root->right);
        updateh(root);
        if (getF(root) == -2){
            if (getF(root->right) == -1)
                L(root);
            else{
                R(root->right);
                L(root);
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        insert(temp,root);
    }
    printf("%d",root->v);
    return 0;
}
