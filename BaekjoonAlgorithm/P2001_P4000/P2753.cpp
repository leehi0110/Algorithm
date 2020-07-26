// Baekjoon 2753
// 문제
// 윤년

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int year;

    cin >> year;

    if(year%4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                cout << '1' << endl;
            }
            else {
                cout << '0' << endl;
            }
        } // 100의 배수인 경우
        else {
            cout << '1' << endl;
        } // 100의 배수가 아닌경우
    } // 4의 배수인 경우
    else {
        cout << '0' << endl;
    } // 4의 배수가 아닌경우
}