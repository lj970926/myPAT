#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Person{
    string name;
    int age, worth;
    Person(string s, int a, int w):name(s), age(a), worth(w){};
};
vector<Person> bill;

bool cmp(Person &a, Person &b){
    return (a.worth > b.worth || (a.worth == b.worth && a.age < b.age) || (a.worth == b.worth && a.age == b.age && a.name < b.name));
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        string n;
        int a, w;
        cin >> n >> a >> w;
        bill.push_back(Person(n, a, w));
    }
    sort(bill.begin(), bill.end(),cmp);
    for (int i = 0; i < m; i++){
        int low, high, num;
        scanf("%d %d %d", &num, &low, &high);
        int tnum = num;
        printf("Case #%d:\n", i+1);
        for (int j = 0; j < bill.size(); j++){
            if (bill[j].age >= low && bill[j].age <= high) {
                printf("%s %d %d\n", bill[j].name.c_str(), bill[j].age, bill[j].worth);
                if (--tnum <= 0)
                    break;
            }
        }
        if (tnum == num)
            printf("None\n");
    }
    return 0;
}
