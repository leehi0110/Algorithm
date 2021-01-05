// ProblemNumber || ProblemName : 짝수와 홀수
// 문제
// 짝수인지 홀수인지 구분하시오

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    
    return (num+2)%2 == 0 ? "Even" : "Odd";
}
