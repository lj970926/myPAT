#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n,k;
    cin >> n>>k;
    map<string,set<int> > students;
    for (int i = 0;i < k;i++){
        int index,num;
        cin >> index >> num;
        for (int j = 0;j < num;j++){
            string stu;
            cin >> stu;
            students[stu].insert(index);
        }
    }
    for (int i = 0;i < n;i++){
        string name;
        cin >> name;
        cout << name << ' ' << students[name].size();
        for (auto itr = students[name].begin();itr != students[name].end();itr++)
            cout << ' ' << *itr;
        cout << endl;
    }
    return 0;
}
