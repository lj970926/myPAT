#include <iostream>
#include <string>
using namespace std;
int main(){
    int a;
    string b;
    cin >> a;
    getline(cin, b);
    cout << a << endl << b << endl;
    cout << b.substr(2);
    return 0;
}
