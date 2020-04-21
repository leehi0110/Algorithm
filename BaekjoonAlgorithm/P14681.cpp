// Baekjoon 14681
// 문제
// 사분면 고르기

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x, y;

    cin >> x;
    cin >> y;

    if(x < 0){
        if(y < 0){
            cout << '3' << endl;
        }
        else {
            cout << '2' << endl;
        }
    } // 2 or 3
    else {
        if (y < 0){
            cout << '4' << endl;
        }
        else {
            cout << '1' << endl;
        }
    } // 1 or 4
}