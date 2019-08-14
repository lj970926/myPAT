#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string N;
    unsigned long long int sum = 0;
    int i = 0,j = 0;
    vector<int> result;
    char **numbers = new char*[10];
    numbers[0] = "zero";
    numbers[1] = "one";
    numbers[2] = "two";
    numbers[3] = "three";
    numbers[4] = "four";
    numbers[5] = "five";
    numbers[6] = "six";
    numbers[7] = "seven";
    numbers[8] = "eight";
    numbers[9] = "nine";
    cin >> N;

    while (N[j] != '\0'){
        i = N[j]-'0';
        sum += i;
        j++;
    }
    if (sum == 0){
        cout << numbers[0];
        return 0;
    }
    while(sum!= 0){
        i = sum % 10;
        result.push_back(i);
        sum /= 10;
    }
    cout << numbers[result[result.size()-1]];
    for (int i = result.size()-2;i > -1; i--){
        cout << ' ' << numbers[result[i]];
    }
    return 0;

}
