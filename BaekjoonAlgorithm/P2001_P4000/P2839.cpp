// Baekjoon 2839 
// 문제 
// 설탕 배달

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool check_weight(int bigCnt,int total);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int total;
    int bigCnt;

    cin >> total;
    bigCnt = total/5;

    while(1){
        if(check_weight(bigCnt,total)){
            cout << bigCnt + ((total-(bigCnt*5))/3) << endl;
            break;
        }
        else {
            bigCnt --;
        }

        if(bigCnt == - 1){
            cout << -1 << endl;
            break;
        }
    }
}

bool check_weight(int bigCnt,int total){
    total = total-(bigCnt*5);

    if(total%3 == 0){
        return true;
    }
    else return false;
}
