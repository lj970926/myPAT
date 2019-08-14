#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Peo{
    string name;
    int hei;
    Peo(string n, int h):name(n), hei(h){};
};
vector<Peo> peo;
vector<vector<string> > row;
bool cmp(Peo a, Peo b){
    if (a.hei != b.hei)
        return a.hei > b.hei;
    return a.name < b.name;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        string n;
        int h;
        cin >> n >> h;
        peo.push_back(Peo(n,h));
    }
    sort(peo.begin(), peo.end(), cmp);
    int m = n / k, r = n - m * k;
    row.resize(k);
    row[0].resize(m + r);
    for (int i = 1; i < k; i++)
        row[i].resize(m);
    int p = 0;
    for (int i = 0; i < k; i++){
        int mid = row[i].size() / 2;
        row[i][mid] = peo[p++].name;
        int j = 1;
        while (mid - j >= 0 || mid + j < row[i].size()){
            if (mid - j >= 0) row[i][mid - j] = peo[p++].name;
            if (mid + j < row[i].size()) row[i][mid + j] = peo[p++].name;
            j++;
        }
    }
    for (int i = 0; i < k; i++){
        for (int j = 0; j < row[i].size(); j++){
            if (j != 0)
                printf(" ");
            printf("%s", row[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
