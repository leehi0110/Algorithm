// Baekjoon 5598
// 문제
// 문자열 처리
// 카이사르 암호

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin >> s;

    for(int i=0;i<s.length();i++){
        if(s[i] - 3 < 65){
            s[i] = s[i] -3 + 26;
        }
        else {
            s[i] -= 3;
        }
    }

    cout << s << endl;
}