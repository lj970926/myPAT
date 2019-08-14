#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b){
    int i = 0;
    while (i < a.size()&&i < b.size()&&a[i] == b[i]) i++;
    if (i < a.size() && i < b.size()) return a[i] < b[i];
    if (i < a.size()){
        int p = 0;
        while (a[i] == a[p]&&i < a.size()){
            i++;p++;
        }
        return a[i] < a[p];
    }
    if (i < b.size()){
        int p = 0;
        while (b[i] == b[p]&&i < b.size()){
            i++;p++;
        }
        return b[i] > b[p];
    }
    return a[i] < b[i];

}

int main()
{
    int n;
    scanf("%d" ,&n);
    vector<string> seg;
    for (int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        bool result = false;
        for (int i = 0;i < temp.size();i++)
            if (temp[i] != '0'){
                result = true;
                break;
            }
        if (result)
            seg.push_back(temp);
    }
    if (seg.size() == 0){
        cout << 0;
        return 0;
    }
    sort(seg.begin(),seg.end(),cmp);
    int pos = seg[0].find_first_not_of("0");
    if (pos < seg[0].size())
        seg[0] = seg[0].substr(pos);
    else
        seg[0] = "";
    for (int i = 0; i < seg.size();i++)
        cout << seg[i];
    return 0;
}
