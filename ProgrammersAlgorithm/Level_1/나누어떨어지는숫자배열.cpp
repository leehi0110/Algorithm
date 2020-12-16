// ProblemNumber || ProblemName : 나누어 떨어지는 숫자 배열
// 문제
// 배열에서 나누어 떨어지는 값만을 새 배열로 만들어 반환하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for(int i : arr) {
        if(i%divisor == 0) {
            answer.push_back(i);
        }
    }
    
    if(!answer.size()) answer.push_back(-1);
    else sort(answer.begin(),answer.end());
    
    return answer;
}
