#include <iostream>
#include <vector>
using namespace std;
vector<double> dig;
vector<double> ts;
int main()
{
    long long n;
    double ans = 0.0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        double t;
        scanf("%lf", &t);
        long long l = i + 1, r = n - i, times = l * r;
        ans+= (times * t);
    }
    printf("%.2f", ans);
    return 0;
}
