// ProblemNumber || ProblemName : 자연수 뒤집어 배열로 만들기
// 문제
// 자연수를 뒤집어 각 자리수를 배열로 만드시오

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n>0) {
        answer.push_back(n%10);
        n /= 10;
    }
    
    return answer;
}
