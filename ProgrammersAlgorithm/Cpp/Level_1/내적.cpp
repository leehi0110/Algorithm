// ProblemNumber || ProblemName : 내적
// 문제
// 두 배열의 내적을 반환하시오

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    for(int i=0;i<a.size();i++) {
        answer += a[i]*b[i];
    }
    
    return answer;
}
