#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> seg;

bool cmp(string a, string b){
    string s1 = a + b, s2 = b + a;
    return s1 < s2;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (stoi(s) != 0)
            seg.push_back(s);
    }
    if (seg.size() == 0){
        printf("%d", 0);
        return 0;
    }
    sort(seg.begin(),  seg.end(), cmp);
    seg[0] = seg[0].substr(seg[0].find_first_not_of("0"));
    for (int i = 0; i < seg.size(); i++){
        printf("%s", seg[i].c_str());
    }
    printf("\n");
    return 0;
}
