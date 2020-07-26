// Baekjoon 2884
// 문제
// 알람 시계

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int h , m;

    cin >> h >> m;

    if(m < 45) {
        if(h == 0){
            cout << "23" << ' ' << m+15 << endl;
        }
        else {
            cout << h-1 << ' ' << m+15 << endl;
        }
    } // 분이 모자를 경우
    else {
        cout << h << ' ' << m-45 << endl;
    }
}