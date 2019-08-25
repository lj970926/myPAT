#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    int key, height;
    Node *left, *right;
    Node(int k, int h, Node *l, Node *r):key(k), height(h), left(l), right(r){};
};

struct nod{
    int key, index;
    nod(int k, int i):key(k), index(i){};
};

vector<nod> ans;
int maxind = 0;
int getHeight(Node *root){
    if (root == nullptr)
        return 0;
    return root->height;
}

void updHeight(Node *root){
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getFactor(Node *root){
    return getHeight(root->left) - getHeight(root->right);
}

void R(Node* &root){
    Node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updHeight(root);
    updHeight(tmp);
    root = tmp;
}

void L(Node* &root){
    Node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updHeight(root);
    updHeight(tmp);
    root = tmp;
}

void ins(int k, Node* &root){
    if (root == nullptr){
        root = new Node(k, 1, nullptr, nullptr);
        return;
    }
    if (k < root->key){
        ins(k, root->left);
        updHeight(root);
        if (getFactor(root) == 2){
            if (getFactor(root->left) == -1)
                L(root->left);
            R(root);
        }
    }
    else{
        ins(k, root->right);
        updHeight(root);
        if (getFactor(root) == -2){
            if (getFactor(root->right) == 1)
                R(root->right);
            L(root);
        }
    }
}

void DFS(Node* root, int index){
    if (root == nullptr){
        return;
    }
    if (index > maxind){
        maxind = index;
    }
    ans.push_back(nod(root->key, index));
    DFS(root->left, index * 2);
    DFS(root->right, index * 2 + 1);

}

bool cmp(nod a, nod b){
    return a.index < b.index;
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *root = nullptr;
    for (int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        ins(k, root);
    }
    DFS(root, 1);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++){
        if (i != 0)
            printf(" ");
        printf("%d", ans[i].key);
    }
    if (maxind > n)
        printf("\nNO\n");
    else
        printf("\nYES\n");
    return 0;
}
