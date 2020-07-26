// Baekjoon 11022
// 문제
// A + B - 8

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,a,b;

    cin >> n;

    for(int i= 1;i<=n;i++){
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << '\n';
    }
}