// Baekjoon 5585
// 문제
// 거스름돈

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int money;
    int coin_cnt = 0;
    vector <int> coin = {500,100,50,10,5,1};
    vector <int>::iterator iter = coin.begin();

    cin >> money;
    money = 1000 - money;

    while(money != 0){
        if(money/(*iter) != 0){
            coin_cnt += money/(*iter);
            money %= *iter;
        }
        else iter ++;
    }

    cout << coin_cnt << endl;

}