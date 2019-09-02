#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

long long convert(string s, long long r){
    long long sum = 0;
    for (int i = 0; i < s.size(); i++){
        int t = isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
        sum = sum * r + t;
    }
    return sum;
}

long long findR(string s, long long num){
    char maxc = *max_element(s.begin(), s.end());
    long long lo = (isdigit(maxc) ?  maxc - '0' : maxc - 'A' + 10) + 1;
    long long hi = max(lo, num);
    while (lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        long long t = convert(s, mid);
        if (t > num || t < 0){
            hi = mid - 1;
        }
        else if (t == num)
            return mid;
        else
            lo = mid + 1;
    }
    return -1;
}

int main(){
    string n1, n2;
    long long tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    long long res;
    if (tag == 1)
        res = findR(n2, convert(n1, radix));
    else
        res = findR(n1, convert(n2, radix));
    if (res == -1)
        printf("Impossible\n");
    else
        printf("%lld\n", res);
    return 0;
}
