// ProblemNumber || ProblemName : 제일 작은수 제거하기
// 문제
// 배열에서 제일 작은수를 제거하고 반환하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    arr.erase(min_element(arr.begin(),arr.end()));
    
    if(arr.size() == 0) arr.push_back(-1);
    
    return arr;
    
}
