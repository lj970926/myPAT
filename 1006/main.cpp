#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct member{
    string id;
    int intime;
    int outtime;
    member(string i, int in, int out):id(i),intime(in),outtime(out){};
};
int main()
{
    vector<member> V;
    int N;
    cin >> N;
    string temp_id;
    int temp_h;
    int temp_m;
    int temp_s;
    int in;
    int out;
    for (int i = 0; i < N;i++){
        cin >> temp_id;
        cin >> temp_h;
        cin.get();
        cin >> temp_m;
        cin.get();
        cin >> temp_s;
        in = temp_h*3600 + temp_m*60 + temp_s;
        cin >> temp_h;
        cin.get();
        cin >> temp_m;
        cin.get();
        cin >> temp_s;
        out = temp_h*3600 + temp_m*60 + temp_s;
        V.push_back(member(temp_id,in,out));

    }
    int ear = 0;
    int latest = 0;
    for (int i = 1;i < V.size();i++){
        if (V[i].intime< V[ear].intime)
            ear = i;
        if (V[i].outtime > V[latest].outtime)
            latest = i;
    }
    cout << V[ear].id << ' ' << V[latest].id;
    return 0;
}
