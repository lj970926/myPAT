#include <iostream>
#include <vector>
using namespace std;

int a[10000+10];

int main()
{
    int n;
    cin >> n;
    vector<int> lotterys;
    for (int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        lotterys.push_back(temp);
        a[temp]++;
    }
    for (int i = 0; i < lotterys.size();i++){
        if (a[lotterys[i]] == 1){
            cout << lotterys[i];
            return 0;
        }

    }
    cout << "None";
    return 0;
}
