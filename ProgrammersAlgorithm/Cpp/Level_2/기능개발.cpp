// ProblemNumber || ProblemName : 기능개발
// 문제
// 배포마다 몇개의 기능이 배포되는지 구하시오

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> need;
    
    for(int i=0;i<progresses.size();i++){
        int share, remainder;
        
        share = (100-progresses[i])/speeds[i];
        remainder = (100-progresses[i])%speeds[i];
        
        remainder == 0 ? need.push_back(share) : need.push_back(share+1);
    }
    
    int max = need[0];
    int cnt = 1;
    
    for(int i=1;i<need.size();i++) {
        if(need[i] <= max) cnt++;
        else {
            answer.push_back(cnt);
            max = need[i];
            cnt = 1;
        }
        
        if(i == need.size()-1) answer.push_back(cnt);
    }
