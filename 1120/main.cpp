#include <iostream>
#include <set>
using namespace std;
bool h[50] = {false};
set<int> fre;
int getsum(int x){
    int sum = 0;
    while(x != 0){
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        int s = getsum(x);
        if (!h[s]){
            fre.insert(s);
            h[s] = true;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (auto it = fre.begin(); it != fre.end(); it++){
        if (it != fre.begin())
            printf(" ");
        printf("%d", *it);
    }
    printf("\n");
    return 0;
}
