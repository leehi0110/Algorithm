// ProblemNumber || ProblemName : 시저 암호
// 문제
// 문자열을 n만큼 밀어낸 새로운 문자열을 반환하시오

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char c : s) {
        if(c == ' ') {
            answer += c;
        }
        else {
            char start = (c >= 'a' && c <= 'z') ? 'a' : 'A';
            answer += (start+(c+n-start)%26);
        }
    }
    
    return answer;
}