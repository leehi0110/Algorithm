#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt_p =0, cnt_y=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='p'||s[i]=='P') cnt_p++;
        else if(s[i]=='y' || s[i] == 'Y') cnt_y++;
        else continue;
    }
    answer = cnt_p == cnt_y ? true : false;

    return answer;
}