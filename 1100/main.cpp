#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
string unit[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly",
                    "aug", "sep", "oct", "nov", "dec"};
string ten[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
                    "elo", "syy", "lok", "mer", "jou"};
string nts[169];
map<string, int> stn;
void init(){
    for (int i = 0; i < 13; i++){
        nts[i] = unit[i];
        stn[unit[i]] = i;
        nts[13 * i] = ten[i];
        stn[ten[i]] = i * 13;
    }
    for (int i = 1; i < 13; i++)
        for (int j = 1; j < 13; j++){
            int t = i * 13 + j;
            string s = ten[i] + " " + unit[j];
            nts[t] = s;
            stn[s] = t;
        }
}
int main(){
    init();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        if (isdigit(s[0])){
            int t = stoi(s);
            printf("%s\n", nts[t].c_str());
        }
        else{
            printf("%d\n", stn[s]);
        }
    }
    return 0;
}
