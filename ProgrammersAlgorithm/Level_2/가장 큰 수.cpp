// ProblemNumber || ProblemName : 가장 큰 수
// 문제
// 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(int a, int b);

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(),numbers.end(),comp);

    for(int i=0;i<numbers.size();i++) {
        answer += to_string(numbers[i]);
    }
    
    if(answer[0] == '0') return "0";
    else return answer;
}

bool comp(int a, int b) {
  string stringA, stringB;

  stringA = to_string(a);
  stringB = to_string(b);

  return stringA + stringB > stringB + stringA; 
}