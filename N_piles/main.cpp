#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        q.push(t);
    }
    int ans = 0;
    while (q.size() != 1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += (a + b);
        q.push(a+b);
    }
    printf("%d", ans);
    return 0;
}
