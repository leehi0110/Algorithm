// ProblemNumber || ProblemName : 이상한 문자 만들기
// 문제
// 단어를 기준으로 짝수번째 문자는 대문자, 홀수번째 문자는 소문자로 바꾸시오

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 1; // 홀수
    
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ') index = 1;
        else {
            if(index) {
                s[i] = toupper(s[i]);
                index = 0;
            } // 짝수
            else {
                s[i] = tolower(s[i]);
                index = 1;
            } // 홀수
        }
    }
    
    return s;
}
