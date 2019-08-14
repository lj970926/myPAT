#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> order(60);
    vector<int> card(60);
    for (int i = 1;i <=54;i++)
        card[i] = i;
    for (int i = 1;i <= 54;i++)
        scanf("%d",&order[i]);
    for (int i = 0;i < n;i++){
        vector<int> temp(60);
        for (int j = 1;j <= 54;j++){
            temp[order[j]] = card[j];
        }
        card = temp;
    }
    char c[5] = {'S','H','C','D','J'};
    bool first = true;
    for (int i = 1;i <= 54;i++){
        first? first = false:printf(" ");
        cout << c[(card[i]-1)/13] << (card[i]-1)%13 + 1;
    }
    return 0;
}
