// Baekjoon 8393
// 문제
// 합

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int sum = 0;

    cin >> n;

    for(int i = 1 ;i <=n ;i++){
        sum += i;
    }

    cout << sum << endl;
}