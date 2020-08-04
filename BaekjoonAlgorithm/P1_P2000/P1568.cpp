// Baekjoon 1568
// 문제
// 탐색
// 새

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int time = 0;
    int now_number = 1;

    cin >> n;

    while(n){
        if(now_number > n){
            now_number = 1;
        }
        else {
            time ++;
            n -= now_number;
            now_number++;
        }
    }

    cout << time;
}