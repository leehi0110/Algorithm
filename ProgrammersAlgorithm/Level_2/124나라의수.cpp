// ProblemNumber || ProblemName : 124 나라의 수
// 문제
// 주어진 수를 124 나라의 수로 변환하라

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n != 0) {
        if(n%3 == 0) {
            answer.insert(0,"4");
            n = n/3-1;
        }
        else {
            if(n%3 == 1) answer.insert(0,"1");
            else answer.insert(0,"2");
            
            n /= 3;
        }
    }
    
    return answer;
}