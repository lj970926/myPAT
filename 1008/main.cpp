#include <iostream>

using namespace std;

int main(){
    int n, floor = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        if (t > floor){
            sum += (t - floor) * 6 + 5;
        }
        else{
            sum += (floor - t) * 4 + 5;
        }
        floor = t;
    }
    printf("%d\n", sum);
    return 0;
}
