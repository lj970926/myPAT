#include <iostream>
#include <cctype>
#include <map>
#include <string>
using namespace std;
map<string,int> dict;
int main()
{
    string temp;
    char c;
    while (1){
        c = getchar();
        if (isalnum(c))
            temp.push_back(tolower(c));
        else if (temp.length() != 0){
            if (dict.find(temp) == dict.end())
                dict[temp] = 1;
            else
                dict[temp]++;
            temp.clear();
        }
        if (c == '\n')
            break;
    }
    int maxn = 0;
    string maxw;
    for (auto itr = dict.begin(); itr != dict.end(); itr++){
        if (itr->second > maxn){
            maxn = itr->second;
            maxw = itr->first;
        }
        else if (itr->second == maxn && itr->first < maxw)
            maxw = itr->first;
    }
    printf("%s %d", maxw.c_str(), maxn);
    return 0;
}
