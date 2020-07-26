// Baekjoon 15552
// 문제
// 빠른 A+B

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    int a,b;

    cin >> num;

    for(int i=0;i<num;i++){
        cin >> a >> b;
        cout << a+b << "\n";
    }
}