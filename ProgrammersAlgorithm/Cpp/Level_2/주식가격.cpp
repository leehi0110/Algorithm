// ProblemNumber || ProblemName : 주식가격
// 문제
// 주식 가격이 떨어지지 않은 시간을 구하라

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int i,j;
    
    for(i=0;i<prices.size();i++) {
        for(j=i;j<prices.size();j++) {
            if(prices[i] > prices[j]) {
                answer.push_back(j-i);
                break;
            }
            if(j == prices.size()-1) answer.push_back(j-i);
        }
    }
    
    return answer;
}
