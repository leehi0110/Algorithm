// ProblemNumber || ProblemName : 자릿수 더하기
// 문제
// 숫자의 각 자릿수를 더하라

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(n > 9) {
        answer += n%10;
        n /= 10;
    }

    return answer + n;
}
