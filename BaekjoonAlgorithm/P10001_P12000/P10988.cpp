// Baekjoon 10988
// 문제
// 문자열 처리
// 팰린드롬인지 확인하기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string target;
    
    cin >> target;
    
    int i = 0;
    int j = target.length()-1;

    while(i != target.length()){
        if(target[i] != target[j]) {
            cout << "0" << endl;
            return 0;
        }
        else {
            i ++ , j--;
        }
    }
    cout << "1" << endl;
}