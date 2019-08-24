#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post, in;
bool flag = true;
int n;
void create(int left, int right){
    if (left == right){
        in.push_back(pre[left]);
        return;
    }
    if (left > right)
        return;
    int i, j;
    for (i = 0; i < n && post[i] != pre[left]; i++) ;
    for (j = 0; j < n && post[j] != pre[left + 1]; j++);
    int lenr = i - j - 1;
    if (lenr == 0)
        flag = false;
    create(left + 1, right - lenr);
    in.push_back(pre[left]);
    create(right - lenr + 1, right);
}

int main()
{

    scanf("%d", &n);
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    create(0, n - 1);
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = 0; i < n; i++){
        if (i != 0)
            printf(" ");
        printf("%d", in[i]);
    }
    printf("\n");
    return 0;
}
