#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int dp[1010][1010];

int main()
{
    string s;
    getline(cin,s);
    int len = s.length(),ans = 1;
    for (int i = 0;i < len;i++){
        dp[i][i] = 1;
        if (i < len-1&& s[i] == s[i+1]){
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
        for (int l = 3;l <= len;l++){
            for (int i = 0; i + l -1 <len;i++){
                if (dp[i+1][i+l-2] == 1 && s[i] ==s[i+l-1]){
                    dp[i][i+l-1] = 1;
                    ans = l;
                }
            }
        }
    printf("%d",ans);


    return 0;
}
