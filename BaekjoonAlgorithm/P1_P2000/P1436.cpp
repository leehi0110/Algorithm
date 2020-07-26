// Baekjoon 1436
// 문제
// 영화감독 숌

#include <iostream>
#include <vector>
#include <string>

bool is_six(int number);
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int counter=0;
    int n;
    int test_num = 666;

    cin >> n;

    while(counter != n){
        if(is_six(test_num)){
            counter ++;
        }

        test_num ++;
    }

    cout << test_num-1;
}

bool is_six(int number){
    int cnt = 0;

    while(number > 10){
        
        if(number%10 == 6){
            cnt ++;
            number /= 10;
            if(cnt == 3) return true;
        }
        else {
            cnt = 0;
            number /= 10;
        }
    }

    if(number == 6) cnt ++;
    else cnt = 0;

    if(cnt == 3) return true;
    else return false;
}