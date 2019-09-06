#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
unordered_set<string> aid;

bool cmp(string a, string b){
    if (a.size() == 0)
        return true;
    return a.substr(6, 8) > b.substr(6, 8) ;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        aid.insert(s);
    }
    string oldgu, oldal;
    int m, cnt = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        if (cmp(oldgu, s)){
            oldgu = s;
        }
        if (aid.find(s) != aid.end()){
            cnt++;
            if (cmp(oldal, s))
                oldal = s;
        }
    }
    printf("%d\n", cnt);
    printf("%s\n", (cnt == 0 ? oldgu : oldal).c_str());
    return 0;
}
