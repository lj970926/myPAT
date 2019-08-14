#include <vector>
#include <cstdio>
using namespace std;

vector<int> pre,post;
bool ismirror = false;

void getpost(int root,int tail){
    int i,j;
    if (!ismirror){
        for (i = root+1;i <= tail&&pre[i] < pre[root];i++) ;
        for (j = tail;j>root&&pre[j] >=pre[root];j--) ;
    }
    else{
        for (i = root +1;i <=tail && pre[i]>= pre[root];i++) ;
        for (j = tail;j > root && pre[j] < pre[root];j--) ;
    }
    if (i - j != 1) return;
    getpost(root + 1,j);
    getpost(i,tail);
    post.push_back(pre[root]);
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    pre.resize(n);
    for (int i = 0;i < n;i++)
        scanf("%d",&pre[i]);
    getpost(0,n-1);
    if (post.size() != n){
        post.clear();
        ismirror = true;
        getpost(0,n-1);
    }
    if (post.size()==n){
        printf("YES\n");
        bool first = true;
        for (int i = 0;i < n;i++){
            first ? first = false:printf(" ");
            printf("%d",post[i]);
        }

    }
    else
        printf("NO");
    return 0;
}
