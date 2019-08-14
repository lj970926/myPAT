#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10005][105];
int n,m;
vector<int> v;
vector<int> path;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    for (int j = 0;j <= m;j++) dp[0][j] = 0;
    for (int i = 0;i <= n;i++) dp[i][0] = 1;
    for (int i = 1;i <= n;i++)
    for (int c = 1; c <= m;c++){
        if (dp[i-1][c] == 1 || ((c-v[i-1] >=0)&& (dp[i-1][c-v[i-1]] == 1)))
            dp[i][c] = 1;
    }
    if (dp[n][m] == 0)
        cout << "No Solution";
    else{
        for (int i = n,j = m;i >= 1&& j >= 0;){
            if (dp[i-1][j-v[i-1]]==1){
                path.push_back(v[i-1]);
                j-= v[i-1];
                i--;
            }
            else if (dp[i-1][j] == 1)
                i--;
        }
        for (int i = 0;i < path.size();i++){
             if (i > 0) cout << ' ';
            cout << path[i];
        }

    }
    return 0;
}
