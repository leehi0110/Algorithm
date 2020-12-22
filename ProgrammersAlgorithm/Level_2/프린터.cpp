// ProblemNumber || ProblemName : 프린터
// 문제
// 내 문서가 몇번째로 출력되는지 구하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while(1) {
        int front = priorities.front();
        int max = *max_element(priorities.begin(),priorities.end());
        
        if(front >= max) {
            if(location == 0) {
                answer++;
                break;   
            }
            else {
                priorities.erase(priorities.begin());
                location --;
                answer++;
            }
        }
        else {
            priorities.erase(priorities.begin());
            priorities.push_back(front);
            location--;
        }
        
        if(location < 0) location = priorities.size()-1;
    }
    
    return answer;
}
