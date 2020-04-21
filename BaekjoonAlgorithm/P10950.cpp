// Baekjoon 10950
// 문제
// A+B-3

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count;
    int a,b;

    cin >> count;

    for(int i=0;i<count;i++){
        cin >> a >> b;
        cout << a+b << endl;
    }
}