// Baekjoon 1712
// 문제
// 손익분기점

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    long int a,b,c;
    int cnt=0;

    cin >> a >> b >> c;

    if(b >= c) cout << -1 << endl;
    else {
        cnt = (a/(c-b))+1;
        cout << cnt << endl;
    }
}