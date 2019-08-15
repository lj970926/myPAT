#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> num;
int main()
{
    int n;
    scanf("%d", &n);
    num.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    sort(num.begin(), num.end());
    int n1 = n / 2 + n % 2, n2 = n - n1;
    int s2 = 0;
    for (int i = 0; i < n2; i++)
        s2 += num[i];
    int s1 = 0;
    for (int i = n2; i < n; i++)
        s1 += num[i];
    printf("%d %d", n1 - n2, s1 - s2);
    return 0;
}
