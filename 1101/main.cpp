#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[100005];
int maxn[100005];
int minn[100005];
vector<int> result;
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++){
        scanf("%d",&num[i]);
    }
    maxn[0] = num[0];
    for (int i = 1;i < n;i++){
        maxn[i] = max(maxn[i-1],num[i]);
    }
    minn[n-1] = num[n-1];
    for (int i = n-2;i >= 0;i--){
        minn[i] = min(minn[i+1],num[i]);
    }
    for (int i = 0;i < n;i++){
        if (minn[i] == maxn[i]){
            result.push_back(minn[i]);
        }
    }
    sort(result.begin(),result.end());
    printf("%d\n",result.size());
    bool first = true;
    for (int i = 0; i < result.size();i++){
        first? first =false:printf(" ");
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;

}
