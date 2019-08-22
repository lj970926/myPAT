#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ride;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        ride.push_back(t);
    }
    sort(ride.begin(), ride.end(), cmp);
    int ans = 0;
    for (int i = ride.size(); i > 0; i--){
        if (ride[i - 1] > i){
            ans = i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
