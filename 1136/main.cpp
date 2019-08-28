#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispal(vector<int>& num){
    int k = num.size() - 1;
    for (int i = 0; i <= k / 2; i++){
        if (num[i] != num[k - i])
            return false;
    }
    return true;
}

vector<int> add(vector<int> a, vector<int> b){
    vector<int> ans;
    int c = 0;
    for (int i = 0; i < a.size(); i++){
        ans.push_back((a[i] + b[i] + c) % 10);
        c = (a[i] + b[i] + c) / 10;
    }
    if (c != 0)
        ans.push_back(c);
    return ans;
}

void show(vector<int>& a){
    for (int i = a.size() - 1; i >= 0; i--)
        printf("%d", a[i]);
}

int main()
{
    string s;
    cin >> s;
    vector<int> num(s.size());
    for (int i = 0; i < s.size(); i++){
        num[i] = s[s.size() - 1 - i] - '0';
    }
    int i = 0;
    while (!ispal(num) && i < 10){
        vector<int> rnum = num;
        reverse(num.begin(), num.end());
        show(rnum);
        printf(" + ");
        show(num);
        num = add(num, rnum);
        printf(" = ");
        show(num);
        printf("\n");
        i++;
    }
    if (ispal(num)){
        show(num);
        printf(" is a palindromic number.\n");
    }
    else{
        printf("Not found in 10 iterations.\n");
    }

    return 0;
}
