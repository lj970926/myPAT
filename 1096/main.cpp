#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
int main()
{
    int n;
    cin >> n;
    int i = 2;
    while(i <= n / 2){
        while(n % i != 0) i++;
        int tn = n, cnt = 0;
        int j = i;
        while (n % j == 0){
            cnt++;
            n /= j;
            j++;
        }
        if (j - i > ans.size()){
            ans.clear();
            for (int m = i; m < j; m++)
                ans.push_back(m);
        }
        n = tn;
        i = j;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i <ans.size(); i++){
        if (i != 0)
            printf("*");
        printf("%d", ans[i]);
    }
    return 0;
}
