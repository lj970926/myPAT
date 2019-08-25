#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<double, vector<double>, greater<double> > q;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        q.push(t);
    }
    while (q.size() != 1){
        double a = q.top(); q.pop();
        double b = q.top(); q.pop();
        q.push((a + b) / 2);
    }
    int ans = q.top();
    printf("%d\n", ans);
    return 0;
}
