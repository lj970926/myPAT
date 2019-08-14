#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
map<string, set<string> > tlt, ath, key, pub, year;
set<string> ans;
int main()
{
    int n, m;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++){
        string id, title, author, kwd, pri,y;
        getline(cin, id);
        getline(cin, title);
        tlt[title].insert(id);
        getline(cin, author);
        ath[author].insert(id);
        do {
            cin >> kwd;
            key[kwd].insert(id);
        }while(getchar() != '\n');
        getline(cin, pri);
        pub[pri].insert(id);
        getline(cin, y);
        year[y].insert(id);
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        int qn;
        string cont;
        cin >> qn;
        getline(cin, cont);
        cont = cont.substr(2);
        switch(qn){
            case 1: ans = tlt[cont]; break;
            case 2: ans = ath[cont]; break;
            case 3: ans = key[cont]; break;
            case 4: ans = pub[cont]; break;
            case 5: ans = year[cont]; break;
        }
        printf("%d: %s\n",qn,cont.c_str());
        if (ans.size() == 0)
            printf("Not Found\n");
        else{
            for (auto itr = ans.begin(); itr != ans.end(); itr++){
                printf("%s\n", (*itr).c_str());
            }
        }
    }
    return 0;
}
