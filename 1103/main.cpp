#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> ans, tans;
int n, k, p, msum = -1;
bool flag = true;
bool cmp(int a, int b){
    return a > b;
}

int powe(int x, int p){
    int ans = 1;
    for (int i = 0; i < p; i++) ans *= x;
    return ans;
}

void dfs(int s, int tsum, int pt){
    if (tans.size() == k){
        if (s == n && tsum >= msum){
            ans  = tans;
            msum = tsum;
        }
        return;
    }
    int i = (pt == 0? 1 : tans[pt - 1]);
    for (; s + powe(i,p) <= n; i++){
        tans.push_back(i);
        dfs(s + powe(i, p), tsum + i, pt + 1);
        tans.pop_back();
    }
}

int main()
{

    scanf("%d %d %d", &n, &k, &p);
    dfs(0,0,0);
    if (ans.size() == 0)
        printf("Impossible");
    else{
        sort(ans.begin(),ans.end(), cmp);
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++){
            if (i != 0)
                printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }

    return 0;
}
