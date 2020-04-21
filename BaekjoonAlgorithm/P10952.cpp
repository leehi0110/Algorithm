// Baekjoon 
// 문제 10952
// A+B - 5

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a,b;

    cin >> a >> b;

    while(a != 0 || b != 0){
        cout << a+b << endl;
        cin >> a >> b;
    }
}