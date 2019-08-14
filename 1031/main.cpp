#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int n2,n1;
    for (n2 = 3;n2 <= n-2;n2++)
        if ((n+2-n2)%2 == 0 && (n+2-n2)/2 <= n2)
            break;
    n1 = (n+2-n2)/2;
    string space;
    for (int i = 0;i < n2-2;i++) space.append(" ");
    int l = n-1;
    int i = 0;
    while (l > n2-1){
        cout << s[i] << space << s[i+l] << endl;
        i++;
        l-=2;
    }
    for (int j = i;j <= i+l;j++){
        cout << s[j];
    }
    return 0;
}
