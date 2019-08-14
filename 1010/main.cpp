#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int num(char c){
    if (isdigit(c))
        return c - '0';
    return c - 'a' + 10;
}

long long contd(string n, int rad){
    long long ans = 0;
    for (int i = 0; i < n.size(); i++){
        ans = ans * rad + num(n[i]);
    }
    return ans;
}

long long findr(string n, long long a){
    long long lo = 2, hi = 36;
    for (int i = 0; i < n.size(); i++){
        if (lo - 1 < num(n[i]))
            lo = num(n[i])+ 1;
    }
    long long ans = -1;
    while (lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        long long  tr = contd(n, mid);
        if (tr == a){
            ans = mid;
        }\
        if (tr < a)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return ans;
}

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int tag, r;
    scanf("%d %d", &tag, &r);
    long long res;
    if (tag == 1){
        long long a1 = contd(n1, r);
        res =findr(n2, a1);
    }
    else{
        long long a2 = contd(n2, r);
        res = findr(n1, a2);
    }
    if (res == -1)
        printf("Impossible");
    else
        printf("%lld", res);
    return 0;
}
