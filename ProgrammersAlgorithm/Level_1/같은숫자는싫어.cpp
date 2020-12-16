// ProblemNumber || ProblemName : 같은 숫자는 싫어
// 문제
// 배열에서 연속되는 중복 숫자를 제거한 배열을 반환하시오

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr[0]);
    
    for(int i=1;i<arr.size();i++) {
        if(arr[i] == answer.back()) continue;
        else answer.push_back(arr[i]);
    }

    return answer;
}