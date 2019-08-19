#include <iostream>

using namespace std;
int s[200005];
const int inf = 0x3fffffff;
int main(){
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++){
        scanf("%d", &s[i]);
    }
    s[n1] = inf;
    scanf("%d", &n2);
    int tmp, p1 = 0, p2 = 0, ans;
    scanf("%d", &tmp);
    for (int i = 0; i < (n1 + n2 + 1) / 2; i++){
        if (tmp < s[p1]){
            ans = tmp;
            p2++;
            if (p2 < n2)
                scanf("%d", &tmp);
            else
                tmp = inf;
        }
        else{
            ans = s[p1];
            p1++;
        }
    }
    printf("%d", ans);
}
