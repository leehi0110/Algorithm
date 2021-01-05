// ProblemNumber || ProblemName : 하샤드 수
// 문제
// 매개변수가 하샤드 수인지 확인하시오

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    
    for(char c: to_string(x)) {
        sum += c -'0';
    }
    
    return x%sum == 0 ? true : false;
}
