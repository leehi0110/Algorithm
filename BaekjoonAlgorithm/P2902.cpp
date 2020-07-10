// Baekjoon 2902
// 문제
// KMP는 왜 KMP일까?

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string result = "";
    string tmp;

    cin >> tmp;

    result += tmp[0];
    for(int i=1;i<tmp.length();i++){
        if(tmp[i] == '-'){
            result += tmp[i+1];
        }
    }

    cout << result << endl;
}