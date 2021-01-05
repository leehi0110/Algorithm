// ProblemNumber || ProblemName : 약수의 합
// 문제
// n의 모든 약수의 합을 구하시오

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++) {
        if(n%i == 0) answer += i;
    }
    
    return answer;
}
