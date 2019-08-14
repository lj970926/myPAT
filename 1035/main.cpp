#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<string> name,pwd;
    map<char, char> mod;
    mod['1'] = '@';mod['l'] = 'L';mod['0'] = '%';mod['O'] = 'o';
    for (int i = 0;i < n;i++){
        string tname,tpwd;
        cin >> tname >> tpwd;
        bool modified = false;
        for (int j = tpwd.find_first_of("l10O");j < tpwd.size();j = tpwd.find_first_of("l10O",j+1)){
            tpwd[j] = mod[tpwd[j]];
            modified = true;
        }
        if (modified){
            name.push_back(tname);
            pwd.push_back(tpwd);
        }
    }
    if (name.size()==0){
        if (n != 1)
            printf("There are %d accounts and no account is modified",n);
        else
            printf("There is 1 account and no account is modified");
        return 0;
    }
    cout << name.size() << endl;
    bool first = true;
    for (int i = 0;i < name.size();i++){
        first? first = false:printf("\n");
        cout << name[i] << ' ' << pwd[i];
    }

    return 0;
}
