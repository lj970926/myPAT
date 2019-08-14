#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool islegal(string s){
    if (s[0] == '-'){
        s = s.substr(1);
    }
    int pnt = s.size();
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '.'){
            if (pnt == s.size()){
                pnt = i;
            }
            else
                return false;
        }
        else if (!isdigit(s[i]))
            return false;
    }
    if ((int)s.size() - pnt - 1 > 2) return false;
    return true;

}

int main()
{
    int n,rn = 0;
    scanf("%d", &n);
    double sum = 0.0;
    for (int i = 0; i < n; i++){
        string t;
        cin >> t;
        if (islegal(t) && stod(t)>= -1000 & stod(t) <= 1000){
            sum += stod(t);
            rn++;
        }
        else{
            printf("ERROR: %s is not a legal number\n", t.c_str());
        }
    }
    if (rn == 0)
        printf("The average of 0 numbers is Undefined");
    else{
        sum /= rn;
        if (rn == 1)
            printf("The average of 1 number is %.2f", sum);
        else
            printf("The average of %d numbers is %.2f", rn, sum);
    }
    return 0;
}
