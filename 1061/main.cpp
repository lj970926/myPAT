#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
map<char, string> day = {{'A', "MON"}, {'B', "TUE"}, {'C', "WED"},{'D', "THU"},
                        {'E', "FRI"}, {'F', "SAT"}, {'G', "SUN"}};
int main()
{
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    int ne;
    for (int i = 0; i < a.size() && i < b.size(); i++){
        if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G'){
            printf(day[a[i]].c_str());
            ne = i + 1;
            break;
        }
    }
    for (int i = ne; i < a.size() && i < b.size(); i++){
        if (a[i] == b[i]){
            if (isdigit(a[i])){
                printf(" %02d:", a[i] - '0');
                break;
            }
            else if (a[i] >= 'A' && a[i] <= 'N'){
                printf(" %02d:", a[i] - 'A' + 10);
                break;
            }
        }
    }
    for (int i = 0; i < c.size() && i < d.size(); i++){
        if (c[i] == d[i] && isalpha(c[i])){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
