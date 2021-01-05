// ProblemNumber || ProblemName : 정수 제곱근 판별
// 문제
// 정수 제곱근이 있을 경우 1을 더해 제곱한 값을 반환하시오

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    
    return powl(sqrt(n),2) == n ? powl(sqrt(n)+1,2) : -1;
    
}