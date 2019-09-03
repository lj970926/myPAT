#include <iostream>
#include <string>
using namespace std;
const int inf = 0x3fffffff;

int convert(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int main(){
    int m;
    scanf("%d", &m);
    string uid, lid;
    int minin = inf, maxout = -1;
    for (int i = 0; i < m; i++){
        string id;
        int hh, mm, ss;
        cin >> id;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        if (convert(hh, mm, ss) < minin){
            minin = convert(hh, mm, ss);
            uid = id;
        }
        scanf("%d:%d:%d", &hh, &mm, &ss);
        if (convert(hh, mm, ss) > maxout){
            maxout = convert(hh, mm, ss);
            lid = id;
        }
    }
    printf("%s %s\n", uid.c_str(), lid.c_str());
}
