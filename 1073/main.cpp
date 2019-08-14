#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sci;
    cin >> sci;
    if (sci[0] == '-')
        printf("-");
    int dv = sci.find_first_of("E");
    string a = sci.substr(1 , dv - 1);
    string b = sci.substr(dv + 1);
    int ex = stoi(b);
    int i = 0, len = a.length();
    if (ex > 0){
        while (a[i] != '.')
            printf("%c", a[i++]);
        i++;
        while ((ex--) != 0){
            printf("%c", a[i++]);
            if (i == a.size())
                a.push_back('0');
        }
        if (a.size() == len){
           printf(".");
            while (i < a.size()){
                printf("%c", a[i++]);
            }
        }

    }
    else if (ex < 0){
        bool flag = true;
        while (ex++ != 0){
            printf("0");
            if (flag){
                printf(".");
                flag = false;
            }
        }

        for (int i = 0; i < a.size(); i++){
            if (a[i] != '.')
                printf("%c", a[i]);
        }
    }
    else {
        printf("%s", a.c_str());
    }
    return 0;
}
