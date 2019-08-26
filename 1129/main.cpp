#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h, ans;
int n, k;

bool cmp(int a, int b){
    return h[a] == h[b] ? a < b : h[a] > h[b];
}

int main()
{
    scanf("%d %d", &n, &k);
    h.resize(n + 1);
    for (int i = 0; i < n; i++){
        int q;
        scanf("%d", &q);
        if (i != 0){
            printf("%d:", q);
            for (int j = 0; j < ans.size(); j++)
                printf(" %d", ans[j]);
            printf("\n");
        }
        h[q]++;
        int j;
        for (j = 0; j < ans.size() && ans[j] != q; j++) ;
        if (j == ans.size())
            ans.push_back(q);
        sort(ans.begin(), ans.end(), cmp);
        if (ans.size() > k)
            ans.pop_back();
    }
    return 0;
}
