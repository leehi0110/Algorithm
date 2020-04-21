// Baekjoon 1330
// 문제
// 두수 비교하기

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a,b;

    cin >> a >> b;

    if(a>b){
        cout << '>' << endl;
    }
    else if (a < b){
        cout << '<' << endl;
    }
    else {
        cout << "==" << endl;
    }
    
}