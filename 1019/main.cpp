#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    long long n,b;
    cin >> n >> b;
    vector<long> a;
    long temp = n;
    while(temp != 0){
        a.push_back(temp%b);
        temp /= b;
    }
    bool ok = true;
    for(long i = 0;i<a.size()/2;i++){
        if (a[i] != a[a.size()-i-1]){
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes":"No") << endl;
    bool first = true;
    for (long i = a.size();i>0;){
        if (first)
            first = false;
        else
            cout << ' ';
        cout << a[--i];
    }
    return 0;
}
