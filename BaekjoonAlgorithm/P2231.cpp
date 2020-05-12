// Baekjoon 2231
// 문제
// 분해합

#include <iostream>
#include <vector>
#include <string>

int div_num(int creator);
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int result;
    int creator;

    cin >> result;

    for(int i=1;i<result;i++){
        if(div_num(i) == result){
            cout << i;
            return 0;
        }
    }

    cout << 0;
}

int div_num(int creator){
    int sum = 0;

    sum += creator;

    while(creator > 10){
        sum += creator%10;
        creator /= 10;
    }

    return sum+creator;
}