// Baekjoon 10808
// 문제
// 알파벳 개수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    vector <int> vec(26,0);

    cin >> s;

    for(int i=0;i<s.length();i++){
        vec[s[i]-97]++;
    }

    for(int i : vec){
        cout << i << " ";
    }
}