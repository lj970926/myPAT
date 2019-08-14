#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *p = new int[N];
    for (int i = 0;i < N;i++){
        cin >> p[i];
    }
    int curstorey = 0;
    int sum = 0;
    for (int i = 0;i < N;i++){
        if (curstorey < p[i]){
            sum += ((p[i]-curstorey)*6 + 5);
        }
        else{
            sum += ((curstorey-p[i])*4 + 5);
        }
        curstorey = p[i];
    }
    cout << sum;
    return 0;
}
