// ProblemNumber || ProblemName : 정수 내림차순으로 배치하기
// 문제
// 정수를 내림차순으로 정렬하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    
    string s = to_string(n);
    sort(s.begin(),s.end(),greater<char>());
    
    return stoll(s);
}
