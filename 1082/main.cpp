#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<string> part;
string suf[4] = {"", "Shi", "Bai", "Qian"};
string wid[3] = {"", "Wan", "Yi"};
map<char, string> snum = {{'0', "ling"}, {'1', "yi"}, {'2',"er"}, {'3', "san"},
                            {'4', "si"}, {'5', "wu"}, {'6', "liu"}, {'7', "qi"},
                            {'8', "ba"}, {'9', "jiu"}};
int main()
{
    string num;
    cin >> num;
    if (num == "0"){
        printf("ling");
        return 0;
    }

    if (num[0] == '-'){
        printf("Fu ");
        num = num.substr(1);
    }
    int high = num.size(), low;
    while (high != 0){
        if (high - 4 <= 0){
            low = 0;
        } else
            low = high - 4;
        string a = num.substr(low, high - low), tres;
        int p = a.find_first_not_of("0");
        if (p != 0)
            tres += " ling";
        int h = a.find_last_not_of("0");
        for (int i = p; i <= h; i++){
            tres += (" " + snum[a[i]]);
            if (a[i] != '0' && i != a.size() - 1)
                tres +=(" " + suf[a.size() - 1 - i]);
        }
        part.push_back(tres);
        high = low;
    }
    for (int i = part.size() - 1; i >= 0 ;i--){
        if (i == part.size() - 1)
            part[i] = part[i].substr(1);
        printf(part[i].c_str());
        if (i != 0)
            printf(" %s", wid[i].c_str());
    }
    return 0;
}
