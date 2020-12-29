// ProblemNumber || ProblemName : H-Index
// 문제
// 논문의 H-Index를 구하라

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    sort(citations.begin(),citations.end(),greater<int>());
    
    for(int i=0;i<citations.size();i++) {
        if(i+1 > citations[i]) return i;
    }
}