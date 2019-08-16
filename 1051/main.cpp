#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int j = 0; j < k; j++){
        stack<int> s;
        vector<int> seq(n);
        for (int i = 0; i < n; i++){
            scanf("%d", &seq[i]);
        }
        int p = 0;
        for (int i = 1; i <= n; i++){
            s.push(i);
            if (s.size() > m){
                break;
            }
            while(!s.empty() && s.top() == seq[p]){
                s.pop();
                p++;
            }
        }
        if (p == n)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
