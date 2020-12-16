// ProblemNumber || ProblemName : 두 정수 사이의 합
// 문제
// 두 정수 사이의 모든 정수의 합을 구하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a > b) swap(a,b);
    
    for(int i=a;i<=b;i++){
        answer += i;
    }
    
    return answer;
}