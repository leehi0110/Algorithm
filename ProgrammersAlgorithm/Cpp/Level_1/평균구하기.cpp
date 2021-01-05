// ProblemNumber || ProblemName : 평균구하기
// 문제
// 배열의 평균을 구하시오

#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    return accumulate(arr.begin(),arr.end(),0)/(double)arr.size();
}
