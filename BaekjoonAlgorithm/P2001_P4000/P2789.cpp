// Baekjoon 2789
// 문제
// 문자열 처리 
// 유학금지

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;

    for(int i=0;i<str.length();i++){
        if(str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E'){
            str.erase(i,1);
            i--;
        }
    }

    cout << str << endl;
}