#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<int> num;
int main()
{
    int n, ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        num.insert(t);
        while (num.find(ans) != num.end()) ans++;
    }
    printf("%d",ans);
    return 0;
}
