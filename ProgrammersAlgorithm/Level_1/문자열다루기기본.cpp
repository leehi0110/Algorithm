// ProblemNumber || ProblemName : 문자열 다루기 기본
// 문제
// 문자열이 숫자로만 이루어졌는지 확인하시오

#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {

    for(int i=0;i<s.length();i++) {
        if(!isdigit(s[i])) return false;
    }
    
    return s.length() == 4 || s.length() == 6 ? true : false;
}
