// ProblemNumber || ProblemName : x간격 만큼의 n개의 수
// 문제
// x간격만큼의 n개의 배열을 구하라

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for(int i=1;i<=n;i++) {
        answer.push_back(x*i);
    }
    
    return answer;
}
