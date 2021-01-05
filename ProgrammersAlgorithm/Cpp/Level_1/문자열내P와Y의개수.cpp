// ProblemNumber || ProblemName : 문자열내 P와 Y의 개수
// 문제
// 문자열 내 P와 Y의 개수가 같은지 반환하시오

#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCnt =0 , yCnt = 0;

    for(int i=0;i<s.length();i++) {
        if(s[i] == 'p' || s[i] == 'P') pCnt++;
        else if(s[i] == 'y' || s[i] == 'Y') yCnt++;
    }

    return pCnt == yCnt;
}
