#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long sqrtVal;

    sqrtVal = sqrt(n);

    pow(sqrtVal,2) == n ? answer = pow(sqrtVal+1,2) : answer = -1;

    return answer;
} // 처음 풀이

// => 수정한 풀이

// long long solution(long long n) {
//   long long answer = sqrt(n);

//   return pow(answer,2) == n ? pow(answer+1,2) : -1 ;
// }