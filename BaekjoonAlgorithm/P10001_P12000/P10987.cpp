// Baekjoon 10987
// 문제
// 문자열
// 모음의 개수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int cnt = 0;

    cin >> s;

    for(int i=0;i<s.length();i++){
        if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u') cnt++;
    }   

    cout << cnt;
}