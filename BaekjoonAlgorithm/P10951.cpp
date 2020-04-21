// Baekjoon 10951
// 문제
// A+B - 4

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a,b;

    while(1){
        cin >> a >> b;
        if(cin.eof()){
            break;
        }

        cout << a + b << endl;
    }
}