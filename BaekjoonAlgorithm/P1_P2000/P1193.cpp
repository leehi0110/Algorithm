// Baekjoon 1193
// 문제
// 분수찾기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    long int x;
    int cnt = 0;
    long int sum_cnt = 0;
    long int a,b;

    cin >> x;

    while(sum_cnt < x){
        cnt++;
        sum_cnt += cnt;
    }

    if(cnt%2 == 0) {
        a = cnt - (sum_cnt-x);
        b = 1 + (sum_cnt-x);
    } // 짝수
    else {
        a = 1 + (sum_cnt-x);
        b = cnt - (sum_cnt-x);
    } // 홀수

    cout << a << "/" << b << endl;

}