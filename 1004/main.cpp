#include <iostream>
#include <vector>

using namespace std;


int countLayer(int i,int* V);

int main()
{
    int N,M,K;
    int id,pid,l,max_l= 0;
    cin >> N;
    if (N<=0||N>=100)
        return 1;
    int *V = new int[N + 1];

    int *result = new int[N+1];
    for (int i = 0;i< N+1;i++){
        V[i] = result[i] = 0;
    }
    cin >> M;
    while (M > 0){
        cin >> id;
        cin >> K;
        while (K > 0){
            cin >> pid;
            V[pid] = id;
            K--;
        }
        M--;
    }
    for (int i = 1;i < N + 1; i++){
        int j;
        for (j = 1; j < N + 1; j++)
            if (V[j] == i)
                break;
        if (j == N+1){
            l=countLayer(i,V);
            if (l > max_l)
                max_l = l;
            result[l]++;
        }

    }
    cout << result[0];
    for (int i = 1;i<(max_l + 1);i++)
        cout << ' ' << result[i] ;
    return 0;
}
int countLayer(int i,int *V){
    int l = 0;
    while (i != 1){
        i = V[i];
        l++;
    }
    return l;
}

