#include <iostream>
#include <algorithm>
using namespace std;
int coins[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        coins[temp]++;
    }
    for (int i = 1;i <= m/2;i++){
         if (coins[i]){
            coins[i]--;
            if (coins[m-i]){
                cout << i << ' ' << m-i;
                return 0;
            }
            coins[i]++;

         }
    }
    cout << "No Solution";
    return 0;
}
