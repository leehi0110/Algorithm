// Baekjoon 10817
// 문제
// 세 수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;

    cin >> a >> b >> c;

    if(a > b){
        if(b > c){
            cout << b << endl;
        }
        else {
            if(a > c){
                cout << c << endl;
            }
            else {
                cout << a << endl;
            }
        }
    }
    else { // a < b
        if(b < c){
            cout << b << endl;
        }
        else {
            if(a > c){
                cout << a << endl;
            }
            else {
                cout << c << endl;
            }
        }
    }
}