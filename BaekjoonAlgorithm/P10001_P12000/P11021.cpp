// Baekjoon 11021
// 문제
// A + B -7

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);

    int n;
    int a,b;

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> a >> b;
        cout << "Case #" << i << ": " << a+b << '\n'; 
    }
}