// Baekjoon 2741
// 문제
// N 찍기

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i=1;i<=n;i++){
        cout << i << '\n';
    }
}